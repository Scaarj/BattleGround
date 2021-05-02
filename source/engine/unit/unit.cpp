#include "unit.h"
#include "action.h"
#include "actions/gethit.h"
#include "actions/idle.h"

using namespace engine::unit;
using namespace engine::math;

Unit::Unit(ObjectSize::SizeType size, Type type) : Object(size), _type(type) {
  _idleAction = new actions::Idle(this);
  _currentAction = _idleAction;
  _nextAction = nullptr;
}

Unit::~Unit() {
  if (_idleAction) {
    delete (Action *)_idleAction;
    _idleAction = nullptr;
  }
  _currentAction = nullptr;
  _nextAction = nullptr;
}

Type Unit::type() const { return _type; }

Vector2d Unit::position() const { return _position; }

void Unit::setPosition(const Vector2d &position) { _position = position; }

Vector2d Unit::direction() const { return _direction; }

void Unit::setDirection(const Vector2d &direction) { _direction = direction; }

void Unit::timeTick(float time) {
  if (_currentAction) {
    ((Action *)_currentAction)->timeTick(time);
  }
}

void *Unit::currentAction() const { return _currentAction; }

void Unit::setCurrentAction(void *currentAction) {
  _currentAction = currentAction;
}

void *Unit::nextAction() const { return _nextAction; }

void Unit::setNextAction(void *nextAction) { _nextAction = nextAction; }

void *Unit::idleAction() const { return _idleAction; }
