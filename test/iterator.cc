#include "gtest/gtest.h"
#include "fenwick/fenwick.h"

namespace fenwick {

TEST(IteratorTest, BeginEnd) {
  fenwick<int> tree = fenwick<int>(10);

  fenwick<int>::iterator it;
  it = tree.begin();
  it = tree.end();

  fenwick<int>::const_iterator cit;
  cit = tree.cbegin();
  cit = tree.cend();

  fenwick<int>::reverse_iterator rit;
  rit = tree.rbegin();
  rit = tree.rend();

  fenwick<int>::const_reverse_iterator crit;
  crit = tree.crbegin();
  crit = tree.crend();
}

TEST(IteratorTest, Iterate) {
  fenwick<int> tree = fenwick<int>(5);

  for (int i = 0; i < 5; i++) {
    tree[i] = i;
  }

  int c = 0;
  for (auto it = tree.begin(); it != tree.end(); it++, c++) {
    ASSERT_EQ(c, *it);
  }

  c = 0;
  for (auto it = tree.cbegin(); it != tree.cend(); it++, c++) {
    ASSERT_EQ(c, *it);
  }

  ASSERT_EQ(4, *tree.rbegin());
  c = 4;
  for (auto it = tree.rbegin(); it != tree.rend(); it++, c--) {
    ASSERT_EQ(c, *it);
  }

  c = 4;
  for (auto it = tree.crbegin(); it != tree.crend(); it++, c--) {
    ASSERT_EQ(c, *it);
  }
}

TEST(IteratorTest, Update) {
  fenwick<int> tree = fenwick<int>(5);

  for (int i = 0; i < 5; i++) {
    tree[i] = i;
  }

  auto it = tree.begin();

  *it = 7;
  *++it = 6;

  // 7, 6, 2, 3, 4

  ASSERT_EQ(tree.front(), 7);
  ASSERT_EQ(tree[1], 6);
  ASSERT_EQ(tree.sum(3), 15); // 7 + 6 + 2
}

struct Data {
  int data;
  Data() {}
  Data(int data) : data(data) {}

  Data& operator+=(const Data& other) {
    data += other.data;
    return *this;
  }

  Data& operator-=(const Data& other) {
    data -= other.data;
    return *this;
  }

  Data operator+(const Data& other) const {
    return Data(*this) += other;
  }

  Data operator-(const Data& other) const {
    return Data(*this) -= other;
  }
};

TEST(IteratorTest, Pointer) {
  fenwick<struct Data> tree = fenwick<struct Data>(5);

  for (int i = 0; i < 5; i++) {
    tree[i] = Data(i);
  }

  int c = 0;
  for (auto it = tree.begin(); it != tree.end(); it++, c++) {
    ASSERT_EQ(it->data, c);
  }

  c = 0;
  for (auto it = tree.cbegin(); it != tree.cend(); it++, c++) {
    ASSERT_EQ(it->data, c);
  }
}

}
