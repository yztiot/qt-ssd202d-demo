#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
class SerialThread:public QObject
{
    Q_OBJECT
public:
    SerialThread(QSerialPort  *serialPort);

signals:
    void sendSerialData(QString str);

public slots:
    void readData();
    void starThread();

private:
    QSerialPort *m_serial;
    QString m_strData;
    QString strWrite = "";
    QString m_strHead;
};

#endif // SERIALTHREAD_H
