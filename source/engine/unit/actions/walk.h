#pragma once

#include "../../math/vector2d.h"
#include "../action.h"

namespace engine::unit::actions {
class Walk : public Action {
 public:
  Walk(Unit* unit);
  virtual void timeTick(float time) override;
  float speed() const;
  void setSpeed(float speed);

 private:
  float _speed;
};
}  // namespace engine::unit::actions
