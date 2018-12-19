#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(NodeTest, At) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree.at(0);
}

TEST(NodeTest, AtWithConst) {
  const Fenwick<int> tree = Fenwick<int>(10);

  tree.at(0);
}

TEST(NodeTest, Conversion) {
  Fenwick<int> tree = Fenwick<int>(10);

  int node = tree[0];
}

TEST(NodeTest, ConversionWithConst) {
  const Fenwick<int> tree = Fenwick<int>(10);

  int node = tree[0];
}

TEST(NodeTest, Suffix) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0];
}

TEST(NodeTest, SuffixWithConst) {
  const Fenwick<int> tree = Fenwick<int>(10);

  tree[0];
}

TEST(NodeTest, Comparison) {
  const Fenwick<int> tree = Fenwick<int>(10);

  ASSERT_EQ(tree[0], tree[1]);
}

}
