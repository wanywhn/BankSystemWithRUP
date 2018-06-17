#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDebug>

#include <Qt>
#include <QZXing.h>
#include "application.h"
#include "creditctrl.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QGuiApplication app(argc, argv);

    QZXing::registerQMLTypes();

    qmlRegisterType<CreditCtrl>("cn.com.wanywhn",1,0,"CreditCtrl") ;
    Application customApp;
    customApp.checkPermissions();

    return app.exec();
}
