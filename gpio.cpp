#include "gpio.h"
#define DEVICE_NAME "/dev/i2c-0"

GPIO::GPIO()
{
    m_sysGPIODir = "/sys/class/gpio";
    m_strCurrentPath = m_sysGPIODir + "/gpio11";
}

void GPIO::gpioModel(QString model){
    QString strModel = m_sysGPIODir + "/" + model;

    QFileInfo dir(strModel);
    if(dir.isDir()){
        m_strCurrentPath = strModel;
    }else{
        QString createName = model.mid(4, model.length());

        QString sysOrder = "echo " + createName +" > " + m_sysGPIODir +"/export";
        QString sysOutOrder = "echo out > " + m_sysGPIODir +"/" + model + "/direction";
        system(sysOrder.toLatin1().data());
        system(sysOutOrder.toLatin1().data());
        QString strCreate =  QString("创建新的GPIO：") + model;
        emit gpioSig(strCreate);
    }
}


/*设置输入输出方向*/
void GPIO::setIODirection(QString ioName, QString direction){

    QString path = m_sysGPIODir + "/" + ioName;
    QFileInfo dir(path);
    QString strSig = "";
    if(dir.isDir()){
      QString strDirection = path + "/direction";
      QFileInfo file(strDirection);
      if(file.isFile()){
          QString sysOrder = "echo " + direction + " > " + path + "/direction";
          system(sysOrder.toLatin1().data());
          strSig = ioName + "设置IO方向为："+ direction;
          emit gpioSig(strSig);
      }else{
          strSig = "打开文件：" + strDirection+  "出错";
          emit gpioSig(strSig);
      }
    }else{
        strSig = ioName + "设置IO方向失败" +direction;
        emit gpioSig(strSig);
    }
}

/*设置电平的高低*/
void GPIO::setHighLowLevel(QString ioName, QString level){
    QString path = m_sysGPIODir + "/" + ioName;
    QFileInfo dir(path);
    QString strSig = "";
    if(dir.isDir()){
      QString strLevel = path + "/value";
      QFileInfo file(strLevel);
      if(file.isFile()){
          QString sysOrder = "echo " + level + " > " + path + "/value";
          system(sysOrder.toLatin1().data());
          strSig = ioName + "设置电平为为：" + level;
          emit gpioSig(strSig);
      }else{
                strSig = "打开文件：" + strLevel+  "出错";
                emit gpioSig(strSig);
            }
    }else{
        strSig = ioName + "设置电平失败" + level;
        emit gpioSig(strSig);
    }
}
