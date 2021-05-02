#include "objectsize.h"

using namespace engine;

Hitbox engine::ObjectSize::getHitbox(engine::ObjectSize::SizeType type) {
  switch (type) {
    case SizeType::Projectile:
      return Hitbox(10, 10);
      break;
    case SizeType::Small:
      return Hitbox(25, 50);
      break;
    case SizeType::Medium:
      return Hitbox(50, 100);
      break;
    case SizeType::Big:
      return Hitbox(100, 200);
      break;
    default:
      break;
  }

  return Hitbox(50, 100);
}
