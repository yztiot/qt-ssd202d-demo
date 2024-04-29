#include "serialfunction.h"

SerialFunction::SerialFunction()
{
    init();
}

void SerialFunction::init(){
    m_port = new QSerialPort;
    m_portName = "";
    m_serialModel = 1;

}

//触摸屏中ttyS2为485，ttyS1为232，电脑端测试为ttyUSB*
void SerialFunction::checkSerialPort(){
    QList<QSerialPortInfo> list  = QSerialPortInfo::availablePorts();
    for(int i = 0 ; i < list.length(); i++){
        qDebug()<<"useful port is::"<<list.at(i).portName();
//虚拟机端
//        if("ttyUSB0" == list.at(i).portName()){
//            m_portName = list.at(i).portName();
//        }
//触摸屏启用下面代码
        if(m_serialModel == 1 && "ttyS2" == list.at(i).portName()){
            m_portName = list.at(i).portName();
        }else if(m_serialModel == 0 && "ttyS1" == list.at(i).portName()){
            m_portName = list.at(i).portName();
        }
    }
}

//设置波特率 qt默认没有300, 600, 43000，56000
void SerialFunction::setBaud(QString baudModel){
    QStringList baudList ={"1200", "2400",
                          "4800", "9600", "19200", "38400",
                          "57600","115200"};
    switch (baudList.indexOf(baudModel)) {
    case 0:
        m_port->setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:
        m_port->setBaudRate(QSerialPort::Baud2400);
        break;
    case 2:
        m_port->setBaudRate(QSerialPort::Baud4800);
        break;
    case 3:
        m_port->setBaudRate(QSerialPort::Baud9600);
        break;
    case 4:
        m_port->setBaudRate(QSerialPort::Baud19200);
        break;
    case 5:
        m_port->setBaudRate(QSerialPort::Baud38400);
        break;
    case 6:
        m_port->setBaudRate(QSerialPort::Baud57600);
        break;
    case 7:
        m_port->setBaudRate(QSerialPort::Baud115200);
        break;

    default:
        m_port->setBaudRate(QSerialPort::UnknownBaud);
        break;
    }
}

//设置数据位
void SerialFunction::setBit(QString bitModel){
    QStringList bitList ={"5", "6", "7", "8"};
    switch (bitList.indexOf(bitModel)) {
    case 0:
        m_port->setDataBits(QSerialPort::Data5);
        break;
    case 1:
        m_port->setDataBits(QSerialPort::Data6);
        break;
    case 2:
        m_port->setDataBits(QSerialPort::Data7);
        break;
    case 3:
        m_port->setDataBits(QSerialPort::Data8);
        break;
    default:
        m_port->setDataBits(QSerialPort::UnknownDataBits);
        break;
    }
}

//设置校验位
void SerialFunction::setCheck(QString checkModel){
    QStringList checkList ={"None", "Odd", "Eyen Mark", "Space"};
    switch (checkList.indexOf(checkModel)) {
    case 0:
        m_port->setParity(QSerialPort::NoParity);
        break;
    case 1:
        m_port->setParity(QSerialPort::OddParity);
        break;
    case 2:
        m_port->setParity(QSerialPort::EvenParity);
        break;
    case 3:
        m_port->setParity(QSerialPort::SpaceParity);
        break;
    default:
        m_port->setParity(QSerialPort::UnknownParity);
        break;
    }
}

//设置停止位
void SerialFunction::setStop(QString stopModel){
    QStringList stopList ={"1", "1.5", "2"};
    switch (stopList.indexOf(stopModel)) {
    case 0:
        m_port->setStopBits(QSerialPort::OneStop);
        break;
    case 1:
        m_port->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    case 2:
        m_port->setStopBits(QSerialPort::TwoStop);
        break;
    default:
        m_port->setStopBits(QSerialPort::UnknownStopBits);
        break;
    }
}

void SerialFunction::runOpenSerial(QString raud, QString bit, QString check, QString stop){
    QMetaObject::invokeMethod( this, "openSerial",Qt::QueuedConnection, Q_ARG(QString, raud),
                               Q_ARG(QString, bit), Q_ARG(QString, check), Q_ARG(QString, stop));
}

/*收发必须要在两个不同的线程上进行*/
void SerialFunction::openSerial(QString raud, QString bit, QString check, QString stop){
    checkSerialPort();

    if(m_portName == ""){
        QString info = "没有可用串口";
        emit openSerialFail(info);
        return;
    }

    m_port->setPortName(m_portName);

    //打开串口
    setBaud(raud);
    setBit(bit);
    setCheck(check);
    setStop(stop);
    m_port->setFlowControl(QSerialPort::NoFlowControl);
    if(m_port->open(QIODevice::ReadWrite)){
       qDebug()<<"open successful";
       QString priInfo = "波特率："+ raud+ "\n数据位: "+ bit+ "\n校验位: "+ check+ "\n停止位: "+ stop;
       emit openSerialSuccessful(priInfo);
    }else{
        qDebug()<<"打开串口失败，请查看串口是否被占用"<<this->m_port->errorString();
    }

    m_serialThread = new SerialThread(m_port);

    m_thread = new QThread;
    m_serialThread->moveToThread(m_thread);

    connect(m_serialThread, SIGNAL(sendSerialData(QString)), this, SLOT(readData(QString)));
    connect(this,SIGNAL(startSig()),m_serialThread,SLOT(starThread()));
    m_thread->start();
    emit startSig();

    QEventLoop eventLoop;
    m_thread->wait(1);
    eventLoop.exec();
}

void SerialFunction::closeSerial(){
    if(m_portName.isEmpty()){
        return;
    }
    m_portName = "";
    m_port->close();
    m_thread->quit();
    m_thread->wait();
    delete m_serialThread;
    m_serialThread = nullptr;
}

//发送要写入串口的数据
void SerialFunction::writeSerialSig(QString data){

    if(m_portName.isEmpty()){
        QString strTip = "请打开串口";
        emit tipSig(strTip);
        return;
    }

    m_port->write(data.toLatin1());
    QString showData = "发送："+ data;
    emit writeSig(showData);
}

void SerialFunction::readData(QString data){
    emit serialDataSig(data);
}






