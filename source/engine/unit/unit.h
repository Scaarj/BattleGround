#pragma once

#include "../object.h"
#include "types.h"

namespace engine::unit {
class Unit : public Object {
 public:
  Unit(ObjectSize::SizeType, Type);
  virtual ~Unit();
  Type type() const;

  math::Vector2d position() const;
  void setPosition(const math::Vector2d& position);
  math::Vector2d direction() const;
  void setDirection(const math::Vector2d& direction);
  void timeTick(float time);
  void startAction(void* action);
  void stopAction(void* action);

 protected:
  Type _type;
  math::Vector2d _position;
  math::Vector2d _direction;
  void* _currentAction;
  void* _idleAction;
};
}  // namespace engine::unit
