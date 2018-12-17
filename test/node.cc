#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(NodeTest, ConversionOperatorTest) {
  Fenwick<int> tree = Fenwick<int>(10);

  int node = tree[0];
}

}
