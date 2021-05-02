#include "pch.h"

#include "engine/unit/monster/troll.h"

using namespace engine::unit::monster;
using namespace engine::math;

TEST(Troll, DefaultPosition) {
  Troll troll;
  ASSERT_EQ(troll.position(), Vector2d(0, 0));
}

TEST(Troll, Walk1Second) {
  Troll troll;
  troll.setDirection(Vector2d(1, 0));
  troll.walk();
  ASSERT_EQ(troll.position(), Vector2d(0, 0));
  troll.timeTick(1);
  ASSERT_EQ(troll.position(), Vector2d(10, 0));
}
