#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppData.h"
#include "QQmlContext"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    AppData * appData = new AppData();

    engine.rootContext()->setContextProperty("myAppData", appData);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
