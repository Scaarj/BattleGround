#include "world.h"

#include <QDebug>
#include <memory>

World::World(QObject* parent)
    : QObject(parent),
      _world(b2Vec2(0.0f, gravity)),
      _factory(_world, this),
      _environmentFactory(_world, this) {}

void World::createFloor(float x, float y, float width, float height) {
  _blocks[_unitIndex] = _environmentFactory.create(x, y, width, height);
  auto block = _blocks[_unitIndex];
  emit createStaticObject(_unitIndex, block->x(), block->y(), block->width(),
                          block->height());
  _unitIndex++;
}

void World::init() {
  _timer.setInterval(timeStep * 1000.f);
  _timer.start();
  connect(&_timer, &QTimer::timeout, this, &World::onTick);

  createFloor(400, 500, 400, 40);
  createFloor(0, 0, 20, 500);
  createFloor(780, 200, 20, 300);
  createFloor(400, 200, 200, 60);
}

void World::onTick() {
  if (_units.empty()) {
    return;
  }

  _world.Step(timeStep, velocityIterations, positionIterations);

  for (auto& it : _units) {
    int index = it.first;
    auto body = it.second;
    emit updateObject(index, body->x(), body->y(), body->angle());
  }

  _timer.start();
}

void World::createBall(float x, float y, float radius) {
  _units[_unitIndex] = _factory.createBall(x, y, radius);
  auto unit = _units[_unitIndex];
  emit createBallObject(_unitIndex, _units[_unitIndex]->width());
  emit updateObject(_unitIndex, unit->x(), unit->y(), unit->angle());
  _unitIndex++;
}

void World::createBox(float x, float y, float width, float height) {
  _units[_unitIndex] = _factory.createBox(x, y, width, height);
  auto unit = _units[_unitIndex];
  emit createBoxObject(_unitIndex, _units[_unitIndex]->width());
  emit updateObject(_unitIndex, unit->x(), unit->y(), unit->angle());
  _unitIndex++;
}

void World::createOnClick(int x, int y) {
  float size = 40.f;
  createBall(x, y, size);
}

void World::createOnRightClick(int x, int y) {
  float width = 40.f;
  float height = 40.f;
  createBox(x, y, width, height);
}
