#include "unitfactory.h"

UnitFactory::UnitFactory(b2World& world, QObject* object)
    : _world(world), QObject(object) {}

Ball* UnitFactory::createBall(float x, float y, float radius) {
  return new Ball(_world, x, y, radius);
}

Box* UnitFactory::createBox(float x, float y, float width, float height) {
  return new Box(_world, x, y, width, height);
}
