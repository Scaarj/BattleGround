#include "pch.h"

#include "engine/unit/monster/minotaur.h"

using namespace engine::unit::monster;
using namespace engine::math;

TEST(Minotaur, DefaultPosition) {
  Minotaur minotaur;
  ASSERT_EQ(minotaur.position(), Vector2d(0, 0));
}

TEST(Minotaur, Idle) {
  Minotaur minotaur;
  minotaur.timeTick(1);
}

TEST(Minotaur, WalkOneSecond) {
  Minotaur minotaur;
  minotaur.setDirection(Vector2d(1, 0));
  minotaur.walk();
  ASSERT_EQ(minotaur.position(), Vector2d(0, 0));
  minotaur.timeTick(1);
  ASSERT_EQ(minotaur.position(), Vector2d(20, 0));
}

TEST(Minotaur, WalkOneSecondTwoTime) {
  Minotaur minotaur;
  minotaur.setDirection(Vector2d(1, 0));
  minotaur.walk();
  ASSERT_EQ(minotaur.position(), Vector2d(0, 0));
  minotaur.timeTick(1);
  minotaur.timeTick(1);
  ASSERT_EQ(minotaur.position(), Vector2d(40, 0));
}

TEST(Minotaur, WalkOneSecondStayOneSeconnd) {
  Minotaur minotaur;

  minotaur.setDirection(Vector2d(1, 0));
  minotaur.walk();
  ASSERT_EQ(minotaur.position(), Vector2d(0, 0));
  minotaur.timeTick(1);
  ASSERT_EQ(minotaur.position(), Vector2d(20, 0));
  minotaur.stay();
  minotaur.timeTick(1);
  ASSERT_EQ(minotaur.position(), Vector2d(20, 0));
}
