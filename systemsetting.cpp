#include "systemsetting.h"

SystemSetting::SystemSetting()
{
    m_strSystime = "";
    m_timer = nullptr;
    m_timer = new QTimer;
    m_process = new QProcess;
    m_bOpenScreenSave = false;
    m_strSysScreenSave = "";
   // QString path = QCoreApplication::applicationDirPath();
   // qDebug()<<"path::"<< path;
    initScreenSave();
}

SystemSetting::~SystemSetting(){
    delete m_process;
    delete m_timer;
    m_process = nullptr;
    m_timer = nullptr;
}

/*设置系统时间*/
void SystemSetting::setSysTime(QString time){
    QString data ;
    QDebug(&data).nospace() <<"date -s "<< time ;


    std::string str = data.toStdString();
    const char* ch = str.c_str();

    qDebug()<<"sys time is::"<< data<<"::"<<ch;
    system(ch);
    system("hwclock -w");
    emit updateTimeSig();
}

/*设置背光亮度*/
void SystemSetting::setSysLight(QString lightNum){
    QString order = "echo " + lightNum + " > /sys/class/pwm/pwmchip0/pwm0/duty_cycle";
    std::string str = order.toStdString();
    const char* pt = str.c_str();
    system(pt);
}

/*获取背光亮度*/
int SystemSetting::getSysLight(){
    QString add = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle";
    QFileInfo currentFolder(add);
    int nLight = 50;
    if(currentFolder.isFile()){
        QFile file(add);
        if(file.open(QIODevice::ReadOnly)){
            QByteArray array;
            array = file.readAll().simplified();
            nLight = array.toInt();
        }

    }else{
    }
    return nLight;
}

/*设置音量*/
void SystemSetting::setSysVol(QString volNum){
    QString order = "pactl set-sink-volume 1 " +  volNum;
    system(order.toLatin1().data());
}

/*
* @brief 设置屏保*
* @param time 屏保时间
* @param openScreenSave 是否开启屏保
*/
void SystemSetting::setScreenSave(int time, bool openScreenSave){
    if(!m_timer){
        m_timer = new QTimer;
    }

    m_bOpenScreenSave = openScreenSave;
    switch (time) {
    case 1:
        m_strSysScreenSave = "0";
        break;
    case 5:
        m_strSysScreenSave = "1";
        break;
    case 10:
        m_strSysScreenSave = "2";
        break;
    case 30:
        m_strSysScreenSave = "3";
        break;
    case 60:
        m_strSysScreenSave = "4";
        break;
    default:
        m_strSysScreenSave = "5";
        break;
    }
    setScreenSaveModel(m_strSysScreenSave);

    connect(m_timer,SIGNAL(timeout()), this, SLOT(onScreenSaveTimeOut()));
    if(!m_bOpenScreenSave){
        m_timer->stop();
    }else{
        m_timer->setInterval(time * 60 * 1000);
        m_timer->start();
    }
}

void SystemSetting::initScreenSave(){
   // QString dir = QDir::currentPath();
    QString filePath = "/tmp/screenSave";
    QFileInfo info(filePath);
    if(info.isFile()){
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly| QIODevice::Text)){
           QByteArray dateArr = file.readAll();

           QString date = dateArr.simplified();
           m_strSysScreenSave = date;
        }

    }else{
        qDebug()<<"creat tmp::";
        system("echo 5 > /tmp/screenSave");
    }
}

/*设置屏保时间*/
void SystemSetting::setScreenSaveModel(QString model){
  //  QString dir = QDir::currentPath();
    QString filePath = "/tmp/screenSave";
    QFileInfo info(filePath);
    if(info.isFile()){
        QString strOrder = "echo "+ model + " > /tmp/screenSave";
        std::string str = strOrder.toStdString();
        const char* pt = str.c_str();
        system(pt);

    }else{
        qDebug()<<"set light false::";

    }
}

QString SystemSetting::getScreenSaveModel(){
    return m_strSysScreenSave;
}

void SystemSetting::onScreenSaveTimeOut(){
    if(m_haveDosth)
    {
        m_haveDosth=false;
        emit screenSaveSig();
    }
}

/*重写鼠标事件，获取鼠标是否在限定时间内进行了位置的改动*/
bool SystemSetting::eventFilter(QObject *ob, QEvent *e)
{
    //  判断如果是鼠标移动事件
    if(e->type()==QEvent::MouseMove)
    {
        //标志是否有过鼠标操作变量
        if(!m_haveDosth)
        {
            m_haveDosth=true;
        }
        //m_timer在这判断是否已经开启.
        if(m_timer->isActive())
        {
            //如果已经开启，并且有鼠标移动事件就需要计时器重新计算
            m_timer->stop();
            if(m_bOpenScreenSave){
                m_timer->start();
            }

            qDebug()<<"m_haveDosthtimer restart";
        }
    }
    //其他事件仍然交给系统处理。这句一定不能少。
    return QObject::eventFilter(ob,e);
}

