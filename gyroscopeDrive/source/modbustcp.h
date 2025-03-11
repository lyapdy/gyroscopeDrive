#ifndef MODBUSTCP_H
#define MODBUSTCP_H

#include <QObject>
#include <QTcpSocket>

class ModbusTCP : public QObject
{
    Q_OBJECT
public:
    enum ModbusFunc {
        MB_READ_HOLDING_REGS   = 0x03,
        MB_WRITE_MULTIPLE_REGS = 0x10
    };
    Q_ENUMS(ModbusFunc)
    enum ModbusError {
        ERR_SUCCESS                  = 0x00,
        ERR_ILLEGAL_FUNCTION         = 0x01,
        ERR_ILLEGAL_DATA_ADDRESS     = 0x02,
        ERR_ILLEGAL_DATA_VALUE       = 0x03,
        ERR_SLAVE_DEVICE_FAILURE     = 0x04,
        ERR_ACKNOWLEDGE              = 0x05,
        ERR_SLAVE_DEVICE_BUSY        = 0x06,
        ERR_NEGATIVE_ACKNOWLEDGE     = 0x07,
        ERR_MEMORY_PARITY_ERROR      = 0x08,
        ERR_NO_CONNECTION            = 0x09,
        ERR_GW_PATH_UNAVAILABLE      = 0x0A,
        ERR_GW_TARGET_FAILED_TO_RESP = 0x0B,
        ERR_CANT_OPEN_PORT           = 0x10,
        ERR_BAD_PARAMS               = 0x11,
        ERR_INIT_FAILED              = 0x12,
        ERR_NOT_RESPOND              = 0x13,
        ERR_FUNC_NOT_SUPPORTED       = 0x14,
        ERR_BAD_DATA_BUFF            = 0x15,
        ERR_CRC_FAILED               = 0x16,
        ERR_BAD_RESPONSE_LENGTH      = 0x17,
        ERR_BAD_RESPONSE_FUNC        = 0x18,
        ERR_BAD_RESPONSE_ADDRESS     = 0x19,
        ERR_BAD_RESPONSE_COUNT       = 0x1A,
        ERR_BAD_RESPONSE_VALUE       = 0x1B,
        ERR_BAD_DATA_COUNT           = 0x1C,
        ERR_BAD_DATA_VALUE           = 0x1D,
        ERR_BAD_EXCERTION_RESPONSE   = 0x1E,
        ERR_UNDEFINED_PROTOCOL       = 0x1F,
        ERR_SEARCHING                = 0x23,
        ERR_NO_SUCH_DEVICE           = 0x24,
        ERR_CONNECT_ABORT            = 0x25
    };
    Q_ENUMS(ModbusError)
    explicit ModbusTCP(QObject *parent = nullptr);
private:
    QTcpSocket *socket;
    QString m_address;
    static void wordPack(uchar *buf, ushort data);
    static ushort wordUnpack(uchar *buf);
    static void dataPack(uchar *buf, ushort *data, ushort count);
    static void dataUnpack(uchar *buf, ushort *data, ushort count);
    ModbusTCP::ModbusError reconnect();
    ModbusTCP::ModbusError invoke(uchar func, ushort addr, ushort *data, ushort count);
    ModbusTCP::ModbusError internal_invoke(uchar func, ushort addr, ushort *data, ushort count);
public:
    bool connected;
    ModbusError open(QString ipaddr);
    void close();
    ModbusError read(ushort addr, ushort *data, ushort count);
    ModbusError write(ushort addr, ushort *data, ushort count);
    QString errorMessage(ModbusError error);
};

#endif // MODBUSTCP_H
