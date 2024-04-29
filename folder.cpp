#include "folder.h"

Folder::Folder()
{
    m_strTotalBuf = "";
    m_strTotalUsable = "";
    m_folderList.clear();

 //   QString HomeLocation = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    /*初始为根目录*/
    m_strInitPath = "/";
    m_strCurrentPath = "/";
  //  m_strInitPath = m_strCurrentPath;
    getDiskInfo();
    folderList();
}

void Folder::getDiskInfo(){

    QStorageInfo home = QStorageInfo::root();
    qint64 nTotal = home.bytesTotal();
    qint64 nAvailable= home.bytesAvailable();

    // 判断总大小容量与剩余大小容量
    if(nTotal >= 1024){
        qint64 kTotal = nTotal/1024;
        if(kTotal >= 1024 ){
            qint64 mTotal = kTotal/1024;
            if(mTotal >= 1024){
                qint64 gTotal = mTotal/1024;
                m_strTotalBuf = QString::number(gTotal)+ "GB";
            }else{
                m_strTotalBuf = QString::number(mTotal)+ "MB";
            }
        }else{
            m_strTotalBuf = QString::number(kTotal)+ "KB";
        }
    }

    if(nAvailable >= 1024){
        qint64 kAvailable = nAvailable/1024;
        if(kAvailable >= 1024 ){
            qint64 mAvailable = kAvailable/1024;
            if(mAvailable >= 1024){
                qint64 gAvailable = mAvailable/1024;
                m_strTotalUsable = QString::number(gAvailable)+ "GB";
            }else{
                m_strTotalUsable = QString::number(mAvailable)+ "MB";
            }
        }else{
            m_strTotalUsable = QString::number(kAvailable)+ "KB";
        }
    }
}


/*获取文件夹数量*/
void Folder::folderList(){
    m_folderList.clear();
    m_fileList.clear();

    QDir dir(m_strCurrentPath);

    QFileInfoList folderList = dir.entryInfoList();

    QFileInfo isDir;
    int nList = folderList.count();
    for(int i = 0; i < nList; i++){
        isDir = folderList.at(i);

        if(isDir.fileName() == "." || isDir.fileName() == ".."){
            i++;
            continue;
        }

        if(isDir.isDir() ){
            m_folderList.append(isDir.baseName());
        }else if(isDir.isFile()){
            m_fileList.append(isDir.fileName());
        }

    }
}

/*删除文件夹或文件*/
void Folder::deleteFolder(QString name){
    QString path = m_strCurrentPath+"/"+name;

    QFileInfo currentFolder(path);
    if(currentFolder.isDir()){
        QDir dir(path);
        dir.removeRecursively();
    }else if(currentFolder.isFile()){
        QFile file(path);
        file.remove();
    }else{
        return ;
    }
    /*重新获取系统大小跟文件数量*/
    getDiskInfo();
    folderList();
    handleCurrentPath();
}

/*添加文件夹*/
void Folder::addFolder(QString name){
    QDir dir(m_strCurrentPath);
    if(!dir.exists(name)){
        dir.mkdir(name);
        getDiskInfo();
        folderList();
        handleCurrentPath();
    }

}

/*编辑文件夹或文件*/
void Folder::editFolder(QString oldNmae, QString newName){
    QString path = m_strCurrentPath+ "/"+ oldNmae;
    QString newPath = m_strCurrentPath+ "/" + newName;

    QFileInfo currentFolder(path);
    if(currentFolder.isDir() || currentFolder.isFile()){
        QDir dir(path);
        dir.rename(path, newPath);

        /*重新获取系统大小跟文件数量*/
        getDiskInfo();
        folderList();
        handleCurrentPath();
       // emit updataFolderSig(m_strCurrentPath);
    }else{
        return ;
    }
}

void Folder::inFolder(QString path){
    qDebug()<<"the current folder::"<< m_strCurrentPath<< "::"<< path;
   // QString str = m_strCurrentPath + "/" + path;
    /*判断点击的是否为文件夹*/
  //  QFileInfo info(str);
    if(!path.isEmpty()){
        m_strCurrentPath = m_strCurrentPath + "/" + path;
        folderList();
        handleCurrentPath();
    }

   // emit updataFolderSig(m_strCurrentPath);
}

/*返回上一级*/
void Folder::comeBack(){
    qDebug()<<"come back m_strcurrentPaht::"<< m_strCurrentPath;
    if(m_strInitPath == m_strCurrentPath){
        emit comeBackSig();
    }else{
        QStringList list = m_strCurrentPath.split("/");
        m_strCurrentPath = "";
        int nLength = list.length();
        for (int i = 0; i < nLength - 1; i++) {
            if(i == nLength - 2){
                m_strCurrentPath += list[i];
            }else{
                m_strCurrentPath += list[i] +"/";
            }
        }
        folderList();
        handleCurrentPath();
       // emit updataFolderSig(m_strCurrentPath);
    }
}

/*处理路径字符串*/
void Folder::handleCurrentPath(){
    QString str = m_strCurrentPath;
    QStringList list = str.split("/");
    str = "/>";
    if(list.length() > 2){
        for (int i = 2; i < list.length() ; i++) {
            if(i == list.length() -1){
                str += list[i];
            }else{
                str += list[i] +">";
            }
        }
    }else{
        str = "/";
    }

    emit updataFolderSig(str);
}
