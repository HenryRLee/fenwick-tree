#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(ConstructorTest, DefaultConstructor) {
  fenwick<int> tree = fenwick<int>();
}

TEST(ConstructorTest, ConstructorWithSize) {
  fenwick<int> tree = fenwick<int>(10);
}

TEST(ConstructorTest, ConstructorWithSizeAndVal) {
  fenwick<int> tree = fenwick<int>(10, 5);

  for (auto it = tree.begin(); it != tree.end(); it++) {
    ASSERT_EQ(*it, 5);
  }
}

}
