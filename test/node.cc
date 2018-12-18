#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(NodeTest, ConversionOperator) {
  Fenwick<int> tree = Fenwick<int>(10);

  int node = tree[0];
}

TEST(NodeTest, Const) {
  const Fenwick<int> tree = Fenwick<int>(10);

  tree[0];
}

}
