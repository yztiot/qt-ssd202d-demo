#include "wifi.h"
//#include "wlanapi.h"
//#define MAX_SCAN_RESULTS 64

WiFi::WiFi(){
    m_thread = nullptr;
    m_wifiThread = nullptr;
    m_wifiState = false;
    m_wifiNameList.clear();
}

WiFi::~WiFi(){
    m_thread->quit();
    m_thread->wait();
    delete m_thread;
    delete m_wifiThread;
    m_thread = nullptr;
    m_wifiThread = nullptr;
}

//这里要用这种方式调用函数，不如会炸掉界面
void WiFi::runScanWiFi()
{
    QMetaObject::invokeMethod( this, "onRunScanWiFi",Qt::QueuedConnection);
}

void WiFi::onRunScanWiFi()
{
    scanWiFi();
}

/*扫描wifi*/
void WiFi::scanWiFi(){

    if(!m_thread){
        m_thread = new QThread;
    }
    if(!m_wifiThread){
        m_wifiThread= new WiFiThread();
        m_wifiThread->moveToThread(m_thread);

        connect(this, SIGNAL(startSig()), m_wifiThread, SLOT(createWifiFile()));
        connect(m_wifiThread, SIGNAL(wifiNameSig(QStringList)), this, SLOT(onWifiNameSig(QStringList)));
        connect(this, SIGNAL(connectWiFiSig(QString,QString)), m_wifiThread, SLOT(onConnectWiFiSig(QString,QString)));
        connect(m_wifiThread, SIGNAL(wifiConnectSuccessfulSig(QString)), this, SLOT(onWifiConnectSuccessfulSig(QString)));
        connect(this, SIGNAL(disconnectWiFiSig()), m_wifiThread, SLOT(onDisConnectWiFiSig()));
        connect(m_wifiThread, SIGNAL(disConnectCurrentWiFiSig()), SLOT(onDisConnectCurrentWiFiSig()));
        connect(this, SIGNAL(closeWiFiSig()), m_wifiThread, SLOT(onCloseWifiSig()));
        connect(m_wifiThread, SIGNAL(closeWiFiThreadSig()), this, SLOT(onCloseWiFiThreadSig()));

        m_thread->start();
        emit startSig();

        QEventLoop eventLoop;
        m_thread->wait(1);
        eventLoop.exec();

    }

}

void WiFi::onWifiNameSig(QStringList name){
    m_wifiNameList.clear();
    m_wifiNameList = name;
    emit wifiNameQml(name);
}

/* 连接成功返回*/
void WiFi::onWifiConnectSuccessfulSig(QString name){
    emit connectCurrentNameSig(name);
}

/* 连接wifi*/
void WiFi::connectWiFi(QString name, QString password){
    emit connectWiFiSig(name, password);
}

/*关闭wifi*/
void WiFi::closeWiFi(){
    emit closeWiFiSig();
}

/*断开wifi*/
void WiFi::disconnectWiFi(){
    emit disconnectWiFiSig();
}

/*响应断开当前连接从子线程发挥来的数据*/
void WiFi::onDisConnectCurrentWiFiSig(){
    emit disCurrentWifiSigQml();
}

//设置wifi状态
void WiFi::setWifiCurrentState(bool state){
    m_wifiState = state;
}

/*获取当前是否打开wifi状态*/
bool WiFi::getWifiCurrentState(){
    return m_wifiState;
}
void WiFi::disconnectSignalsAndSlots() {
    disconnect(this, SIGNAL(startSig()), m_wifiThread, SLOT(createWifiFile()));
}

void WiFi::onCloseWiFiThreadSig() {
    qDebug() << "quit wifi thread::";
    m_wifiState = false;

    if (m_thread != nullptr) {
        m_thread->quit();
        m_thread->wait();
        // 删除线程
        delete m_thread;
        m_thread = nullptr;
    }

    if (m_wifiThread != nullptr) {
        // 断开连接，确保不再有信号槽连接
//        disconnectSignalsAndSlots();
        // 删除线程对象
        delete m_wifiThread;
        m_wifiThread = nullptr;
    }
    disCurrentWifiSigQml();
}
