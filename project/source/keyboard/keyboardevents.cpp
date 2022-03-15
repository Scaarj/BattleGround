#include "keyboardevents.h"

#include <QDebug>
#include <QKeyEvent>

using namespace keyboard;

KeyboardEvents::KeyboardEvents(QObject *parent) {}

void KeyboardEvents::keyPressed(int key) {
  switch (key) {
    case Qt::Key_J:
      qDebug() << "j pressed";
      break;
    case Qt::Key_Left:
      emit moveScreenPressed(-1, 0);
      break;
    case Qt::Key_Right:
      emit moveScreenPressed(1, 0);
      break;
    case Qt::Key_Up:
      emit moveScreenPressed(0, 1);
      break;
    case Qt::Key_Down:
      emit moveScreenPressed(0, -1);
      break;
    case Qt::Key_Escape:
      emit escapePressed();
      break;
    default:
      break;
  }
}
