#include "pch.h"

#include "basicunit.h"

#include "world.h"

TEST(Example, Case2) {
  World world;
  world.onTick();
}

TEST(Example, OnePlusOne) { ASSERT_EQ(1 + 1, 2); }
