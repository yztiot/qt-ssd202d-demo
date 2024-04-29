#ifndef INTERNETSETTING_H
#define INTERNETSETTING_H
#include <QDebug>
#include <QObject>
#include <QNetworkInterface>
#include <QNetworkConfigurationManager>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QThread>
#include <QTimer>
#include <QEventLoop>

class InternetSetting:public QObject
{
    Q_OBJECT
public:
    InternetSetting();
    ~InternetSetting();

    /*获取linux中网络配置信息*/
    Q_INVOKABLE QString ifconfig();
    /*返回ping结果*/
    Q_INVOKABLE QString getPingStr(){return m_StrPing;}
    /*ping 百度*/
    Q_INVOKABLE void ping();
    /*关闭ping进程*/
    Q_INVOKABLE void closePing();
    /*关闭ifconfig进程*/
    Q_INVOKABLE void closeIfconfig();

signals:
    void pingSig();


public slots:
    void getPing();
    void startTimer();


private:
        QTimer *m_pingTimer = nullptr;
        QString m_StrPing = "";
        QProcess *m_pingProcess;
        QProcess *m_ifconfigProcess;
};

#endif // INTERNETSETTING_H
