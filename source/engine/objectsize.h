#pragma once

#include "hitbox.h"

namespace engine {
class ObjectSize {
 public:
  enum class SizeType { Projectile, Small, Medium, Big, Special };

 public:
  static Hitbox getHitbox(SizeType);
};
}  // namespace engine
