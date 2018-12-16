#include <vector>

template <class T>
class Fenwick {
public:
  class Node;

  Fenwick() { }
  Fenwick(int size) : size_(size) { };

  void resize(int size) {
    size_ = size;
  }

  int size() {
    return size_;
  }

  Node operator[] (int idx) {
    if (idx < 0 || idx >= size_) {
      throw std::out_of_range("Fenwick: index out of range");
    }

    return Node(*this, idx);
  }

  class Node {
    public:
      Node(Fenwick &tree, int idx) : tree_(tree), idx_(idx) { }

    private:
      Fenwick &tree_;
      int idx_;
  };

private:
  std::vector<T> data;
  std::vector<T> tree;

  int size_;

  friend class Node;
};
