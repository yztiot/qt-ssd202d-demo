#ifndef SERIALFUNCTION_H
#define SERIALFUNCTION_H
#include <QtSerialPort/QtSerialPort>
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QFuture>
#include <QtConcurrent>
#include <QModbusReply>
#include <QtSerialPort/QSerialPort>
#include <QThreadPool>
#include <QThread>
#include <serialthread.h>
#include <QEventLoop>

class SerialFunction : public QObject
{
    Q_OBJECT
public:
    SerialFunction();
    void init();

    void checkSerialPort();

    /*打开串口*/
    Q_INVOKABLE void runOpenSerial(QString raud, QString bit, QString check, QString stop);

    /*打开串口*/
 //   Q_INVOKABLE void openSerial(QString raud, QString bit, QString check, QString stop);
    /*关闭串口*/
    Q_INVOKABLE void closeSerial();
    /*往串口写数据*/
    Q_INVOKABLE void writeSerialSig(QString data);
    /*设置波特率*/
    void setBaud(QString baudModel);
    /*设置数据位*/
    void setBit(QString bitModel);
    /*设置校验位*/
    void setCheck(QString checkModel);
    /*设置停止位*/
    void setStop(QString stopModel);

signals:
    void serialDataSig(QString);
    void startSig();
    void writeSig(QString data);
    void openSerialFail(QString info);
    void openSerialSuccessful(QString serialName);
    void tipSig(QString tip);

public slots:
    /*子线程读取串口返回的数据*/
    void readData(QString data);
    void openSerial(QString raud, QString bit, QString check, QString stop);


private:
    QSerialPort  *m_port;
    QString      m_portName;
    QThread      *m_thread;

    SerialThread *m_serialThread;
    /*m_serialModel 1:485   2:232*/
    int          m_serialModel;


    int m_add = 0; //测试用

};

#endif // SERIALFUNCTION_H
