#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "world.h"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);
  World world;

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml/MainWindow.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  QQmlContext *context = engine.rootContext();
  context->setContextProperty("World", &world);
  context->setContextProperty("Objects", &world._unitContainer);

  engine.load(url);

  world.init();

  return app.exec();
}
