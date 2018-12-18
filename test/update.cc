#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(UpdateTest, Increment) {
  Fenwick<int> tree = Fenwick<int>(10);

  tree[0] += 1;

  ASSERT_EQ(static_cast<int>(tree[0]), 1);
}

}
