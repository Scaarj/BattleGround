#pragma once

#include "math/vector2d.h"
#include "objectsize.h"

namespace engine {
class Object {
 public:
  Object(ObjectSize::SizeType);

 private:
  Hitbox _hitBox;
};
}  // namespace engine
