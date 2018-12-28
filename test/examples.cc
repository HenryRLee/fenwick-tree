#include "gtest/gtest.h"
#include "fenwick.h"
#include <iostream>

TEST(Examples, ExampleOne) {
  fenwick::fenwick<int> array(5); // initiate an array with 5 elements

  array[0] = 1;
  array[1] = 3;
  array[2] = 5;
  array[3] = 7;
  array[5] = 9;

  ASSERT_EQ(array.sum(3), 9); // the sum of the first three elements
  ASSERT_EQ(array.sum(1, 4), 15); // the sum of the range [1, 4)
}
