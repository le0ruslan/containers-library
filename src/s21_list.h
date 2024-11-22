#ifndef S21Containers_SRC_S21_LIST_H_
#define S21Containers_SRC_S21_LIST_H_

#include <climits>
#include <initializer_list>
#include <iostream>

namespace s21 {

template <typename T>
class List {
 public:
  using value_type = T;
  using const_value = const T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  List();
  explicit List(size_t size);
  List(std::initializer_list<T> data);

  List(const List &other);
  List &operator=(const List &other);

  List(List &&other) noexcept;
  List &operator=(List &&other) noexcept;

  ~List();

  [[nodiscard]] reference Front() const;
  [[nodiscard]] reference Back() const;

  [[nodiscard]] bool IsEmpty() const;
  [[nodiscard]] size_type Size() const;
  [[nodiscard]] size_type MaxSize() const;

  void Clear();
  void PushBack(const_reference data);
  void PushBack(std::initializer_list<T> list);
  void PopBack();
  void PushFront(const_reference value);
  void PopFront();
  void Swap(List &other);
  void Merge(List &other);
  void Reverse();
  void Unique();
  void Sort();

  void Print() const;
  void PrintAddress();

 private:
  struct Node {
    value_type data_;
    Node *prev_;
    Node *next_;

    explicit Node(value_type data = value_type(), Node *prev = nullptr,
                  Node *next = nullptr)
        : data_(data), prev_(prev), next_(next) {}
  };

 public:
  struct iterator {
    iterator();
    explicit iterator(Node *node);
    value_type operator*() const;
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

    Node *node_;
  };

 public:
  iterator Begin() const;
  iterator End() const;
  iterator Insert(iterator pos, const_value data);
  void Erase(iterator pos);
  void Splice(const iterator pos, List &other);

  // additional part
  template <class... Args>
  iterator InsertMany(const iterator pos, Args &&...args);

  template <class... Args>
  void InsertManyBack(Args &&...args);

  template <class... Args>
  void InsertManyFront(Args &&...args);

