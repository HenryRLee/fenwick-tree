#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(UpdateTest, Increment) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] += 1;

  ASSERT_EQ(static_cast<int>(tree[0]), 1);
}

TEST(UpdateTest, Decrement) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] -= 3;

  ASSERT_EQ(static_cast<int>(tree[0]), -3);
}

TEST(UpdateTest, Assign) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] = 2;

  ASSERT_EQ(static_cast<int>(tree[0]), 2);
}

}
