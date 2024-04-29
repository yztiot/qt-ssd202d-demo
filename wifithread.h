#ifndef WIFITHREAD_H
#define WIFITHREAD_H
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QVector>
#include <QMap>
#include <QString>
#include <QtGlobal>
#include <stdio.h>

extern "C"{
   #include "./include/WIFISDK.h"
   #include "./include/mi_common_datatype.h"
   #include "./include/mi_wlan.h"
   #include "./include/mi_wlan_datatype.h"
}

class WiFiThread: public QObject
{
    Q_OBJECT
public:

    explicit WiFiThread();
    ~WiFiThread();

    void connectWiFi(QString wifiName, QString passWord);

    void wifiStatus();

signals:
    void wifiNameSig(QStringList name);
    void wifiConnectSuccessfulSig(QString name);
    void disConnectCurrentWiFiSig();
    void closeWiFiThreadSig();


public slots:
    /*搜索wifi，打开wifi进行初始化*/
    void createWifiFile();
    void onConnectWiFiSig(QString name,QString password);
    void onDisConnectWiFiSig();
    void onCloseWifiSig();


private:

    QString m_wifiName;
    int m_count;
   // QMap<QString,QString> m_wifiList;
    QStringList wifiNameList;

    bool m_bFirstCheck = true;


};

#endif // WIFITHREAD_H
