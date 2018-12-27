#include "gtest/gtest.h"
#include "fenwick.h"

namespace fenwick {

TEST(NodeTest, At) {
  fenwick<int> tree = fenwick<int>(10);

  tree.at(0);
}

TEST(NodeTest, AtWithConst) {
  const fenwick<int> tree = fenwick<int>(10);

  tree.at(0);
}

TEST(NodeTest, Conversion) {
  fenwick<int> tree = fenwick<int>(10);

  int node = tree[0];
}

TEST(NodeTest, ConversionWithConst) {
  const fenwick<int> tree = fenwick<int>(10);

  int node = tree[0];
}

TEST(NodeTest, Suffix) {
  fenwick<int> tree = fenwick<int>(10);

  tree[0];
}

TEST(NodeTest, SuffixWithConst) {
  const fenwick<int> tree = fenwick<int>(10);

  tree[0];
}

TEST(NodeTest, Comparison) {
  const fenwick<int> tree = fenwick<int>(10);

  ASSERT_EQ(tree[0], tree[1]);
}

}
