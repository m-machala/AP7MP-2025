#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QQmlContext>

#include <image.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QList<QObject*> m_images;
    m_images.append(new Image("Space", "1.jpg"));
    m_images.append(new Image("Dog", "2.webp"));
    m_images.append(new Image("Bird", "3.jpg"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("pictures", QVariant::fromValue(m_images));
    engine.loadFromModule("CV12", "Main");


    return app.exec();
}
