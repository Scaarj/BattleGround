#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include "ball.h"
#include "basicunit.h"
#include "box.h"

class UnitFactory : public QObject {
  Q_OBJECT

 public:
  explicit UnitFactory(b2World&, QObject* object);
  Ball* createBall(float x, float y, float radius);
  Box* createBox(float x, float y, float width, float height);

 private:
  b2World& _world;
};
