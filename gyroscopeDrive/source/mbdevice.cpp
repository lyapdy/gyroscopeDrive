#include "mbdevice.h"

MbDevice::MbDevice(QObject *parent) : QObject(parent)
{
}

int MbDevice::connect(QString address)
{
    if (mb.connected) return 0;
    m_error = mb.open(address);
    if (m_error) { disconnect(m_error);  }
    return m_error;
}

void MbDevice::disconnect(int error)
{
    if (mb.connected) {
        mb.close();
        emit connectionChanged();
    }
    if (error) emit onError(this, mb.errorMessage(static_cast<ModbusTCP::ModbusError>(error)));
}

qreal MbDevice::read(ushort addr, int dataType, int format, qreal scale)
{
    ushort buf[4];
    ushort datalen;
    bool isSigned = true;
    switch(dataType) {
        case MbDevice::INT16:  datalen = 1; break;
        case MbDevice::UINT16: datalen = 1; isSigned = false; break;
        case MbDevice::INT32:  datalen = 2; break;
        case MbDevice::FLOAT:  datalen = 2; break;
        case MbDevice::DOUBLE: datalen = 4; break;
        default: return 0;
    }
    m_error = int(mb.read(addr, buf, datalen));
    if (m_error) { disconnect(m_error); return 0; }
    qreal value;
    if (dataType == MbDevice::DOUBLE) {
        udatal data = {0};
        for(int i = 0; i < 4; i++) {
            data.i <<= 16;
            data.i |= quint64(buf[i]);
        }
        value = data.f;
    }
    else {
        udata data;
        if (datalen == 1) data.i = isSigned ? long(short(buf[0])) : long(buf[0]);
        else if (!m_type) data.i = (long(buf[1]) << 16) | long(buf[0]);
        else data.i = (long(buf[0]) << 16) | long(buf[1]);
        if (dataType == MbDevice::FLOAT) value = double(data.f);
        else if (dataType == MbDevice::INT32) value = double(data.i) / (1L << format);
        else value = double(data.i);
    }
    return (value / scale);
}

void MbDevice::write(ushort addr, qreal value, int dataType, int format, qreal scale)
{
    value = value * scale;
    ushort buf[4];
    ushort datalen;
    bool isSigned = true;
    switch(dataType) {
        case MbDevice::INT16:  datalen = 1; break;
        case MbDevice::UINT16: datalen = 1; isSigned = false; break;
        case MbDevice::INT32:  datalen = 2; break;
        case MbDevice::FLOAT:  datalen = 2; break;
        case MbDevice::DOUBLE: datalen = 4; break;
        default: return;
    }
    if (dataType == MbDevice::DOUBLE) {
        udatal data;
        data.f = value;
        quint64 udata = data.i;
        ushort *bufptr = &buf[3];
        for(int i = 0; i < 4; i++) {
            *bufptr = ushort(udata);
            udata >>= 16;
            bufptr--;
        }
    }
    else {
        udata data;
        if (dataType == MbDevice::FLOAT) data.f = float(value);
        else if (dataType == MbDevice::INT32) data.i = long(value * (1L << format));
        else if (!isSigned) data.i = long(ulong(value));
        else data.i = long(value);
        if (datalen == 1) buf[0] = ushort(data.i);
        else if (!m_type) { buf[0] = ushort(data.i); buf[1] = ushort(data.i >> 16); }
        else { buf[1] = ushort(data.i); buf[0] = ushort(data.i >> 16); }
    }
    m_error = int(mb.write(addr, buf, datalen));
    if (m_error) disconnect(m_error);
}

void MbDevice::driveEnable()
{
    if (!m_type) {
        write(0xA1, 1, MbDevice::INT16);
        write(0xC1, 1, MbDevice::INT16);
    }
    else {
        write(232, 1, MbDevice::INT32);
        write(254, 1, MbDevice::INT32);
    }
}

void MbDevice::driveDisable()
{
    if (!m_type) {
        write(0xA1, 0, MbDevice::INT16);
        write(0xC1, 0, MbDevice::INT16);
    }
    else {
        write(232, 0, MbDevice::INT32);
        write(236, 1, MbDevice::INT32);
    }
}

void MbDevice::resetPosition()
{
    if (!m_type) write(0x94, 5, MbDevice::INT16);
    else write(3130, 1, MbDevice::INT32);
}

qreal MbDevice::readPosition()
{
    qreal value;
    if (!m_type) value = read(0x1D, MbDevice::INT32);
    #if 0
    else value = read(2072, MbDevice::INT32);
    #else
    else value = read(588, MbDevice::DOUBLE);
    #endif
    return value;
}

void MbDevice::setPosition(qreal value)
{
    if (!m_type) write(0xC4, value, MbDevice::INT32);
    #if 0
    else write(3038, value, MbDevice::INT32);
    #else
    else write(3054, value, MbDevice::DOUBLE);
    #endif
    emit positionChanged(this, value);
}

