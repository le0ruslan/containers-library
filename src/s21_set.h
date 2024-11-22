#ifndef S21Containers_SRC_S21_SET_H_
#define S21Containers_SRC_S21_SET_H_

#include <climits>
#include <initializer_list>
#include <iostream>

enum Color { Black, Red };
namespace s21 {
template <typename T>
class Set {
 public:
  using key_type = T;
  using size_type = size_t;

  Set();
  Set(std::initializer_list<key_type> const& data);

  Set(const Set& other);
  Set& operator=(const Set& other);

  Set(Set&& other) noexcept;
  Set& operator=(Set&& other) noexcept;

  ~Set();

  bool Empty();
  size_type Size();
  size_type MaxSize();

  void Clear();

  void Swap(Set& other);
  void Merge(Set& other);

 private:
  struct Node {
    key_type data_;
    Color color_;
    Node* left_;
    Node* right_;
    Node* parent_;

    explicit Node(key_type data = key_type(), Color color = Red,
                  Node* left = nullptr, Node* right = nullptr,
                  Node* parent = nullptr)
        : data_(data),
          color_(color),
          left_(left),
          right_(right),
          parent_(parent) {}
  };

  size_type size_;
  Node* root_;

 public:
  struct iterator {
    iterator();
    explicit iterator(Node* node);
    key_type operator*();
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;

    Node* node_;
  };

  iterator Begin() const;
  iterator End() const;
  std::pair<iterator, bool> Insert(const key_type& value);
  void Erase(iterator pos);
  iterator Find(const key_type& key);
  bool Contains(const key_type& key);

  // additional part3
  template <class... Args>
  std::vector<std::pair<iterator, bool>> InsertMany(Args&&... args);

 private:
  void PrintInor();
  void PrintPost();
  void PrintPre();
  void PrePrint(Node* tmp);
  void Post(Node* tmp);
  void Pre(Node* tmp);
  void Inorder(Node* tmp);
  void Postorder(Node* tree);

  Node* Grandparent(Node* tmp);
  Node* Uncle(Node* tmp);
  void RotateLeft(Node* tmp);
  void RotateRight(Node* tmp);
  void InsertCase1(Node* tmp);
  void InsertCase2(Node* tmp);
  void InsertCase3(Node* tmp);
  void InsertCase4(Node* tmp);
  void InsertCase5(Node* tmp);