 private:
  size_type size_;
  Node *head_;
  Node *tail_;
};

template <typename value_type>
List<value_type>::List() : size_(0), head_(nullptr), tail_(nullptr) {}

template <typename value_type>
List<value_type>::List(size_type size)
    : size_(0), head_(nullptr), tail_(nullptr) {
  for (size_t i = 0; i < size; ++i) PushBack(0);
}

template <typename value_type>
List<value_type>::List(std::initializer_list<value_type> data)
    : size_(0), head_(nullptr), tail_(nullptr) {
  this->PushBack(data);
}

template <typename value_type>
List<value_type>::List(const List &other)
    : size_(0), head_(nullptr), tail_(nullptr) {
  Node *Tmp = other.head_;
  while (Tmp != nullptr) {
    this->PushBack(Tmp->data_);
    Tmp = Tmp->next_;
  }
}

template <typename value_type>
List<value_type> &List<value_type>::operator=(const List &other) {
  if (this == &other) return *this;
  this->Clear();

  Node *Tmp = other.head_;
  while (Tmp != nullptr) {
    this->PushBack(Tmp->data_);
    Tmp = Tmp->next_;
  }

  return *this;
}

template <typename value_type>
List<value_type>::List(List &&other) noexcept
    : size_(other.size_), head_(other.head_), tail_(other.tail_) {
  other.size_ = 0;
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

template <typename value_type>
List<value_type> &List<value_type>::operator=(List &&other) noexcept {
  if (this == &other) return *this;
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
  return *this;
}

template <typename value_type>
List<value_type>::~List() {
  while (head_ != nullptr) {
    Node *Tmp = head_;
    head_ = Tmp->next_;
    delete Tmp;
  }
}

template <typename value_type>
typename List<value_type>::reference List<value_type>::Front() const {
  return head_->data_;
}

template <typename value_type>
typename List<value_type>::reference List<value_type>::Back() const {
  return tail_->data_;
}

template <typename value_type>
void List<value_type>::PushBack(std::initializer_list<value_type> list) {
  for (auto element : list) {
    this->PushBack(element);
  }
}

template <typename value_type>
void List<value_type>::PushBack(const_value &data) {
  if (head_ == nullptr) {
    head_ = new Node(data);
    tail_ = head_;
  } else {
    Node *Tmp = new Node(data);
    tail_->next_ = Tmp;
    Tmp->prev_ = tail_;
    Tmp->next_ = nullptr;
    tail_ = Tmp;
  }
  ++size_;
}

template <typename value_type>
void List<value_type>::Clear() {
  while (head_ != nullptr) {
    Node *Tmp = head_;
    head_ = Tmp->next_;
    delete Tmp;
  }
  size_ = 0;
}

template <typename value_type>
void List<value_type>::PopBack() {
  Node *Tmp = tail_;
  tail_ = tail_->prev_;
  tail_->next_ = nullptr;
  --size_;
  delete Tmp;
}

template <typename value_type>
void List<value_type>::PushFront(const_value &data) {
  Node *Tmp = new Node(data);
  Tmp->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = Tmp;
  }
  head_ = Tmp;
  if (tail_ == nullptr) {
    tail_ = Tmp;
  }
  ++size_;
}

template <typename value_type>
void List<value_type>::PopFront() {
  Node *Tmp = head_;
  head_ = head_->next_;
  head_->prev_ = nullptr;
  --size_;
  delete Tmp;
}

template <typename value_type>
void List<value_type>::Swap(List &other) {
  if (this == &other) return;

  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
}

template <typename value_type>
void List<value_type>::Merge(List &other) {
  if (this == &other) return;
  tail_->next_ = other.head_;
  size_ += other.size_;
  tail_ = other.tail_;
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
  this->Sort();
}

template <typename value_type>
void List<value_type>::Reverse() {
  Node *current = head_;
  Node *Tmp = nullptr;

  while (current != nullptr) {
    Tmp = current->next_;
    current->next_ = current->prev_;
    current->prev_ = Tmp;
    current = current->prev_;
  }

  std::swap(head_, tail_);
}

template <typename value_type>
void List<value_type>::Unique() {
  for (auto it = this->Begin(); it != this->End(); ++it) {
    auto next = iterator(it.node_->next_);

    while (next != this->End() && *it == *next) {
      auto tmp = next.node_->next_;
      this->Erase(next);
      next = iterator(tmp);
    }
  }
}

template <typename value_type>
void List<value_type>::Sort() {
  if (head_ == tail_) {
    return;
  }

  for (auto it = this->Begin(); it != this->End(); ++it) {
    auto next = iterator(it.node_->next_);

    while (next != End() && next != it) {
      if (*it > *next) {
        value_type tmpData = it.node_->data_;
        it.node_->data_ = next.node_->data_;
        next.node_->data_ = tmpData;
      }
      next = ++next;
    }
  }
}

template <typename value_type>
size_t List<value_type>::MaxSize() const {
  return (std::numeric_limits<std::size_t>::max() / sizeof(Node)) / 2;
}

template <typename value_type>
size_t List<value_type>::Size() const {
  return size_;
}

template <typename value_type>
void List<value_type>::Print() const {
  for (Node *Tmp = head_; Tmp != nullptr; Tmp = Tmp->next_) {
    std::cout << Tmp->data_ << " ";
  }
  std::cout << std::endl;
}

template <typename value_type>
void List<value_type>::PrintAddress() {
  Node *Tmp = head_;
  while (Tmp != nullptr) {
    printf("%p ", &Tmp->data_);
    Tmp = Tmp->next_;
  }
  std::cout << std::endl;
}

template <typename value_type>
bool List<value_type>::IsEmpty() const {
  return size_ == 0;
}

template <typename value_type>
List<value_type>::iterator::iterator() : node_(nullptr) {}

template <typename value_type>
List<value_type>::iterator::iterator(Node *node) : node_(node) {}

template <typename value_type>
value_type List<value_type>::iterator::operator*() const {
  if (node_ == nullptr) {
    throw std::out_of_range("Iterator is dereferenced at end");
  }
  return node_->data_;
}

template <typename value_type>
typename List<value_type>::iterator &List<value_type>::iterator::operator++() {
  if (node_ != nullptr) node_ = node_->next_;
  return *this;
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator++(
    int) {
  iterator tmp = *this;
  if (node_ != nullptr) node_ = node_->next_;
  return tmp;
}

template <typename value_type>
typename List<value_type>::iterator &List<value_type>::iterator::operator--() {
  if (node_ != nullptr) {
    node_ = node_->prev_;
  }
  return *this;
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator--(
    int) {
  iterator tmp = *this;
  if (node_ != nullptr) node_ = node_->prev_;
  return tmp;
}

template <typename value_type>
bool List<value_type>::iterator::operator==(const iterator &other) const {
  return node_ == other.node_;
}

template <typename value_type>
bool List<value_type>::iterator::operator!=(const iterator &other) const {
  return !(*this == other);
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::Begin() const {
  if (head_ == nullptr) return End();
  return iterator(head_);
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::End() const {
  return iterator(nullptr);
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::Insert(iterator pos,
                                                             const_value data) {
  if (pos == Begin()) {
    this->PushFront(data);
    pos = iterator(head_);
  } else if (pos == End()) {
    this->PushBack(data);
    pos = iterator(tail_);
  } else {
    Node *current = pos.node_;
    Node *Tmp = new Node(data);
    Tmp->next_ = current;
    Tmp->prev_ = current->prev_;
    current->prev_->next_ = Tmp;
    current->prev_ = Tmp;
    ++size_;
    return iterator(Tmp);
  }
  return pos;
}

template <typename value_type>
void List<value_type>::Erase(iterator pos) {
  if (pos.node_ == head_) {
    this->PopFront();
  } else if (pos.node_ == tail_) {
    this->PopBack();
  } else {
    Node *value_typemp = pos.node_;
    value_typemp->prev_->next_ = pos.node_->next_;
    value_typemp->next_->prev_ = pos.node_->prev_;
    --size_;
    delete pos.node_;
  }
}

template <typename value_type>
void List<value_type>::Splice(const iterator pos, List &other) {
  if (this == &other) return;
  if (pos.node_ == head_) {
    other.tail_->next_ = head_;
    head_->prev_ = other.tail_;
    size_ += other.size_;
    head_ = other.head_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  } else if (pos.node_ == tail_) {
    tail_->next_ = other.head_;
    other.head_->prev_ = tail_;
    size_ += other.size_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  } else {
    Node *current = pos.node_->prev_;
    Node *next = pos.node_;
    current->next_ = other.head_;
    other.head_->prev_ = current;
    other.tail_->next_ = next;
    next->prev_ = other.tail_;
    size_ += other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <typename value_type>
template <class... Args>
typename List<value_type>::iterator List<value_type>::InsertMany(
    const iterator pos, Args &&...args) {
  iterator currentPos = pos;
  auto insertEach = [&](const value_type &value) {
    currentPos = Insert(currentPos, value);
    ++currentPos;
  };
  (insertEach(std::forward<Args>(args)), ...);
  return currentPos;
}

template <typename value_type>
template <class... Args>
void List<value_type>::InsertManyBack(Args &&...args) {
  (PushBack(std::forward<Args>(args)), ...);
}

template <typename value_type>
template <class... Args>
void List<value_type>::InsertManyFront(Args &&...args) {
  (PushFront(std::forward<Args>(args)), ...);
}

}  // namespace s21

#endif  // S21Containers_SRC_S21_LIST_H_
