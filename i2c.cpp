#include "i2c.h"

//#define DEVICE_NAME "/dev/i2c-0"

I2C::I2C()
{
    m_path = "/dev/";
}

/*检测是否存在I2C*/
QString I2C::checkI2C(QString name){
    qDebug()<<"the name is::"<< name<<"::"<<m_path;
    QString i2cContent = "";
    QString i2cModel = m_path + name;
    int fd = open(i2cModel.toLatin1().data(), O_RDWR);
    if(fd < 0){
        i2cContent = "扫描没有发现"+ name;
    }else{
        i2cContent = "扫描发现"+ name;
    }
    close(fd);
    return i2cContent;

}
