#include "unitfactory.h"
#include "ball.h"

UnitFactory::UnitFactory(b2World& world, QObject* object)
    : _world(world), QObject(object) {}

Ball* UnitFactory::createBall(float x, float y) {
  return new Ball(_world, x, y);
}
