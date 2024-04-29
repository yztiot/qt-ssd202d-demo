#include "internetsetting.h"

InternetSetting::InternetSetting()
{
    m_pingTimer = new QTimer(this);
    m_pingTimer->setInterval(1000);
    m_pingProcess     = nullptr;
    m_ifconfigProcess = nullptr;
}

InternetSetting::~InternetSetting()
{
    m_pingTimer->stop();;
    delete m_pingProcess;
    delete m_ifconfigProcess;
    m_pingProcess     = nullptr;
    m_ifconfigProcess = nullptr;
}


QString InternetSetting::ifconfig(){
    m_ifconfigProcess = new QProcess;
    QString ifc = "ifconfig";
    m_ifconfigProcess->start(ifc);
    m_ifconfigProcess->waitForFinished(-1);
    QString p_stdout = QString::fromLocal8Bit( m_ifconfigProcess->readAllStandardOutput());
    return p_stdout;
}


void InternetSetting::ping(){
    QString ifc = "ping www.baidu.com";
    m_pingProcess = new QProcess;
    m_pingProcess->start(ifc);
    connect(m_pingTimer, SIGNAL(timeout()), this, SLOT(getPing()));
    m_pingTimer->start();
}

void InternetSetting::startTimer(){
    m_pingTimer->start();
    QEventLoop loop;
    connect(m_pingTimer, SIGNAL(timeout()), this, SLOT(getPing()));
    loop.exec();
}

//获取ping的结果
void InternetSetting::getPing(){
    QString p_stdout = QString::fromLocal8Bit( m_pingProcess->readAllStandardOutput());
    m_StrPing = p_stdout;
    emit pingSig();
}

//关闭ping
void InternetSetting::closePing(){
    m_pingTimer->stop();
    m_pingProcess->close();
    delete m_pingProcess;
    m_pingProcess = nullptr;
}

//关闭ifconfig
void InternetSetting::closeIfconfig(){
    m_ifconfigProcess->close();
    delete m_ifconfigProcess;
    m_ifconfigProcess = nullptr;
}


