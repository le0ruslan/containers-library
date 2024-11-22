#include <iostream>
#include <limits>
#include <stdexcept>

namespace s21 {
template <typename key_, typename value_, typename compare_>
class AVLTree {
 public:
  class Node;
  struct TreeIterator;
  struct TreeIteratorConst;

  using key_type = key_;
  using value_type = value_;

  using reference = value_type &;
  using const_reference = const value_type &;

  using size_type = std::size_t;
  using iterator = TreeIterator;
  using const_iterator = TreeIteratorConst;

  AVLTree() : root(new Node), size_(0){};

  AVLTree(const AVLTree &other) : root(nullptr), size_(other.size_) {
    root = root->CopyNode(other.root);
  }

  AVLTree(AVLTree &&other) noexcept : root(other.root), size_(other.size_) {
    other.size_ = 0;
    other.root = new Node();
  }

  AVLTree &operator=(const AVLTree &other) {
    if (this != &other) {
      size_ = other.size_;
      root->CopyNode(other.root);
    }
    return *this;
  };

  AVLTree &operator=(AVLTree &&other) noexcept {
    if (this != &other) {
      DeleteTree();
      size_ = other.size_;
      root = other.root;

      other.size_ = 0;
      other.root = new Node();
    }
    return *this;
  }

  ~AVLTree() { DeleteTree(); }

  void DeleteTree() {
    if (root) {
      size_ = 0;
      root->ClearNode(root);
      root = nullptr;
    }
  }

  bool Empty() const noexcept { return size_ == 0 ? true : false; }

  size_type Size() const noexcept { return size_; }

  Node *MinNode() const {
    if (Empty()) return nullptr;
    return root->GetMin();
  }

  std::pair<iterator, bool> InsertUnique(value_type item) {
    std::pair<iterator, bool> result = Insert(item, root, true);
    if (result.second == true) IncreaseSize();
    return result;
  }

  std::pair<iterator, bool> InsertNonUnique(value_type item) {
    std::pair<iterator, bool> result = Insert(item, root, false);
    if (result.second == true) IncreaseSize();
    return result;
  }

  std::pair<iterator, bool> Insert(value_type item, Node *n, bool isUnique) {
    std::pair<iterator, bool> result = {iterator(n, root), true};
    if (this->Empty()) {
      root->data = item;
      return result;
    }
    if (compare_Keys(item, n->data)) {
      if (n->left == nullptr) {
        n->left = new Node(item);
        n->left->parent = n;
      } else {
        result = Insert(item, n->left, isUnique);
      }
    } else if (compare_Keys(n->data, item)) {
      if (n->right == nullptr) {
        n->right = new Node(item);
        n->right->parent = n;
      } else {
        result = Insert(item, n->right, isUnique);
      }
    } else {
      if (isUnique == true) {
        result = {iterator(n, root), false};
      } else {
        if (n->right == nullptr) {
          n->right = new Node(item);
          n->right->parent = n;
        } else {
          result = Insert(item, n->right, isUnique);
        }
      }
    }
    Balance(n);
    return result;
  }

  void Balance(Node *node) {
    node->UpdateHeight();
    int temp = node->Bfactor();
    if (temp == 2) {
      if (node->right != nullptr) {
        if (node->right->Bfactor() < 0) node->right = RotateRight(node->right);
      }
      node = RotateLeft(node);
    }
    if (temp == -2) {
      if (node->left != nullptr) {
        if (node->left->Bfactor() > 0) node->left = RotateLeft(node->left);
      }
      node = RotateRight(node);
    }
  }

  Node *RotateRight(Node *p) {
    Node *q = p->left;
    if (root == p) {
      root = q;
    } else {
      if (p->parent->left == p) p->parent->left = q;
      if (p->parent->right == p) p->parent->right = q;
    }
    q->parent = p->parent;

    p->left = q->right;
    q->right = p;
    if (p->left) p->left->parent = q;
    p->parent = q;
    q->UpdateHeight();
    return q;
  }

