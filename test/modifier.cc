#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(ModifierTest, Assign) {
  fenwick<int> tree(10);

  tree.assign(5, 20);
  ASSERT_EQ(tree.size(), 5);
  ASSERT_EQ(tree.front(), 20);
  ASSERT_EQ(tree.back(), 20);
  ASSERT_EQ(tree.sum(5), 100);

  tree.assign(20, 10);
  ASSERT_EQ(tree.front(), 10);
  ASSERT_EQ(tree.back(), 10);
  ASSERT_EQ(tree.sum(20), 200);

  tree.assign(10, 50);
  ASSERT_EQ(tree.front(), 50);
  ASSERT_EQ(tree.back(), 50);
  ASSERT_EQ(tree.sum(10), 500);
}

TEST(ModifierTest, PushBack) {
  fenwick<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.push_back(i);
  }

  ASSERT_EQ(tree.size(), 10);
  ASSERT_EQ(tree.front(), 0);
  ASSERT_EQ(tree.back(), 9);
  ASSERT_EQ(tree.sum(10), 45);
}

}
