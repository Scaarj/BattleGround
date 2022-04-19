#include "pch.h"

#include "basicunit.h"

#include "world.h"

TEST(Example, OnePlusOne) { ASSERT_EQ(1 + 1, 2); }

TEST(World, Init) {
  World world;
  world.init();
}

TEST(World, CreateOnLeftClock) {
  World world;
  world.createOnLeftClick(0, 0);
}

TEST(World, CreateOnRightClock) {
  World world;
  world.createOnRightClick(0, 0);
}
