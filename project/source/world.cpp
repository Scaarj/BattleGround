#include "world.h"

#include <QDebug>
#include <memory>

World::World(QObject* parent)
    : QObject(parent),
      _world(b2Vec2(0.0f, worldGravity)),
      _factory(_world, this),
      _unitContainer(this) {
  connect(&_timer, &QTimer::timeout, this, &World::onTick);
  _map = _mapFactory.createMap();
}

void World::init() {
  createWall(0.f, 500.f, 1000.f, 100.f);
  createWall(0.f, 0.f, 20.f, 500.f);
  createWall(780.f, 0.f, 20.f, 500.f);
  createWall(200.f, 300.f, 200.f, 20.f);

  _timer.setInterval(timeStep * 1000.f);
  _timer.start();
}

void World::onTick() {
  _world.Step(timeStep, velocityIterations, positionIterations);

  _unitContainer.update();

  _timer.start();
}

void World::createBall(float x, float y, float radius) {
  _unitContainer.collect(_factory.createBall(x, y, radius));
}

void World::createBox(float x, float y, float width, float height) {
  _unitContainer.collect(_factory.createBox(x, y, width, height));
}

void World::createWall(float x, float y, float width, float height) {
  _unitContainer.collect(_factory.createWall(x, y, width, height));
}

void World::createOnRightClick(float x, float y) {
  float width = 80.f;
  float height = 80.f;
  createBox(x, y, width, height);
}

void World::createOnLeftClick(float x, float y) {
  float radius = 20.f;
  createBall(x, y, radius);
}
