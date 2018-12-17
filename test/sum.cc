#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(SumTest, OneElement) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] += 1;

  ASSERT_EQ(static_cast<int>(tree.sum(1)), 1);
}

TEST(SumTest, ThreeElements) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] += 1;
  tree[1] += 5;
  tree[2] += 9;

  ASSERT_EQ(static_cast<int>(tree.sum(3)), 15);
}

TEST(SumTest, ThreeElementsWithNegativeNumber) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] += 1;
  tree[1] += -9;
  tree[2] += 5;

  ASSERT_EQ(static_cast<int>(tree.sum(3)), -3);
}

}
