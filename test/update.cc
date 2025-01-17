#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(UpdateTest, Increment) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] += 1;
  ASSERT_EQ(tree[0], 1);

  tree[1] += 2;
  ASSERT_EQ(tree[1], 2);

  tree[2] += -1;
  ASSERT_EQ(tree[2], -1);

  ASSERT_EQ(tree.sum(1), 1);
  ASSERT_EQ(tree.sum(2), 3);
  ASSERT_EQ(tree.sum(3), 2);
}

TEST(UpdateTest, Decrement) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] -= 3;
  ASSERT_EQ(tree[0], -3);

  tree[1] -= -2;
  ASSERT_EQ(tree[1], 2);

  tree[2] -= 4;
  ASSERT_EQ(tree[2], -4);

  ASSERT_EQ(tree.sum(1), -3);
  ASSERT_EQ(tree.sum(2), -1);
  ASSERT_EQ(tree.sum(3), -5);
}

TEST(UpdateTest, Assign) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0] = 1;
  ASSERT_EQ(tree[0], 1);

  tree[1] = 2;
  ASSERT_EQ(tree[1], 2);

  tree[2] = -7;
  ASSERT_EQ(tree[2], -7);

  ASSERT_EQ(tree.sum(1), 1);
  ASSERT_EQ(tree.sum(2), 3);
  ASSERT_EQ(tree.sum(3), -4);
}

}
