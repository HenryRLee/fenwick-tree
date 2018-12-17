#include "gtest/gtest.h"
#include "Fenwick.h"

TEST(UpdateTest, IncrementTest) {
  Fenwick<int> tree = Fenwick<int>(10);

  Fenwick<int>::Node node = tree[0];

  node += 1;

  ASSERT_EQ(static_cast<int>(node), 1);
}

