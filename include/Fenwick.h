#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

namespace Fenwick {

template <class T>
class Fenwick {
private:
  class Node;

public:
  typedef T value_type ;
  typedef value_type & reference;
  typedef const value_type & const_reference;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  Fenwick() { }
  Fenwick(size_type size) {
    resize(size);
  };

  void resize(size_type size) {
    data_.resize(size);
    tree_.resize(size);
    size_ = size;
  }

  size_type size () const {
    return size_;
  }

  value_type sum(size_type n) const;

  Node operator[](size_type idx) {
    return Node(*this, idx);
  }

  const_reference operator[](size_type idx) const {
    return data_[idx];
  }

  Node at(size_type idx) {
    check_out_of_range(idx);
    return (*this)[idx];
  }

  const_reference at(size_type idx) const {
    check_out_of_range(idx);
    return (*this)[idx];
  }

private:
  class Node {
    public:
      Node(Fenwick &tree, size_type idx) : tree_(tree), idx_(idx) { }

      operator value_type() const {
        return tree_.data_[idx_];
      }

      Node & operator+=(const_reference delta) {
        tree_.update(idx_, delta);
        return *this;
      }

      Node & operator=(const_reference value) {
        value_type delta = value - tree_.data_[idx_];

        return operator+=(delta);
      }

    private:
      Fenwick &tree_;
      const size_type idx_;
  };

  std::vector<value_type> data_;
  std::vector<value_type> tree_;

  size_type size_;

  void update(size_type idx, const_reference delta);
  void update_tree(size_type idx, const_reference delta);

  void check_out_of_range(size_type idx) const;

  friend class Node;
};

template<class T>
void Fenwick<T>::update(size_type idx, const_reference delta) {
  data_[idx] += delta;

  update_tree(idx + 1, delta);
}

template<class T>
void Fenwick<T>::update_tree(size_type idx, const_reference delta) {
  if (idx >= size_) {
    return;
  }

  tree_[idx - 1] += delta;

  idx = idx + (idx & (-idx));

  update_tree(idx, delta);
}

template<class T>
typename Fenwick<T>::value_type
Fenwick<T>::sum(size_type n) const {
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

template<class T>
void Fenwick<T>::check_out_of_range(size_type idx) const {
  if (idx >= size_) {
    throw std::out_of_range("Fenwick: out of range");
  }
}

}

#endif // FENWICK_H