  Node *RotateLeft(Node *q) {
    Node *p = q->right;
    if (root == q) {
      root = p;
    } else {
      if (q->parent->left == q) q->parent->left = p;
      if (q->parent->right == q) q->parent->right = p;
    }
    p->parent = q->parent;

    q->right = p->left;
    p->left = q;
    if (q->right) q->right->parent = q;
    q->parent = p;
    p->UpdateHeight();
    return p;
  }

  bool Contains(const key_ &key) const {
    return root->Search(key) ? true : false;
  }

  iterator Find(const key_ &key) const {
    iterator it(root->Search(key), root);
    if (it.iter == nullptr) throw std::out_of_range("no key found");
    return it;
  }

  void IncreaseSize() noexcept { size_++; }
  void DecreaseSize() noexcept { size_--; }

  void Erase(iterator pos) {
    Node *p = pos.iter;
    Node *newNode = Remove(p);
    delete p;
    p = nullptr;
    if (newNode) Balance(newNode);
    if (!root) root = new Node();
    DecreaseSize();
  }

  Node *Remove(Node *p) {
    Node *newNode = nullptr;
    if (p == nullptr) return newNode;

    if (p->left != nullptr && p->right != nullptr) {
      newNode = RemoveTwoChildNode(p);
    } else if ((p->left == nullptr) xor (p->right == nullptr)) {
      newNode = RemoveOneChildNode(p);
    }

    if (p != root) {
      (p->parent->left == p) ? p->parent->left = newNode
                             : p->parent->right = newNode;
    } else {
      root = newNode;
    }

    return newNode;
  }

  Node *RemoveOneChildNode(Node *p) {
    Node *newNode = (p->left == nullptr) ? p->right : p->left->GetMax();
    newNode->parent = p->parent;
    return newNode;
  }

  Node *RemoveTwoChildNode(Node *p) {
    Node *maxInLeft = p->left->GetMax();
    Node *newNode = maxInLeft;

    newNode->right = p->right;
    if (p->right) newNode->right->parent = newNode;

    maxInLeft->parent->right = maxInLeft->left;
    if (maxInLeft->left) maxInLeft->left->parent = maxInLeft->parent;

    newNode->parent = p->parent;

    if (p->left != newNode) {
      newNode->left = p->left;
      newNode->left->parent = newNode;
    }

    return newNode;
  }

  void ClearTree() {
    if (root) {
      size_ = 0;
      root->ClearNode(root);
    }
    root = new Node();
  }

  iterator FindLowerBound(const_reference key) const {
    Node *start = root;
    Node *result = nullptr;

    while (start != nullptr) {
      if ((start->data >= key)) {
        result = start;
        start = start->left;
      } else {
        start = start->right;
      }
    }
    return iterator(result, root);
  }

  iterator FindUpperBound(const_reference key) const {
    Node *start = root;
    Node *result = nullptr;
    while (start != nullptr) {
      if (start->data > key) {
        result = start;
        start = start->left;
      } else
        start = start->right;
    }

    return iterator(result, root);
  }

  size_type Count(const key_ &key) const noexcept {
    return root->CountNonUnique(key);
  }

  iterator At(const key_ &key) const {
    return iterator(root->GetPair(key), root);
  }
  bool ContainsPair(const key_ &key) const {
    return root->GetPair(key) ? true : false;
  }

  Node *GetRoot() const noexcept { return root; }

  struct TreeIterator {
    TreeIterator() = delete;
    TreeIterator(Node *node, Node *root_) : iter(node), root(root_){};

    reference operator*() {
      if (iter == nullptr && root != nullptr) {
        iter = root->GetMax();
      }
      return iter->data;
    }

    iterator &operator++() {
      if (iter == nullptr && root != nullptr) {
        iter = root->GetMax();
      }
      iter = iter->MoveForward();
      return *this;
    }

    iterator &operator--() {
      if (iter == nullptr && root != nullptr) {
        iter = root->GetMin();
      }
      iter = iter->MoveBack();
      return *this;
    }

    bool operator==(const iterator &other) const noexcept {
      return iter == other.iter;
    }

    bool operator!=(const iterator &other) const noexcept {
      return iter != other.iter;
    }

