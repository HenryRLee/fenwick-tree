#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(ConstructorTest, DefaultConstructor) {
  fenwick<int> tree = fenwick<int>();
}

TEST(ConstructorTest, ConstructorWithSize) {
  fenwick<int> tree = fenwick<int>(10);
}

}
