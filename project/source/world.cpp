#include "world.h"

#include <QDebug>
#include <memory>

World::World(QObject* parent)
    : QObject(parent),
      _world(b2Vec2(0.0f, WORLD_GRAVITY)),
      _factory(_world, this) {
  timeStep = 1.0f / 10.0f;
  velocityIterations = 6;
  positionIterations = 2;

  connect(&_timer, &QTimer::timeout, this, &World::onTick);
}

void World::init() {
  groundBodyDef.position.Set(0.0f, 5.0f);
  groundBody = _world.CreateBody(&groundBodyDef);
  groundBox.SetAsBox(10.0f, 0.1f);
  groundBody->CreateFixture(&groundBox, 0.0f);

  _timer.setInterval(50);
  _timer.start();
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
    emit moveObjectTo(index, ratio * position.x, ratio * position.y, angle);
  }

  _timer.start();
}

void World::createBall(float x, float y) {
  _units[_unitIndex] = std::shared_ptr<BasicUnit>(_factory.createBall(x, y));
  b2Body* body = _units[_unitIndex]->body();
  b2Vec2 basePosition = body->GetPosition();
  float baseAngle = body->GetAngle();
  emit createObject(_unitIndex, ratio * _units[_unitIndex]->width());
  emit moveObjectTo(_unitIndex, ratio * basePosition.x, ratio * basePosition.y,
                    baseAngle);
  _unitIndex++;
}

void World::createOnClick(int x, int y) {
  float scalledX = (float)x / ratio;
  float scalledY = (float)y / ratio;
  createBall(scalledX, scalledY);
}
