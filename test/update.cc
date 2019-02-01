#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(UpdateTest, Increment) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] += 1;

  ASSERT_EQ(tree[0], 1);
}

TEST(UpdateTest, Decrement) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] -= 3;

  ASSERT_EQ(tree[0], -3);
}

TEST(UpdateTest, Assign) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] = 2;

  ASSERT_EQ(tree[0], 2);
}

}
