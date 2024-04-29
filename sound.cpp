#include "sound.h"
#include "include/audio.h"


Sound::Sound()
{
    m_strPath = "";
    m_strPath = QDir::currentPath();
    m_strSoundNameList.clear();
    //findSoundFile();
}

/*寻找当前mp3文件，在运行文件的目录可自行修改*/
void Sound::findSoundFile(){
    /*此路径可自行更改为mp3的所在目录路径*/
    QString path = QDir::currentPath();
    // QString path = "/root/";
    // printf("当前目录%s\n",path);
    qDebug()<<"current path::"<< path;
    m_strSoundNameList.clear();
    QFileInfo info = QFileInfo(path);

    if(info.isDir()){
        QDir dir = QDir(path);
        QStringList list = dir.entryList();
        foreach (QString file, list) {
            QFileInfo fileInfo = QFileInfo(file);
            if(fileInfo.isFile()){
                QString strFile(file);
                if(strFile.contains(".mp3")){
                    m_strSoundNameList.append(strFile);
                }
            }
        }
    }else{
        return;
    }
}

/*获取音频文件*/
QStringList Sound::getSoundFile(){
    // qDebug()<<"hello sound::"<< m_strSoundNameList;
    return m_strSoundNameList;
}

QString Sound::getSoundPath(){
    return m_strPath;
}

void Sound::setPath(){

}

//sound stop
void Sound::musicStop(){
    #if QtForArm
        Mp3PlayStopDec();
    #else

    #endif

}

// set sound
void Sound::setSound(QString num){
    int n =num.toInt();
    #if QtForArm
        set_volume(n-70);
    #else
    #endif

}

void Sound::musicPlay(QString name){

    QByteArray byteArray = name.toUtf8();
    const char* mp3FileName = byteArray.constData();
#if QtForArm
    mp3_codec(const_cast<char*>(mp3FileName));
#else
#endif


}

