/*
 * MIT License
 * 
 * Copyright (c) 2018 Henry Lee
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

namespace fenwick {

template <class T, class Alloc = std::allocator<T>>
class fenwick {
private:
  class node;

public:
  /*
   * Member types
   */
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename std::allocator_traits<allocator_type>::pointer pointer;
  typedef typename std::allocator_traits<allocator_type>::const_pointer const_pointer;
  typedef typename std::vector<value_type, allocator_type>::iterator iterator;
  typedef typename std::vector<value_type, allocator_type>::const_iterator const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  /*
   * Constructors
   */
  fenwick() { }

  fenwick(size_type size) {
    resize(size);
  };

  /*
   * Capacity
   */
  void resize(size_type size) {
    data_.resize(size);
    tree_.resize(size);
    size_ = size;
  }

  size_type size() const {
    return size_;
  }

  /*
   * Sum
   */
  value_type sum(size_type n) const;

  /*
   * Element access
   */
  node operator[](size_type idx) {
    return node(*this, idx);
  }

  const_reference operator[](size_type idx) const {
    return data_[idx];
  }

  node at(size_type idx) {
    check_out_of_range(idx);
    return (*this)[idx];
  }

  const_reference at(size_type idx) const {
    check_out_of_range(idx);
    return (*this)[idx];
  }

  /*
   * Allocator
   */
  allocator_type get_allocator() const {
    return allocator_type();
  }

private:
  class node {
    public:
      node(fenwick& tree, size_type idx) : tree_(tree), idx_(idx) { }

      operator value_type() const {
        return tree_.data_[idx_];
      }

      node& operator+=(const_reference delta) {
        tree_.update(idx_, delta);
        return *this;
      }

      node& operator-=(const_reference delta) {
        tree_.update(idx_, -delta);
        return *this;
      }

      node& operator=(const_reference value) {
        value_type delta = value - tree_.data_[idx_];
        return operator+=(delta);
      }

    private:
      fenwick& tree_;
      const size_type idx_;
  };

  std::vector<value_type, allocator_type> data_;
  std::vector<value_type, allocator_type> tree_;

  size_type size_;

  void update(size_type idx, const_reference delta);
  void update_tree(size_type idx, const_reference delta);

  void check_out_of_range(size_type idx) const;

  friend class node;
};

template<class T, class Alloc>
void fenwick<T, Alloc>::update(size_type idx, const_reference delta) {
  data_[idx] += delta;

  update_tree(idx + 1, delta);
}

template<class T, class Alloc>
void fenwick<T, Alloc>::update_tree(size_type idx, const_reference delta) {
  if (idx >= size_) {
    return;
  }

  tree_[idx - 1] += delta;

  idx = idx + (idx & (-idx));

  update_tree(idx, delta);
}

template<class T, class Alloc>
typename fenwick<T, Alloc>::value_type
fenwick<T, Alloc>::sum(size_type n) const {
  value_type ret = 0;

  if (n > size_) {
    n = size_;
  }

  while (n > 0) {
    ret += tree_[n - 1];
    n = n - (n & (-n));
  }

  return ret;
}

template<class T, class Alloc>
void fenwick<T, Alloc>::check_out_of_range(size_type idx) const {
  if (idx >= size_) {
    throw std::out_of_range("fenwick: index out of range");
  }
}

}

#endif // FENWICK_H
