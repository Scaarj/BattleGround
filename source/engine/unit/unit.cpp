#include "unit.h"
#include "action.h"
#include "actions/gethit.h"
#include "actions/idle.h"

using namespace engine::unit;
using namespace engine::math;

Unit::Unit(ObjectSize::SizeType size, Type type) : Object(size), _type(type) {
  _idleAction = new actions::Idle(this);
  _currentAction = _idleAction;
}

Unit::~Unit() {
  if (_idleAction) {
    delete (Action *)_idleAction;
    _idleAction = nullptr;
  }
  _currentAction = nullptr;
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

void Unit::startAction(void *action) {
  if (_currentAction == _idleAction) {
    _currentAction = action;
  } else {
    Action *action = (Action *)_currentAction;
    if (action->interruptible()) {
      _currentAction = action;
    }
  }
}

void Unit::stopAction(void *action) {
  if (_currentAction == action) {
    _currentAction = _idleAction;
  }
}
