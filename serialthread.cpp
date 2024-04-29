#include "serialthread.h"

SerialThread::SerialThread(QSerialPort  *serialPort)
{
    m_strHead = "返回数据：";
    m_serial = serialPort;
}


void SerialThread::readData(){
    m_strData.clear();
    QString data = "";
    data =  m_serial->readAll();
    m_strData = m_strHead + data;
    emit sendSerialData(m_strData);
}

void SerialThread::starThread(){
    connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
}


