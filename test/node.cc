#include "gtest/gtest.h"
#include "Fenwick.h"

TEST(NodeTest, IndexOperatorTest) {
  Fenwick<int> tree = Fenwick<int>(10);

  Fenwick<int>::Node node = tree[0];
}
