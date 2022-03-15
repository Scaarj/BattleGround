#include "application.h"

#include <QApplication>
#include <QDebug>
#include <QKeyEvent>

using namespace keyboard;

Application::Application() : _screenViewer(1600, 900) {
  connect(&_keyboardEvents, &KeyboardEvents::escapePressed, this,
          &Application::close);
  connect(&_keyboardEvents, &KeyboardEvents::moveScreenPressed, &_screenViewer,
          &screen::ScreenViewer::move);

  connect(&_world._unitContainer, &UnitContainer::createObject, this,
          &Application::transformCreateObject);
  connect(&_world._unitContainer, &UnitContainer::moveObjectTo, this,
          &Application::transformMoveObjectTo);
}

void Application::init() { _world.init(); }

keyboard::KeyboardEvents *Application::keyboardEvents() {
  return &_keyboardEvents;
}

screen::ScreenViewer *Application::screenViewer() { return &_screenViewer; }

World *Application::world() { return &_world; }

void Application::transformCreateObject(int id, const QString &type, float x,
                                        float y, float width, float height) {
  emit createObject(id, type, x + _screenViewer.x(), y + _screenViewer.y(),
                    width, height);
}

void Application::transformMoveObjectTo(int id, const QString &type, float x,
                                        float y, float angle) {
  emit moveObjectTo(id, type, x + _screenViewer.x(), y + _screenViewer.y(),
                    angle);
}

void Application::createOnLeftClick(float x, float y) {
  _world.createOnLeftClick(x - _screenViewer.x(), y - _screenViewer.y());
}

void Application::createOnRightClick(float x, float y) {
  _world.createOnRightClick(x - _screenViewer.x(), y - _screenViewer.y());
}

void Application::close() {
  qDebug() << "save all...";
  QApplication::quit();
}
