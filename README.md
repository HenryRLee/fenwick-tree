# FenwickTree
A C++ Fenwick Tree Library

### Why Fenwick Tree
A Fenwick Tree, also known as binary indexed tree, is a data structure that can efficiently update elements and calculate the sum of a range of consecutive numbers, originally proposed by Peter Fenwick in 1994.

If we want to query the sum of a range of consecutive numbers in an array, normally it will take O(n) time on average, by adding the numbers up. Alternatively, we can add another array saving the prefix sum, hence the query can be done in O(1) time, but updating the elements becomes an O(n) operation.

Fenwick tree is a simple data structure to solve the problem. It balances both the sum query and element update operations, performing no worse than O(logn) time.

### Features
This library provides public members similar to the `std::vector`, and updating the elements can be done through updating the lvalues from `[]` operators or (potentially) iterators. So it works like an extension of `std::vector`, with only one additional public function, which is a series of `sum` functions, to query the sum of a range in the vector.

### Examples
Initialize the tree with a default value, and iterate the tree

```
// initialize an array with 5 elements, setting their values to 10
fenwick<int> array(5, 10);

for (auto it = array.begin(); it != array.end(); it++) {
  assert(*it == 10);
}
```

Update elements using the suffix operator, and get the sum of a particular range.

```cpp
fenwick::fenwick<int> array(5); // initiate an array with 5 elements

array[0] = 1;
array[1] = 3;
array[2] = 5;
array[3] = 7;
array[5] = 9;

assert(array.sum(3) == 9); // the sum of the first three elements
assert(array.sum(1, 4) == 15); // the sum of the range [1, 4)
```

### Use of library
The library is a single header file library. Simply copy the header file `fenwick.h` and include it in your source file.

### Unit test
The unit test is based on Google Test, which requires CMake to compile.

Run `cmake .` on the repository, this will generate a unit test program `unit_test`. Then run the program `./unit_test` to test the result.

