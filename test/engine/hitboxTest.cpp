#include "pch.h"

#include "engine/hitbox.h"

using namespace engine;

TEST(Hitbox, TwoHitboxCollisionInOrigin) {
  Hitbox obj1(10, 10), obj2(10, 10);
  bool isCollided = obj1.isCollided(obj2);
  ASSERT_TRUE(isCollided);
}

TEST(Hitbox, TwoHitboxNotCollisionInDifferenPosition) {
  Hitbox obj1(10, 10), obj2(10, 10);
  obj1.moveTo(0, 0);
  obj2.moveTo(100, 100);
  bool isCollided = obj1.isCollided(obj2);
  ASSERT_FALSE(isCollided);
}
