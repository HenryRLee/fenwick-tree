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

  Node operator[] (int index) {
    return Node(this, index);
  }

  class Node {
    public:
      Node(Fenwick &tree, int index) : tree_(tree), index_(index) { }
    private:
      Fenwick &tree_;
      int index_;
  };

private:
  std::vector<T> data;
  std::vector<T> tree;

  int size_;

  friend class Node;
};
