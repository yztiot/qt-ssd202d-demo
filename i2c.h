#ifndef I2C_H
#define I2C_H
#include <QObject>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


class I2C : public QObject
{
    Q_OBJECT
public:
    I2C();
    Q_INVOKABLE QString checkI2C(QString name);

private:
    QString m_strI2C0;
    QString m_strI2C1;
    QString m_path;
};

#endif // I2C_H
