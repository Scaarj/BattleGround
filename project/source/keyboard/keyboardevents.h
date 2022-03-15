#pragma once

#include <QWidget>

#include <QDebug>
#include <QKeyEvent>

namespace keyboard {
class KeyboardEvents : public QObject {
  Q_OBJECT
 public:
  KeyboardEvents(QObject* parent = nullptr);

 signals:
  void escapePressed();
  void moveScreenPressed(int x, int y);

 public slots:
  void keyPressed(int key);
};
}  // namespace keyboard
