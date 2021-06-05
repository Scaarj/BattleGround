#pragma once

#include <Box2D/Box2D.h>
#include <QObject>

#include "basicunit.h"

class UnitFactory : public QObject {
  Q_OBJECT

 public:
  explicit UnitFactory(b2World& world, QObject* object);
  BasicUnit* createBall(float x, float y, float radius);
  BasicUnit* createBox(float, float y, float width, float height);
  BasicUnit* createWall(float x, float y, float width, float height);

 private:
  b2World& _world;
};
