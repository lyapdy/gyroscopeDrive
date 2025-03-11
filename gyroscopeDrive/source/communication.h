#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include "mbdevice.h"
#include <QWidget>
class COMMUNICATION : public QObject
{
    Q_OBJECT
public:
    COMMUNICATION(QWidget *parent = nullptr);
    Q_INVOKABLE int btnDevConnect(QString ipAddress,int number);
    Q_INVOKABLE void btnDevDisconnect(int number);
    Q_INVOKABLE bool isConnected(int number);
    Q_INVOKABLE void btnDevEnable(int number);
    Q_INVOKABLE void btnDevEnable2(int number);
    Q_INVOKABLE void btnDevDisable(int number);
    Q_INVOKABLE void btnDev1SetPos(int pos);
    Q_INVOKABLE void btnDev2SetPos(int pos);
    Q_INVOKABLE int readPosition(int deviceNumber);


    MbDevice dev1;
    MbDevice dev2;

private:





};

#endif // COMMUNICATION_H
