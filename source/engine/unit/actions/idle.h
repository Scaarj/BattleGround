#pragma once

#include "../action.h"

namespace engine::unit::actions {
class Idle : public Action {
 public:
  Idle(Unit* unit);
  virtual void timeTick(float time);
};
}  // namespace engine::unit::actions
