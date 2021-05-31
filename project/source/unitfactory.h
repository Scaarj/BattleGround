#pragma once

#include <Box2D/Box2D.h>
#include <QObject>
#include "ball.h"
#include "basicunit.h"

class UnitFactory : public QObject {
  Q_OBJECT

 public:
  explicit UnitFactory(b2World&, QObject* object);
  Ball* createBall(float, float);

 private:
  b2World& _world;
};
