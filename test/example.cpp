#include "pch.h"

#include "basicunit.h"

TEST(Example, OnePlusOne) { ASSERT_EQ(1 + 1, 2); }

TEST(BasicUnit, IsReady) {
  BasicUnit obj;
  ASSERT_TRUE(obj.isReady());
}
