#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H
#include <QObject>
#include <QProcess>
#include <QTime>
#include <QDebug>
#include <QDateTime>
#include <string>
#include <QTimer>
#include <QEvent>
#include <cstdlib>
#include <QFile>
#include <QDir>
#include <QCoreApplication>


class SystemSetting: public QObject
{
    Q_OBJECT
public:
    SystemSetting();
    ~SystemSetting();
    /*设置系统时间*/
    Q_INVOKABLE void setSysTime(QString timer);
    /*设置背光亮度*/
    Q_INVOKABLE void setSysLight(QString lightNum);
    /*获取背光亮度*/
    Q_INVOKABLE int getSysLight();
    /*设置音量*/
    Q_INVOKABLE void setSysVol(QString volNum);
    /*设置屏保*/
    Q_INVOKABLE void setScreenSave(int time, bool openScreenSave);

    /*获取设置屏保时间*/
    Q_INVOKABLE QString getScreenSaveModel();

    bool eventFilter(QObject *ob, QEvent *e);

    /*初始化屏保文件*/
    void initScreenSave();
    /*设置屏保时间*/
    void setScreenSaveModel(QString model);



signals:
    void updateTimeSig();
    void screenSaveSig();


public slots:
    void onScreenSaveTimeOut();

private:
    QString m_strSystime;
    QString m_strSysScreenSave;
    QProcess *m_process;
    QTimer *m_timer;

    bool m_haveDosth = false;
    bool m_bOpenScreenSave;
};

#endif // SYSTEMSETTING_H
