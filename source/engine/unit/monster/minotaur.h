#pragma once

#include "../ground.h"
#include "../unit.h"

namespace engine::unit::monster {
class Minotaur : public Unit, public Ground {
 public:
  Minotaur();
};
}  // namespace engine::unit::monster
