#include "minotaur.h"

using namespace engine::unit::monster;

Minotaur::Minotaur()
    : Unit(ObjectSize::SizeType::Medium, Type::Monster), Ground(this) {
  setSpeed(20);
}
