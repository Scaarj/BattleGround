#pragma once

#include "../ground.h"
#include "../unit.h"

namespace engine::unit::monster {
class Troll : public Unit, public Ground {
 public:
  Troll();
};
}  // namespace engine::unit::monster
