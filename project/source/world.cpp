#include "world.h"

#include <QDebug>
#include <memory>

World::World(QObject* parent)
    : QObject(parent),
      _world(b2Vec2(0.0f, gravity)),
      _factory(_world, this),
      _environmentFactory(_world, this) {}

void World::createFloor() {
  _blocks[_unitIndex] =
      std::shared_ptr<Wall>(_environmentFactory.create(0, 500, 800, 10));
  auto block = _blocks[_unitIndex];
  b2Body* body = block->body();
  b2Vec2 basePosition = body->GetPosition();
  emit createStaticObject(_unitIndex, basePosition.x, basePosition.y,
                          block->width() + 20, block->height());
  _unitIndex++;
}

void World::init() {
  _timer.setInterval(timeStep * 1000.f);
  _timer.start();
  connect(&_timer, &QTimer::timeout, this, &World::onTick);

  createFloor();
}

void World::onTick() {
  if (_units.empty()) {
    return;
  }

  _world.Step(timeStep, velocityIterations, positionIterations);

  for (auto& it : _units) {
    int index = it.first;
    auto body = it.second.get()->body();
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    emit updateObject(index, position.x, position.y, angle);
  }

  _timer.start();
}

void World::createBall(float x, float y) {
  _units[_unitIndex] = std::shared_ptr<BasicUnit>(_factory.createBall(x, y));
  b2Body* body = _units[_unitIndex]->body();
  b2Vec2 basePosition = body->GetPosition();
  float baseAngle = body->GetAngle();
  emit createObject(_unitIndex, _units[_unitIndex]->width());
  emit updateObject(_unitIndex, basePosition.x, basePosition.y, baseAngle);
  _unitIndex++;
}

void World::createOnClick(int x, int y) {
  float scalledX = (float)x;
  float scalledY = (float)y;
  createBall(scalledX, scalledY);
}
