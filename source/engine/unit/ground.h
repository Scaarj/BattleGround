#pragma once

#include "actions/idle.h"
#include "actions/walk.h"
#include "unit.h"

namespace engine::unit {
class Ground {
 public:
  Ground(Unit* unit);
  void walk();
  void stay();
  void setSpeed(float speed);

 public:
  actions::Walk actionWalk;
  actions::Idle* actionIdle;
};

}  // namespace engine::unit
