#include "communication.h"

COMMUNICATION::COMMUNICATION(QWidget *parent) : QObject(parent)
{
    // implementation of the constructor
}

int COMMUNICATION::btnDevConnect(QString ipAddress,int number)
{

    qDebug()<<ipAddress;
    //int err = m_tcp.open(ipAddress);
    if (number==1){
        int err = dev1.connect(ipAddress);
        return err;
    }
    else{
        int err = dev2.connect(ipAddress);
        return err;
    }
}

void COMMUNICATION::btnDevDisconnect(int number)
{
    if (number==1){
        dev1.disconnect();
    }
    else{
        dev2.disconnect();
    }
}

bool COMMUNICATION::isConnected(int number)
{
    if (number==1){
        if (dev1.connected()) return true;
        else{return false;}
    }
    else{
        if (dev2.connected()) return true;
        else{return false;}
    }
}

void COMMUNICATION::btnDevEnable(int number)
{
    if (number==1){
        dev1.setPosition(0);
        dev1.resetPosition();
        dev1.driveEnable();
        qDebug()<<"qwe1";
    }
    else{
        dev2.setPosition(0);
        dev2.resetPosition();
        dev2.driveEnable();
    }
}
void COMMUNICATION::btnDevEnable2(int number)
{
    if (number==1){
        dev1.driveEnable();
        qDebug()<<"qwe1";
    }
    else{
        dev2.driveEnable();
    }
}
void COMMUNICATION::btnDevDisable(int number)
{
    if (number==1){
        dev1.driveDisable();
    }
    else{
        dev2.driveDisable();
    }
}

void COMMUNICATION::btnDev1SetPos(int pos)
{
    dev1.setPosition(pos);
}

void COMMUNICATION::btnDev2SetPos(int pos)
{
    dev2.setPosition(pos);
}

int COMMUNICATION::readPosition(int deviceNumber)
{
    if (deviceNumber==1){
        return dev1.readPosition();
    }
    if (deviceNumber==2){
        return dev2.readPosition();
    }
}

