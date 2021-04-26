#include "pch.h"
#include "sum.h"

TEST(Example, OnePlusOne) { ASSERT_EQ(1 + 1, 2); }

TEST(ExampleSum, OnePlusOne) { ASSERT_EQ(sum(1, 2), 3); }

