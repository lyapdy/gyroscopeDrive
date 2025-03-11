#include "modbustcp.h"
#include <QNetworkProxy>
#include <QThread>

#define TCP_SLAVE           1
#define TCP_PORT            502
#define TCP_CONN_TIMEOUT    1000
#define TCP_READ_TIMEOUT    500
#define TCP_WRITE_TIMEOUT   200
#define TCP_ACK_TIMEOUT     20
#define TCP_RETRY_COUNT     1
#define TCP_RETRY_TIMEOUT   10
#define TCP_BUSY_TIMEOUT    100

ModbusTCP::ModbusTCP(QObject *parent) :
    QObject(parent), socket(nullptr), connected(false)
{
}

ModbusTCP::ModbusError ModbusTCP::open(QString ipaddr)
{
    m_address = ipaddr;
    for(int i = 0; i < TCP_RETRY_COUNT; i++) {
        socket = new QTcpSocket;
        socket->setProxy(QNetworkProxy::NoProxy);
        socket->connectToHost(m_address, TCP_PORT, QIODevice::ReadWrite, QAbstractSocket::IPv4Protocol);
        if (!socket->waitForConnected(TCP_CONN_TIMEOUT)) {
            close();
            QThread::currentThread()->msleep(TCP_RETRY_TIMEOUT);
            continue;
        }
        connected = true;
        return ERR_SUCCESS;
    }
    return ERR_CANT_OPEN_PORT;
}

void ModbusTCP::close()
{
    connected = false;
    if (socket) { socket->abort(); delete socket; socket = nullptr; }
}

ModbusTCP::ModbusError ModbusTCP::read(ushort addr, ushort *data, ushort count)
{
	return invoke(MB_READ_HOLDING_REGS, addr, data, count);
}

ModbusTCP::ModbusError ModbusTCP::write(ushort addr, ushort *data, ushort count)
{
	return invoke(MB_WRITE_MULTIPLE_REGS, addr, data, count);
}

ModbusTCP::ModbusError ModbusTCP::reconnect()
{
    close();
    return open(m_address);
}

ModbusTCP::ModbusError ModbusTCP::invoke(uchar func, ushort addr, ushort *data, ushort count)
{
    ModbusTCP::ModbusError error = ERR_SUCCESS;
    int busy_counter = TCP_BUSY_TIMEOUT;
    for(int i = 0; i < TCP_RETRY_COUNT; ) {
        error = internal_invoke(func, addr, data, count);
        if (!error) break;
        if (error == ERR_ACKNOWLEDGE) { QThread::currentThread()->msleep(TCP_ACK_TIMEOUT); continue; }
        if (error == ERR_SLAVE_DEVICE_BUSY) { if (--busy_counter > 0) continue; else break;}
        if ((error != ERR_NOT_RESPOND) && (error != ERR_CRC_FAILED) && (error != ERR_BAD_RESPONSE_LENGTH) && (error != ERR_BAD_EXCERTION_RESPONSE)) break;
        QThread::currentThread()->msleep(TCP_RETRY_TIMEOUT);
        i++;
    }
    return error;
}

ModbusTCP::ModbusError ModbusTCP::internal_invoke(uchar func, ushort addr, ushort *data, ushort count)
{
    if (!socket || (socket->state() != QAbstractSocket::ConnectedState))
        return ERR_CANT_OPEN_PORT;

    uchar buf[270];
    wordPack(&buf[0], 0); // transIdent
    wordPack(&buf[2], 0); // protocolIdent
    buf[6] = TCP_SLAVE;

	int len;
	buf[7] = func;
    switch(func)
    {
        case MB_READ_HOLDING_REGS:
            if (!count) return ERR_BAD_DATA_COUNT;
            wordPack(&buf[8], addr);
            wordPack(&buf[10], count);
            len = 5;
        break;
        case MB_WRITE_MULTIPLE_REGS:
            if (!count) return ERR_BAD_DATA_COUNT;
            wordPack(&buf[8], addr);
            wordPack(&buf[10], count);
            buf[12] = static_cast<uchar>(count * 2);
            dataPack(&buf[13], data, count);
            len = buf[12] + 6;
        break;
        default:
            return ERR_FUNC_NOT_SUPPORTED;
    }
	
    wordPack(&buf[4], static_cast<ushort>(len + 1));
    len += 7;

    socket->write(reinterpret_cast<const char *>(buf), static_cast<qint64>(len));
    if (!socket->waitForBytesWritten(TCP_WRITE_TIMEOUT)) return ERR_NOT_RESPOND;
    if (!socket->waitForReadyRead(TCP_READ_TIMEOUT)) return ERR_NOT_RESPOND;

    len = static_cast<int>(socket->read(reinterpret_cast<char *>(buf), static_cast<qint64>(sizeof(buf))));
    if (len < 7) return ERR_NOT_RESPOND;
    if (wordUnpack(&buf[0]) || wordUnpack(&buf[2])) return ERR_NOT_RESPOND;
    if (wordUnpack(&buf[4]) != (len - 6)) return ERR_NOT_RESPOND;
    if (buf[6] != TCP_SLAVE) return ERR_BAD_RESPONSE_ADDRESS;
    len -= 7;

    if (buf[7] & 0x80) {
        if ((buf[7] & ~0x80) != func) return ERR_BAD_EXCERTION_RESPONSE;
        return static_cast<ModbusTCP::ModbusError>(buf[8]);
    }
    if (buf[7] != func) return ERR_BAD_RESPONSE_FUNC;
    switch(func)
    {
        case MB_READ_HOLDING_REGS:
            if (buf[8] != static_cast<uchar>(count * 2)) return ERR_BAD_RESPONSE_COUNT;
            if (len != static_cast<int>(count * 2 + 2)) return ERR_BAD_RESPONSE_LENGTH;
            dataUnpack(&buf[9], data, count);
        break;
        case MB_WRITE_MULTIPLE_REGS:
            if (len != 5) return ERR_BAD_RESPONSE_LENGTH;
            if (wordUnpack(&buf[8]) != addr) return ERR_BAD_RESPONSE_ADDRESS;
            if (wordUnpack(&buf[10]) != count) return ERR_BAD_RESPONSE_COUNT;
        break;
    }
	
    return ERR_SUCCESS;
}

