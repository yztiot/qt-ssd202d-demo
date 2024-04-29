#ifndef SOUND_H
#define SOUND_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QStorageInfo>
#include <QStandardPaths>
#include "HeadDefine.h"
class Sound: public QObject
{
    Q_OBJECT
public:
    Sound();

    /*获取音频文件*/
    Q_INVOKABLE QStringList getSoundFile();
    /*返回音频的路径*/
    Q_INVOKABLE QString getSoundPath();

    Q_INVOKABLE void musicPlay(QString name);
    Q_INVOKABLE void musicStop();
    Q_INVOKABLE void setSound(QString num);

    /*设置获取音频路径*/
    void setPath();

    Q_INVOKABLE void findSoundFile();


private:
    /* 获取mp3文件的路径*/
    QString m_strPath;
    QStringList m_strSoundNameList;


};

#endif // SOUND_H
