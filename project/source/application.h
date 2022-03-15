#pragma once

#include <QObject>

#include "keyboard/keyboardevents.h"
#include "map/mapfactory.h"
#include "screen/screenviewer.h"
#include "world.h"

class Application : public QObject {
  Q_OBJECT
 public:
  Application();

  void init();

  keyboard::KeyboardEvents* keyboardEvents();
  screen::ScreenViewer* screenViewer();
  World* world();

 signals:
  void createObject(int id, const QString& type, float x, float y, float width,
                    float height);
  void moveObjectTo(int id, const QString& type, float x, float y, float angle);

 public slots:
  void transformCreateObject(int id, const QString& type, float x, float y,
                             float width, float height);
  void transformMoveObjectTo(int id, const QString& type, float x, float y,
                             float angle);

  void createOnLeftClick(float x, float y);
  void createOnRightClick(float x, float y);

 private slots:
  void close();

 private:
  keyboard::KeyboardEvents _keyboardEvents;
  screen::ScreenViewer _screenViewer;
  World _world;
};
