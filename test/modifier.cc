#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(ModifierTest, Assign) {
  fenwick<int> tree(10);

  tree.assign(5, 20);
  ASSERT_EQ(tree.size(), 5);
  ASSERT_EQ(tree[0], 20);
  ASSERT_EQ(tree[4], 20);
  ASSERT_EQ(tree.sum(5), 100);

  tree.assign(20, 10);
  ASSERT_EQ(tree[0], 10);
  ASSERT_EQ(tree[19], 10);
  ASSERT_EQ(tree.sum(20), 200);

  tree.assign(10, 50);
  ASSERT_EQ(tree[0], 50);
  ASSERT_EQ(tree[9], 50);
  ASSERT_EQ(tree.sum(10), 500);
}

}