  Node* Sibling(Node* tmp);
  void ReplaceNode(Node* tmp, Node* child);
  void DeleteOneChild(Node* tmp);
  bool IsLeaf(Node* tmp);
  void DeleteCase1(Node* tmp);
  void DeleteCase2(Node* tmp);
  void DeleteCase3(Node* tmp);
  void DeleteCase4(Node* tmp);
  void DeleteCase5(Node* tmp);
  void DeleteCase6(Node* tmp);
};

template <typename key_type>
Set<key_type>::Set() : size_(0), root_(nullptr) {}

template <typename key_type>
Set<key_type>::Set(std::initializer_list<key_type> const& data)
    : size_(0), root_(nullptr) {
  for (auto element : data) {
    this->Insert(element);
  }
}

template <typename key_type>
Set<key_type>::Set(const Set& other) : size_(0), root_(nullptr) {
  Node* tmp = other.root_;
  this->Pre(tmp);
}

template <typename key_type>
Set<key_type>& Set<key_type>::operator=(const Set& other) {
  if (this == &other) return *this;
  this->Clear();

  Node* tmp = other.root_;
  this->Pre(tmp);
  return *this;
}

template <typename key_type>
Set<key_type>::Set(Set&& other) noexcept
    : size_(other.size_), root_(other.root_) {
  other.size_ = 0;
  other.root_ = nullptr;
}

template <typename key_type>
Set<key_type>& Set<key_type>::operator=(Set&& other) noexcept {
  if (this == &other) return *this;
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
  return *this;
}

template <typename key_type>
Set<key_type>::~Set() {
  this->Postorder(root_);
  size_ = 0;
}

template <typename key_type>
bool Set<key_type>::Empty() {
  if (root_ == nullptr)
    return true;
  else
    return false;
}

template <typename key_type>
typename Set<key_type>::size_type Set<key_type>::Size() {
  return size_;
}

template <typename key_type>
typename Set<key_type>::size_type Set<key_type>::MaxSize() {
  return (std::numeric_limits<std::size_t>::max() / sizeof(Node)) / 2;
}

template <typename key_type>
void Set<key_type>::Clear() {
  this->Postorder(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename key_type>
void Set<key_type>::Swap(Set<key_type>& other) {
  if (this == &other) return;

  std::swap(size_, other.size_);
  std::swap(root_, other.root_);
}

template <typename key_type>
void Set<key_type>::Merge(Set& other) {
  auto it = other.Begin();
  while (it != other.End()) {
    auto next_it = it;
    ++next_it;
    auto result = this->Insert(std::move(*it));
    if (result.second) other.Erase(it);
    it = next_it;
  }
}

template <typename key_type>
Set<key_type>::iterator::iterator() : node_(nullptr) {}

template <typename key_type>
Set<key_type>::iterator::iterator(Node* node) : node_(node) {}

template <typename key_type>
typename Set<key_type>::key_type Set<key_type>::iterator::operator*() {
  if (node_ == nullptr)
    throw std::out_of_range("Iterator is dereferenced at end");
  return node_->data_;
}

template <typename key_type>
typename Set<key_type>::iterator& Set<key_type>::iterator::operator++() {
  if (node_ == nullptr) return *this;

  if (node_->right_ != nullptr) {
    node_ = node_->right_;
    while (node_->left_ != nullptr) node_ = node_->left_;
  } else {
    while (node_->parent_ != nullptr && node_ == node_->parent_->right_)
      node_ = node_->parent_;
    if (node_->parent_ == nullptr)
      node_ = nullptr;
    else
      node_ = node_->parent_;
  }
  return *this;
}

template <typename key_type>
typename Set<key_type>::iterator Set<key_type>::iterator::operator++(int) {
  auto tmp = *this;
  operator++();
  return iterator(tmp);
}

template <typename key_type>
typename Set<key_type>::iterator& Set<key_type>::iterator::operator--() {
  if (node_ == nullptr) {
    return *this;
  }

  if (node_->left_ != nullptr) {
    node_ = node_->left_;
    while (node_->right_ != nullptr) node_ = node_->right_;
  } else {
    while (node_->parent_ != nullptr && node_ == node_->parent_->left_)
      node_ = node_->parent_;

    if (node_->parent_ == nullptr)
      node_ = nullptr;
    else
      node_ = node_->parent_;
  }

  return *this;
}

template <typename key_type>
typename Set<key_type>::iterator Set<key_type>::iterator::operator--(int) {
  auto tmp = *this;
  operator--();
  return iterator(tmp);
}

template <typename key_type>
bool Set<key_type>::iterator::operator==(const iterator& other) const {
  return node_ == other.node_;
}

template <typename key_type>
bool Set<key_type>::iterator::operator!=(const iterator& other) const {
  return node_ != other.node_;
}

template <typename key_type>
typename Set<key_type>::iterator Set<key_type>::Begin() const {
  if (root_ == nullptr) return iterator(nullptr);
  Node* tmp_parent = nullptr;
  Node* tmp_root = root_;

  while (tmp_root != nullptr) {
    tmp_parent = tmp_root;
    tmp_root = tmp_root->left_;
  }

  return iterator(tmp_parent);
}

template <typename key_type>
typename Set<key_type>::iterator Set<key_type>::End() const {
  return iterator(nullptr);
}

template <typename key_type>
void Set<key_type>::Erase(iterator pos) {
  Node* tmp = pos.node_;
  if (tmp == nullptr) return;

  // Save the iterator to the next node
  iterator next = pos;
  ++next;

  if (this->IsLeaf(tmp)) {
    if (tmp == root_) {
      delete root_;
      root_ = nullptr;
      --size_;
    } else {
      this->DeleteOneChild(tmp);
    }
  } else if (tmp->left_ == nullptr || tmp->right_ == nullptr) {
    Node* child = (tmp->left_ != nullptr) ? tmp->left_ : tmp->right_;
    this->ReplaceNode(tmp, child);
    delete tmp;
    --size_;
  } else {
    Node* successor = tmp->right_;
    while (successor->left_ != nullptr) {
      successor = successor->left_;
    }

    std::swap(tmp->data_, successor->data_);
    this->Erase(iterator(successor));
    return;  // Successor is deleted, no need to proceed further
  }

  pos = next;
}

template <typename key_type>
typename Set<key_type>::iterator Set<key_type>::Find(const key_type& key) {
  Node* tmp = root_;
  while (tmp != nullptr) {
    if (key < tmp->data_)
      tmp = tmp->left_;
    else if (key > tmp->data_)
      tmp = tmp->right_;
    else
      return iterator(tmp);
  }
  return iterator(nullptr);
}

template <typename key_type>
bool Set<key_type>::Contains(const key_type& key) {
  Node* tmp = root_;
  while (tmp != nullptr) {
    if (key < tmp->data_)
      tmp = tmp->left_;
    else if (key > tmp->data_)
      tmp = tmp->right_;
    else
      return true;
  }
  return false;
}

template <typename key_type>
std::pair<typename Set<key_type>::iterator, bool> Set<key_type>::Insert(
    const key_type& data) {
  Node* tmp_parent = nullptr;
  Node* tmp_root = root_;
  Node* NewNode = new Node(data);

  while (tmp_root != nullptr) {
    tmp_parent = tmp_root;
    if (NewNode->data_ == tmp_root->data_) {
      delete NewNode;
      return std::make_pair(iterator(tmp_root), false);
    }
    if (tmp_root->data_ > NewNode->data_)
      tmp_root = tmp_root->left_;
    else
      tmp_root = tmp_root->right_;
  }

  NewNode->parent_ = tmp_parent;
  if (tmp_parent != nullptr) {
    if (NewNode->data_ > tmp_parent->data_)
      tmp_parent->right_ = NewNode;
    else
      tmp_parent->left_ = NewNode;
  } else {
    root_ = NewNode;
  }
  size_ += 1;
  this->InsertCase1(NewNode);

  return std::make_pair(iterator(NewNode), true);
}

template <typename key_type>
void Set<key_type>::PrintInor() {
  Node* tmp = root_;
  this->Inorder(tmp);
}

template <typename key_type>
void Set<key_type>::PrintPost() {
  Node* tmp = root_;
  this->Post(tmp);
}

template <typename key_type>
void Set<key_type>::PrintPre() {
  Node* tmp = root_;
  this->PrePrint(tmp);
}

template <typename key_type>
void Set<key_type>::PrePrint(Node* tmp) {
  if (tmp == nullptr) return;
  std::cout << tmp->data_ << ' ';
  this->PrePrint(tmp->left_);
  this->PrePrint(tmp->right_);
}

template <typename key_type>
void Set<key_type>::Pre(Node* tmp) {
  if (tmp == nullptr) return;
  this->Insert(tmp->data_);
  this->Pre(tmp->left_);
  this->Pre(tmp->right_);
}

template <typename key_type>
void Set<key_type>::Post(Node* tmp) {
  if (tmp == nullptr) return;
  this->Post(tmp->left_);
  this->Post(tmp->right_);
  std::cout << tmp->data_ << ' ';
}

template <typename key_type>
void Set<key_type>::Inorder(Node* tmp) {
  if (tmp == nullptr) return;
  this->Inorder(tmp->left_);
  std::cout << tmp->data_ << " ";
  this->Inorder(tmp->right_);
}

template <typename key_type>
void Set<key_type>::Postorder(Node* tree) {
  if (tree == nullptr) return;
  if (tree->left_ != nullptr) this->Postorder(tree->left_);
  if (tree->right_ != nullptr) this->Postorder(tree->right_);
  delete tree;
}

template <typename key_type>
typename Set<key_type>::Node* Set<key_type>::Grandparent(Node* tmp) {
  if ((tmp != nullptr) && (tmp->parent_ != nullptr))
    return tmp->parent_->parent_;
  else
    return nullptr;
}

template <typename key_type>
typename Set<key_type>::Node* Set<key_type>::Uncle(Node* tmp) {
  Node* g = this->Grandparent(tmp);
  if (g == nullptr) return nullptr;
  if (tmp->parent_ == g->left_)
    return g->right_;
  else
    return g->left_;
}

template <typename key_type>
void Set<key_type>::RotateLeft(Node* tmp) {
  Node* pivot = tmp->right_;
  pivot->parent_ = tmp->parent_;
  if (tmp->parent_ != nullptr) {
    if (tmp->parent_->left_ == tmp)
      tmp->parent_->left_ = pivot;
    else
      tmp->parent_->right_ = pivot;
  } else
    root_ = pivot;

  tmp->right_ = pivot->left_;
  if (pivot->left_ != nullptr) pivot->left_->parent_ = tmp;

  tmp->parent_ = pivot;
  pivot->left_ = tmp;
}

template <typename key_type>
void Set<key_type>::RotateRight(Node* tmp) {
  Node* pivot = tmp->left_;
  pivot->parent_ = tmp->parent_;
  if (tmp->parent_ != nullptr) {
    if (tmp->parent_->left_ == tmp)
      tmp->parent_->left_ = pivot;
    else
      tmp->parent_->right_ = pivot;
  } else
    root_ = pivot;

  tmp->left_ = pivot->right_;
  if (pivot->right_ != nullptr) pivot->right_->parent_ = tmp;

  tmp->parent_ = pivot;
  pivot->right_ = tmp;
}

template <typename key_type>
void Set<key_type>::InsertCase1(Node* tmp) {
  if (tmp->parent_ == nullptr) {
    tmp->color_ = Black;
  } else
    this->InsertCase2(tmp);
}

template <typename key_type>
void Set<key_type>::InsertCase2(Node* tmp) {
  if (tmp->parent_->color_ == Black) {
    return;
  } else
    this->InsertCase3(tmp);
}

template <typename key_type>
void Set<key_type>::InsertCase3(Node* tmp) {
  Node *u = this->Uncle(tmp), *g;
  if ((u != nullptr) && (u->color_ == Red)) {
    tmp->parent_->color_ = Black;
    u->color_ = Black;
    g = Grandparent(tmp);
    g->color_ = Red;
    this->InsertCase1(g);
  } else {
    this->InsertCase4(tmp);
  }
}

template <typename key_type>
void Set<key_type>::InsertCase4(Node* tmp) {
  Node* g = this->Grandparent(tmp);
  if ((tmp == tmp->parent_->right_) && (tmp->parent_ == g->left_)) {
    this->RotateLeft(tmp->parent_);
    tmp = tmp->left_;
  } else if ((tmp == tmp->parent_->left_) && (tmp->parent_ == g->right_)) {
    this->RotateRight(tmp->parent_);
    tmp = tmp->right_;
  }
  this->InsertCase5(tmp);
}

template <typename key_type>
void Set<key_type>::InsertCase5(Node* tmp) {
  Node* g = this->Grandparent(tmp);
  tmp->parent_->color_ = Black;
  g->color_ = Red;
  if ((tmp == tmp->parent_->left_) && (tmp->parent_ == g->left_))
    this->RotateRight(g);
  else
    this->RotateLeft(g);
}

template <typename key_type>
typename Set<key_type>::Node* Set<key_type>::Sibling(Node* tmp) {
  if (tmp == tmp->parent_->left_)
    return tmp->parent_->right_;
  else
    return tmp->parent_->left_;
}

template <typename key_type>
void Set<key_type>::ReplaceNode(Node* tmp, Node* child) {
  if (tmp->parent_ == nullptr)
    root_ = child;
  else {
    if (tmp == tmp->parent_->left_)
      tmp->parent_->left_ = child;
    else
      tmp->parent_->right_ = child;
  }
  if (child != nullptr) child->parent_ = tmp->parent_;
}

template <typename key_type>
void Set<key_type>::DeleteOneChild(Node* tmp) {
  Node* child = IsLeaf(tmp->right_) ? tmp->left_ : tmp->right_;
  this->ReplaceNode(tmp, child);
  if (tmp->color_ == Black) {
    if (child != nullptr && child->color_ == Red)
      child->color_ = Black;
    else
      this->DeleteCase1(child);
  }
  delete tmp;
  size_ -= 1;
}

template <typename key_type>
bool Set<key_type>::IsLeaf(Node* tmp) {
  return tmp != nullptr && tmp->left_ == nullptr && tmp->right_ == nullptr;
}

template <typename key_type>
void Set<key_type>::DeleteCase1(Node* tmp) {
  if (tmp != nullptr && tmp->parent_ != nullptr) this->DeleteCase2(tmp);
}

template <typename key_type>
void Set<key_type>::DeleteCase2(Node* tmp) {
  Node* s = this->Sibling(tmp);
  if (s->color_ == Red) {
    tmp->parent_->color_ = Red;
    s->color_ = Black;
    if (tmp == tmp->parent_->left_)
      this->RotateLeft(tmp->parent_);
    else
      this->RotateRight(tmp->parent_);
  }
  this->DeleteCase3(tmp);
}

template <typename key_type>
void Set<key_type>::DeleteCase3(Node* tmp) {
  Node* s = this->Sibling(tmp);
  if ((tmp->parent_->color_ == Black) && (s->color_ == Black) &&
      (s->left_ == nullptr || s->left_->color_ == Black) &&
      (s->right_ == nullptr || s->right_->color_ == Black)) {
    s->color_ = Red;
    this->DeleteCase1(tmp->parent_);
  } else
    this->DeleteCase4(tmp);
}

template <typename key_type>
void Set<key_type>::DeleteCase4(Node* tmp) {
  Node* s = this->Sibling(tmp);
  if ((tmp->parent_->color_ == Red) && (s->color_ == Black) &&
      (s->left_ == nullptr || s->left_->color_ == Black) &&
      (s->right_ == nullptr || s->right_->color_ == Black)) {
    s->color_ = Red;
    tmp->parent_->color_ = Black;
  } else
    this->DeleteCase5(tmp);
}

template <typename key_type>
void Set<key_type>::DeleteCase5(Node* tmp) {
  Node* s = this->Sibling(tmp);
  if (s->color_ == Black) {
    if ((tmp == tmp->parent_->left_) &&
        (s->right_ == nullptr || s->right_->color_ == Black) &&
        (s->left_ != nullptr && s->left_->color_ == Red)) {
      s->color_ = Red;
      s->left_->color_ = Black;
      this->RotateRight(s);
    } else if ((tmp == tmp->parent_->right_) &&
               (s->left_ == nullptr || s->left_->color_ == Black) &&
               (s->right_ != nullptr && s->right_->color_ == Red)) {
      s->color_ = Red;
      s->right_->color_ = Black;
      this->RotateLeft(s);
    }
    this->DeleteCase6(tmp);
  }
}

template <typename key_type>
void Set<key_type>::DeleteCase6(Node* tmp) {
  Node* s = this->Sibling(tmp);
  s->color_ = tmp->parent_->color_;
  tmp->parent_->color_ = Black;

  if (tmp == tmp->parent_->left_) {
    if (s->right_ != nullptr) s->right_->color_ = Black;
    this->RotateLeft(tmp->parent_);
  } else {
    if (s->left_ != nullptr) s->left_->color_ = Black;
    this->RotateRight(tmp->parent_);
  }
}

template <typename key_type>
template <class... Args>
std::vector<std::pair<typename Set<key_type>::iterator, bool>>
Set<key_type>::InsertMany(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  (result.push_back(this->Insert(std::forward<Args>(args))), ...);
  return result;
}

}  // namespace s21
#endif  // S21Containers_SRC_S21_SET_H_