    Node *iter;
    Node *root;
  };

  struct TreeIteratorConst {
    TreeIteratorConst() = delete;
    TreeIteratorConst(Node *node, Node *root_) : iter(node), root(root_){};

    const_reference operator*() const {
      if (iter == nullptr && root != nullptr) {
        root->GetMax();
      }
      return iter->data;
    }

    const_iterator &operator++() {
      if (iter == nullptr && root != nullptr) {
        iter = root->GetMax();
      }
      iter = iter->MoveForward();
      return *this;
    }

    const_iterator &operator--() {
      if (iter == nullptr && root != nullptr) {
        iter = root->GetMin();
      }
      iter = iter->MoveBack();
      return *this;
    }

    bool operator==(const_iterator &other) const noexcept {
      return iter == other.iter;
    }

    bool operator!=(const_iterator &other) const noexcept {
      return iter != other.iter;
    }

    const Node *iter;
    Node *root;
  };

 private:
  Node *root;
  size_type size_;
  compare_ compare_Keys;
};

template <typename key_, typename value_, typename compare_>
class AVLTree<key_, value_, compare_>::Node {
 public:
  Node() = default;
  Node(value_type data_) : data(data_) {}

  Node *CopyNode(const Node *other) {
    Node *copy = new Node{other->data};
    if (other->left) copy->left = copy->CopyNode(other->left);
    if (other->right) copy->right = copy->CopyNode(other->right);
    copy->parent = this;
    return copy;
  }

  Node *MoveForward() const {
    Node *p = const_cast<Node *>(this);
    if (right != nullptr) {
      return right->GetMin();
    } else {
      Node *tempParent = p->parent;
      while (tempParent != nullptr && tempParent->right == p) {
        p = tempParent;
        tempParent = tempParent->parent;
      }
      p = tempParent;
    }
    return p;
  }

  Node *MoveBack() const {
    Node *p = const_cast<Node *>(this);
    if (left != nullptr) {
      return left->GetMax();
    } else {
      Node *tempParent = p->parent;
      while (tempParent != nullptr && tempParent->left == p) {
        p = tempParent;
        tempParent = tempParent->parent;
      }
      p = parent;
    }
    return p;
  }

  Node *GetMin() {
    if (left == nullptr) return this;
    return left->GetMin();
  }

  Node *GetMax() {
    if (right == nullptr) return this;
    return right->GetMax();
  }

  int UpdateHeight() {
    int left_height = (left == nullptr) ? 0 : left->UpdateHeight();
    int right_height = (right == nullptr) ? 0 : right->UpdateHeight();
    height = 1 + std::max(left_height, right_height);
    return height;
  }

  int GetHeight() const { return height; }

  int Bfactor() const {
    int left_height = (left == nullptr) ? 0 : left->GetHeight();
    int right_height = (right == nullptr) ? 0 : right->GetHeight();
    return right_height - left_height;
  }

  Node *Search(const key_ &key) {
    if (data < key) {
      return (right == nullptr) ? nullptr : right->Search(key);
    } else if (data > key) {
      return (left == nullptr) ? nullptr : left->Search(key);
    } else {
      return this;
    }
  }

  size_type CountNonUnique(const key_ &key) const noexcept {
    size_type count_left = (left == nullptr) ? 0 : left->CountNonUnique(key);
    size_type count_right = (right == nullptr) ? 0 : right->CountNonUnique(key);
    return (data == key ? 1 : 0) + count_left + count_right;
  }

  Node *GetPair(const key_ &key) {
    Node *left_res = (left == nullptr) ? nullptr : left->GetPair(key);
    Node *right_res = (right == nullptr) ? nullptr : right->GetPair(key);
    if (data.first == key) return this;
    return (data.first < key) ? right_res : left_res;
  }

  void ClearNode(Node *node) {
    if (node != nullptr) {
      ClearNode(node->left);
      ClearNode(node->right);
      delete node;
      node = nullptr;
    }
  }

  value_type data;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *parent = nullptr;
  int height = 0;
};
}  // namespace s21