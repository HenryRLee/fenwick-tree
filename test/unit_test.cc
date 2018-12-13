#include "gtest/gtest.h"
#include "Fenwick.h"

TEST(ConstructorTest, DefaultConstructorTest) {
  Fenwick<int> tree = Fenwick<int>();
}
