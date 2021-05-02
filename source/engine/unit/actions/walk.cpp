#include "walk.h"

using namespace engine::unit::actions;

Walk::Walk(Unit* unit) : Action(unit) {}

void Walk::timeTick(float time) {
  if (!_unit) {
    return;
  }
  engine::math::Vector2d position = _unit->position();
  engine::math::Vector2d direction = _unit->direction();
  _unit->setPosition(position + direction * _speed * time);
}

float Walk::speed() const { return _speed; }

void Walk::setSpeed(float speed) { _speed = speed; }
