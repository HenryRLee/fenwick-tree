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
  class lvalue_type;
  template<typename Reference> class iterator_type;

 public:
  /*
   * Member types
   */
  typedef T value_type;
  typedef Alloc allocator_type;
  typedef lvalue_type reference;
  typedef const value_type& const_reference;
  typedef typename std::allocator_traits<allocator_type>::const_pointer pointer;
  typedef typename std::allocator_traits<allocator_type>::const_pointer const_pointer;
  typedef iterator_type<reference> iterator;
  typedef iterator_type<const_reference> const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  /*
   * Constructors
   */
  fenwick() { clear(); }

  fenwick(size_type size, const value_type& val = value_type()) {
    resize(size, val);
  };

  /*
   * Iterators
   */
  iterator begin() noexcept { return iterator(*this, 0); };
  const_iterator begin() const noexcept { return const_iterator(*this, 0); };

  iterator end() noexcept { return iterator(*this, size_); };
  const_iterator end() const noexcept { return const_iterator(*this, size_); };

  const_iterator cbegin() const noexcept { return begin(); }
  const_iterator cend() const noexcept { return end(); }

  reverse_iterator rbegin() noexcept { return reverse_iterator(end()); };
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(cend());
  };

  reverse_iterator rend() noexcept { return reverse_iterator(begin()); };
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(cbegin());
  };

  const_reverse_iterator crbegin() const noexcept { return rbegin(); }
  const_reverse_iterator crend() const noexcept { return rend(); }

  /*
   * Capacity
   */
  void resize(size_type size) {
    resize(size, value_type());
  }

  void resize(size_type size, const value_type& val);

  size_type size() const { return size_; }
  size_type capacity() const { return capacity_; }

  /*
   * Sum
   */
  value_type sum(size_type n) const;
  value_type sum(size_type first, size_type last) const;

  /*
   * Element access
   */
  reference operator[](size_type idx) { return lvalue_type(*this, idx); }

  const_reference operator[](size_type idx) const { return data_[idx]; }

  reference at(size_type idx) {
    check_out_of_range(idx);
    return (*this)[idx];
  }

  const_reference at(size_type idx) const {
    check_out_of_range(idx);
    return (*this)[idx];
  }

  void clear() noexcept {
    size_ = 0;
    capacity_ = 0;
    data_.clear();
    tree_.clear();
  };

  /*
   * Allocator
   */
  allocator_type get_allocator() const {
    return allocator_type();
  }

 private:
  class lvalue_type {
   public:
    lvalue_type(fenwick& tree, size_type idx) : tree_(tree), idx_(idx) {}

    operator value_type() const { return tree_.data_[idx_]; }

    lvalue_type& operator+=(const_reference delta) {
      tree_.update(idx_, delta);
      return *this;
    }

    lvalue_type& operator-=(const_reference delta) {
      tree_.update(idx_, -delta);
      return *this;
    }

    lvalue_type& operator=(const_reference value) {
      value_type delta = value - tree_.data_[idx_];
      return operator+=(delta);
    }

   private:
    fenwick& tree_;
    const size_type idx_;
  };

  template<typename Reference>
  class iterator_type {
   public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef value_type value_type;
    typedef difference_type difference_type;
    typedef Reference reference;
    typedef pointer pointer;

    iterator_type() {}

    reference operator*() const {
      return tree_->at(idx_);
    }

    pointer operator->() const {
      return &(static_cast<const fenwick *>(tree_)->at(idx_));
    }

    iterator_type& operator++() {
      ++idx_;
      return *this;
    }

    iterator_type operator++(int) {
      iterator_type tmp(*this);
      ++idx_;
      return tmp;
    }

    iterator_type& operator--() {
      --idx_;
      return *this;
    }

    iterator_type operator--(int) {
      iterator_type tmp(*this);
      --idx_;
      return tmp;
    }

    template<typename Tp>
    bool operator==(const iterator_type<Tp>& other) {
      return tree_ == other.tree_ && idx_ == other.idx_;
    }

    template<typename Tp>
    bool operator!=(const iterator_type<Tp>& other) {
      return !operator==(other);
    }

   private:
    typedef typename std::conditional<
        std::is_const<typename std::remove_reference<reference>::type>::value,
        const fenwick&, fenwick&>::type tree_reference;
    typedef typename std::conditional<
        std::is_const<typename std::remove_reference<reference>::type>::value,
        const fenwick*, fenwick*>::type tree_pointer;

    tree_pointer tree_;
    size_type idx_;

    iterator_type(tree_reference tree, size_type idx) : tree_(&tree), idx_(idx) {}

    friend class fenwick<T, Alloc>;
  };

  std::vector<value_type, allocator_type> data_;
  std::vector<value_type, allocator_type> tree_;

  size_type size_ = 0;
  size_type capacity_ = 0;

  void update(size_type idx, const_reference delta);
  void update_tree(size_type idx, const_reference delta);

  void check_out_of_range(size_type idx) const;

  friend class lvalue_type;
};

template<class T, class Alloc>
void fenwick<T, Alloc>::resize(size_type size, const value_type& val) {
  size_type original_size = size_;

  size_ = size;
  data_.resize(size, val);

  if (size > capacity_) {
    /*
     * If the container is expanding, the tree needs to be recalcuated.
     */
    capacity_ = size;
    tree_.clear();
    tree_.resize(size);
    for (size_type i = 0; i < original_size; i++) {
      /*
       * Because updating the tree requires the delta, so the value of
       * data_[i] needs to be reset before the update.
       */
      value_type tmp = value_type();
      std::swap(tmp, data_[i]);
      operator[](i) = tmp;
    }
    for (size_type i = original_size; i < size; i++) {
      /*
       * Because updating the tree requires the delta, so the value of
       * data_[i] needs to be reset before the update.
       */
      value_type tmp = value_type();
      std::swap(tmp, data_[i]);
      operator[](i) = tmp;
    }
  }
}

template<class T, class Alloc>
void fenwick<T, Alloc>::update(size_type idx, const_reference delta) {
  data_[idx] += delta;

  update_tree(idx + 1, delta);
}

template<class T, class Alloc>
void fenwick<T, Alloc>::update_tree(size_type idx, const_reference delta) {
  if (idx > capacity_) {
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
typename fenwick<T, Alloc>::value_type
fenwick<T, Alloc>::sum(size_type first, size_type last) const {
  return sum(last) - sum(first);
}

template<class T, class Alloc>
void fenwick<T, Alloc>::check_out_of_range(size_type idx) const {
  if (idx >= size_) {
    throw std::out_of_range("fenwick: index out of range");
  }
}

}

#endif // FENWICK_H
