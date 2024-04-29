#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QQmlContext>
#include "internetsetting.h"
#include "folder.h"
#include "systemsetting.h"
#include "serialfunction.h"
#include "gpio.h"
#include "i2c.h"
#include "wifi.h"
#include "sound.h"
#include "stdlib.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
  //  qputenv("QT_IM_MODULE",QByteArray("Qt5Input"));
    QGuiApplication app(argc, argv);

   //QFontDatabase::addApplicationFont(QLatin1String(":/fonts/AlibabaPuHuiTi2.ttf"));

    QQmlApplicationEngine engine;

    InternetSetting internetSetting;
    Folder folder;

    SystemSetting systemSetting;
    SerialFunction serialFunction;
    GPIO gpio;
    I2C i2c;
    Sound sound;

    WiFi wifi;

    //app是QApplication的实例，给a安装事件过滤器。
    app.installEventFilter(&systemSetting);

    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("InternetSetting", &internetSetting);
    ctx->setContextProperty("Folder", &folder);
    ctx->setContextProperty("SystemSetting", &systemSetting);
    ctx->setContextProperty("SerialFunction", &serialFunction);
    ctx->setContextProperty("GPIO", &gpio);
    ctx->setContextProperty("I2C", &i2c);
    ctx->setContextProperty("WiFi", &wifi);
    ctx->setContextProperty("Sound", &sound);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
