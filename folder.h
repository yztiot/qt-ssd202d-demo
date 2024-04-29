#ifndef FOLDER_H
#define FOLDER_H
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QStorageInfo>
#include <QStandardPaths>


class Folder : public QObject
{
    Q_OBJECT
public:
    Folder();

    /*获取系统硬盘总大小*/
    Q_INVOKABLE QString getTotalBuf(){ return m_strTotalBuf;}
    /*获取系统硬盘可用大小*/
    Q_INVOKABLE QString getTotalUsable(){return m_strTotalUsable;}
    /*获取文件夹数量*/
    Q_INVOKABLE QStringList getFolderList(){return m_folderList;}
    /*获取文件数量*/
    Q_INVOKABLE QStringList getFileList(){return m_fileList;}
    /*删除文件夹*/
    Q_INVOKABLE void deleteFolder(QString name);
    /*添加文件夹*/
    Q_INVOKABLE void addFolder(QString name);
    /*编辑文件夹*/
    Q_INVOKABLE void editFolder(QString oldName, QString newName);
    /*进入下一级文件夹*/
    Q_INVOKABLE void inFolder(QString path);
    /*返回上一级*/
    Q_INVOKABLE void comeBack();

    void getDiskInfo();
    void folderList();
    void handleCurrentPath();

signals:
    void sigDelFolder();
    void SigEditFolder();
    void updataFolderSig(QString path);
    void comeBackSig();

private:
    QString m_strTotalBuf;
    QString m_strTotalUsable;
    QString m_strInitPath;
    QString m_strCurrentPath;
    QStringList m_folderList;
    QStringList m_fileList;




};

#endif // FOLDER_H
