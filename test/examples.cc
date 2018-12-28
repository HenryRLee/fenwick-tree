#include "gtest/gtest.h"
#include "fenwick.h"
#include <iostream>

namespace fenwick {

TEST(Examples, ExampleOne) {
  fenwick<int> array(3); // initiate an array with 3 elements

  array[0] = 1;
  array[1] = 3;
  array[2] = 5;

  ASSERT_EQ(array.sum(3), 9); // the sum of the first three elements
}

}