void ModbusTCP::wordPack(uchar *buf, ushort data)
{
    buf[0] = static_cast<uchar>(data >> 8);
    buf[1] = static_cast<uchar>(data & 0xFF);
}

ushort ModbusTCP::wordUnpack(uchar *buf)
{
    uint temp = (static_cast<uint>(buf[0]) << 8) | static_cast<uint>(buf[1]);
    return static_cast<ushort>(temp);
}

void ModbusTCP::dataPack(uchar *buf, ushort *data, ushort count)
{
    do {
        *buf++ = static_cast<uchar>(*data >> 8);
        *buf++ = static_cast<uchar>(*data & 0xFF);
        data++;
    } while(--count);
}

void ModbusTCP::dataUnpack(uchar *buf, ushort *data, ushort count)
{
    uint temp;
    do {
        temp = (static_cast<uint>(buf[0]) << 8) | static_cast<uint>(buf[1]);
        *data++ = static_cast<ushort>(temp);
        buf += 2;
    } while(--count);
}

QString ModbusTCP::errorMessage(ModbusError error)
{
    QString msg;
    switch(error)
    {
        case ERR_ILLEGAL_FUNCTION:         msg = "недопустимая функция в запросе"; break;
        case ERR_ILLEGAL_DATA_ADDRESS:     msg = "недопустимый адрес в запросе"; break;
        case ERR_ILLEGAL_DATA_VALUE:       msg = "недопустимое значение данных в запросе"; break;
        case ERR_SLAVE_DEVICE_FAILURE:     msg = "сбой подчиненного устройства"; break;
        case ERR_ACKNOWLEDGE:              msg = "подтверждение"; break;
        case ERR_SLAVE_DEVICE_BUSY:        msg = "устройство занято"; break;
        case ERR_NEGATIVE_ACKNOWLEDGE:     msg = "отрицательное подтверждение"; break;
        case ERR_MEMORY_PARITY_ERROR:      msg = "ошибка равенства памяти"; break;
        case ERR_NO_CONNECTION:            msg = "нет связи"; break;
        case ERR_CANT_OPEN_PORT:           msg = "невозможно создать подключение"; break;
        case ERR_BAD_PARAMS:               msg = "недопустимые параметры подключения"; break;
        case ERR_INIT_FAILED:              msg = "сбой инициализации подключения"; break;
        case ERR_NOT_RESPOND:              msg = "устройство не отвечает"; break;
        case ERR_FUNC_NOT_SUPPORTED:       msg = "функция не поддерживается"; break;
        case ERR_BAD_DATA_BUFF:            msg = "недопустимый буфер данных"; break;
        case ERR_CRC_FAILED:               msg = "ошибка CRC"; break;
        case ERR_BAD_RESPONSE_LENGTH:      msg = "неверная длина кадра в ответе"; break;
        case ERR_BAD_RESPONSE_FUNC:        msg = "неверная функция в ответе"; break;
        case ERR_BAD_RESPONSE_ADDRESS:     msg = "неверный адрес в ответе"; break;
        case ERR_BAD_RESPONSE_COUNT:       msg = "неверное количество данных в ответе"; break;
        case ERR_BAD_RESPONSE_VALUE:       msg = "неверное значение данных в ответе"; break;
        case ERR_BAD_DATA_COUNT:           msg = "неверное количество данных"; break;
        case ERR_BAD_DATA_VALUE:           msg = "неверное значение данных"; break;
        case ERR_BAD_EXCERTION_RESPONSE:   msg = "неверный кадр исключения"; break;
        case ERR_UNDEFINED_PROTOCOL:       msg = "недопустий протокол обмена"; break;
        default: msg = "неизвестная ошибка"; break;
    }
    return msg;
}
