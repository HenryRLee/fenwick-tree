#include <vector>

template <class T>
class Fenwick {
private:
  class Node;

public:
  typedef T value_type ;
  typedef value_type & reference;
  typedef const value_type & const_reference;

  Fenwick() { }
  Fenwick(int size) { resize(size); };

  void resize(int size) {
    data_.resize(size);
    tree_.resize(size);
    size_ = size;
  }

  int size () const {
    return size_;
  }

  Node operator[] (int idx) {
    if (idx < 0 || idx >= size_) {
      throw std::out_of_range("Fenwick: index out of range");
    }

    return Node(*this, idx);
  }

private:
  class Node {
    public:
      Node(Fenwick &tree, int idx) : tree_(tree), idx_(idx) { }

      operator value_type() const { return tree_.data_[idx_]; }

      Node & operator+=(const_reference delta) {
        tree_.update(idx_, delta);
        return *this;
      }

    private:
      Fenwick &tree_;
      const int idx_;
  };

  std::vector<value_type> data_;
  std::vector<value_type> tree_;

  int size_;

  void update(int idx, const_reference delta);
  void update_tree(int idx, const_reference delta);

  friend class Node;
};

template<class T>
void Fenwick<T>::update(int idx, const_reference delta) {
  data_[idx] += delta;

  update_tree(idx + 1, delta);
}

template<class T>
void Fenwick<T>::update_tree(int idx, const_reference delta) {
  if (idx < 0 || idx >= size_) {
    return;
  }

  tree_[idx - 1] += delta;

  idx = idx + (idx & (-idx));

  update_tree(idx, delta);
}
