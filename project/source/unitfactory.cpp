#include "unitfactory.h"
#include "ball.h"
#include "box.h"
#include "wall.h"

#include <QDebug>

UnitFactory::UnitFactory(b2World& world, QObject* object)
    : _world(world), QObject(object) {}

BasicUnit* UnitFactory::createBall(float x, float y, float radius) {
  return new Ball(_world, x, y, radius);
}

BasicUnit* UnitFactory::createBox(float x, float y, float width, float height) {
  return new Box(_world, x, y, width, height);
}

BasicUnit* UnitFactory::createWall(float x, float y, float width,
                                   float height) {
  return new Wall(_world, x, y, width, height);
}
