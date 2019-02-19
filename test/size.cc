#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(SizeTest, Zero) {
  fenwick<int> tree;

  ASSERT_EQ(tree.size(), 0);
  ASSERT_GE(tree.capacity(), 0);
}

TEST(SizeTest, Static) {
  fenwick<int> tree(10);

  ASSERT_EQ(tree.size(), 10);
  ASSERT_GE(tree.capacity(), 10);
}

TEST(SizeTest, Resize) {
  fenwick<int> tree;

  tree.resize(10);

  ASSERT_EQ(tree.size(), 10);
  ASSERT_GE(tree.capacity(), 10);

  tree[9] = 10;
  ASSERT_EQ(tree.sum(10), 10);

  tree.resize(20);

  ASSERT_EQ(tree.size(), 20);
  ASSERT_GE(tree.capacity(), 20);

  tree[19] = 10;
  ASSERT_EQ(tree[9], 10);
  ASSERT_EQ(tree[19], 10);
  ASSERT_EQ(tree.sum(10), 10);
  ASSERT_EQ(tree.sum(10, 20), 10);
  ASSERT_EQ(tree.sum(20), 20);

  tree.resize(5);

  ASSERT_EQ(tree.size(), 5);
  ASSERT_GE(tree.capacity(), 5);

  tree[4] = 5;
  ASSERT_EQ(tree.sum(5), 5);
}

}
