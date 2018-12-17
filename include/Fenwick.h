#include <vector>

template <class T>
class Fenwick {
private:
  class Node;

public:

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

      operator T() const { return tree_.data_[idx_]; }

      Node & operator+=(const T & delta) {
        tree_.update(idx_, delta);
        return *this;
      }

    private:
      Fenwick &tree_;
      const int idx_;
  };

  std::vector<T> data_;
  std::vector<T> tree_;

  int size_;

  void update(int idx, const T & delta);
  void update_tree(int idx, const T & delta);

  friend class Node;
};

template<class T>
void Fenwick<T>::update(int idx, const T & delta) {
  data_[idx] += delta;

  update_tree(idx + 1, delta);
}

template<class T>
void Fenwick<T>::update_tree(int idx, const T & delta) {
  if (idx < 0 || idx >= size_) {
    return;
  }

  tree_[idx - 1] += delta;

  idx = idx + (idx & (-idx));

  update_tree(idx, delta);
}
