#include "environmentfactory.h"
#include "wall.h"

EnvironmentFactory::EnvironmentFactory(b2World& world, QObject* object)
    : _world(world), QObject(object) {}

Wall* EnvironmentFactory::create(float x, float y, float width, float height) {
  return new Wall(_world, x, y, width, height);
}
