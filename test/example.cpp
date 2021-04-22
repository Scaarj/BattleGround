#include "pch.h"

#include "Sum.h"

TEST(Example, OnePlusOne) {
    ASSERT_EQ(1 + 1, 2);
}

TEST(Example, Sum) {
    ASSERT_EQ(sum(1, 5), 6);
}
