#pragma once

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
};

}  // namespace engine::unit
