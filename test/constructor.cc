#include "gtest/gtest.h"
#include "Fenwick.h"

namespace Fenwick {

TEST(ConstructorTest, DefaultConstructor) {
  Fenwick<int> tree = Fenwick<int>();
}

TEST(ConstructorTest, ConstructorWithSize) {
  Fenwick<int> tree = Fenwick<int>(10);
}

}
