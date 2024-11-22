#ifndef S21_MAP_H
#define S21_MAP_H

#include "s21_avltree.h"

namespace s21 {
template <typename Key, typename T>
class Map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  struct MapCompare {
    bool operator()(const value_type& a, const value_type& b) const noexcept {
      return a.first < b.first;
    }
  };

  using iterator = typename AVLTree<key_type, value_type, MapCompare>::iterator;
  using const_iterator =
      typename AVLTree<key_type, value_type, MapCompare>::const_iterator;
  using Node = typename AVLTree<key_type, value_type, MapCompare>::Node;

  Map() : tree(new AVLTree<key_type, value_type, MapCompare>()) {}

  Map(std::initializer_list<value_type> const& items)
      : tree(new AVLTree<key_type, value_type, MapCompare>()) {
    for (auto item : items) {
      Insert(item);
    }
  }

  Map(const Map& m) : tree(new AVLTree(*m.tree)) {}

  Map(Map&& m) : tree(new AVLTree(std::move(*m.tree))) {}

  Map& operator=(const Map& m) {
    if (this != &m) {
      *tree = *m.tree;
    }
    return *this;
  }

  Map& operator=(Map&& m) {
    if (this != &m) {
      Clear();
      *tree = std::move(*m.tree);
    }
    return *this;
  }

  ~Map() {
    delete tree;
    tree = nullptr;
  }

  T& At(const Key& key) { return (*tree->At(key)).second; }

  T& operator[](const Key& key) {
    auto result = tree->InsertUnique({key, T()});
    return (*(result.first)).second;
  }

  iterator Begin() { return iterator(tree->MinNode(), tree->GetRoot()); }

  iterator End() { return iterator(nullptr, tree->GetRoot()); }

  const_iterator CBegin() const noexcept {
    return const_iterator(tree->MinNode(), tree->GetRoot());
  }

  const_iterator CEnd() const noexcept {
    return const_iterator(nullptr, tree->GetRoot());
  }

  bool Empty() { return tree->Empty(); }

  size_type Size() { return tree->Size(); }

  size_type Max_size() {
    return (std::numeric_limits<size_type>::max() / 2) / sizeof(Node);
  }

  std::pair<iterator, bool> Insert(const_reference value) {
    return tree->InsertUnique(value);
  }

  std::pair<iterator, bool> Insert(const Key& key, const T& obj) {
    return tree->InsertUnique(value_type{key, obj});
  }

  std::pair<iterator, bool> InsertOrAssign(const Key& key, const T& obj) {
    value_type value = std::make_pair(key, obj);
    std::pair<iterator, bool> result = Insert(value);
    if (!result.second) {
      (*(result.first)).second = obj;
    }
    return result;
  }

  void Erase(iterator pos) { tree->Erase(pos); }

  void Swap(Map& other) { std::swap(tree, other.tree); }

  void Clear() { tree->ClearTree(); }

  void Merge(Map& other) {
    auto otherEnd = other.End();
    for (auto it = other.Begin(); it != otherEnd; ++it) {
      Insert(*it);
    }
    other.Clear();
  }

  bool Contains(const Key& key) { return tree->ContainsPair(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> InsertMany(Args&&... args) {
    std::vector<std::pair<iterator, bool>> result;
    std::vector<value_type> arguments = {args...};
    for (auto& elem : arguments) {
      result.push_back(Insert(elem));
    }
    return result;
  }

 private:
  AVLTree<key_type, value_type, MapCompare>* tree;
};

}  // namespace s21

#endif  // S21_MAP_H
