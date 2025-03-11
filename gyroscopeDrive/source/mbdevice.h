#ifndef MBDEVICE_H
#define MBDEVICE_H

#include <QObject>
#include "modbustcp.h"

struct udata { union { long i; float f; }; };
struct udatal { union { quint64 i; double f; }; };

class MbDevice : public QObject
{
    Q_OBJECT
public:
    explicit MbDevice(QObject *parent = nullptr);
    enum DataType { INT16, UINT16, INT32, FLOAT, DOUBLE };
    QString header() { return m_header; }
    void setHeader(QString value) { m_header = value; }
    void setType(int value) { m_type = value; }
    int error() { return m_error; }
    bool connected() { return mb.connected; }
    int connect(QString address);
    void disconnect(int error = 0);
    qreal read(ushort addr, int dataType, int format = 0, qreal scale = 1);
    void write(ushort addr, qreal value, int dataType, int format = 0, qreal scale = 1);
    void driveEnable();
    void driveDisable();
    void resetPosition();
    qreal readPosition();
    void setPosition(qreal value);
signals:
    void onError(MbDevice *sender, QString error);
    void connectionChanged();
    void positionChanged(MbDevice *sender, qreal position);
private:
    ModbusTCP mb;
    QString m_header;
    int m_type=1;
    int m_error;
};

#endif // MBDEVICE_H
