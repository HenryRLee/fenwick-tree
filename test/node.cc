#include "gtest/gtest.h"
#include "Fenwick.h"

TEST(NodeTest, IndexOperatorTest) {
  Fenwick<int> tree = Fenwick<int>(10);

  Fenwick<int>::Node node = tree[0];
}

TEST(NodeTest, ConversionOperatorTest) {
  Fenwick<int> tree = Fenwick<int>(10);

  int node = tree[0];
}
