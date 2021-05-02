#include "pch.h"

#include "engine/math/vector2d.h"

using namespace engine::math;

TEST(Vector2d, TwoZeroVectorEqual) {
  ASSERT_EQ(Vector2d(0, 0), Vector2d(0, 0));
}

TEST(Vector2d, TwoSameVectorEqual) {
  ASSERT_EQ(Vector2d(10, 20), Vector2d(10, 20));
}

TEST(Vector2d, TwoNoneSameVectorNotEqual) {
  ASSERT_NE(Vector2d(10, 20), Vector2d(20, 10));
}

TEST(Vector2d, SumTwoZeroVectorEqualZero) {
  Vector2d vector1(0, 0);
  Vector2d vector2(0, 0);
  ASSERT_EQ(Vector2d(0, 0), Vector2d(0, 0));
}

TEST(Vector2d, SumVector) {
  Vector2d vector1(10, 5);
  Vector2d vector2(20, 7);
  ASSERT_EQ(vector1 + vector2, Vector2d(30, 12));
}
