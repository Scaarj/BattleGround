#include "troll.h"

using namespace engine::unit::monster;

Troll::Troll()
    : Unit(ObjectSize::SizeType::Medium, Type::Monster), Ground(this) {
  setSpeed(10);
}
