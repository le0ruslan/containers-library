#ifndef S21Containers_SRC_S21_VECTOR_H_
#define S21Containers_SRC_S21_VECTOR_H_

#include <algorithm>
#include <climits>
#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Vector();
  explicit Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);

  Vector(const Vector &other);
  Vector &operator=(const Vector &other);

  Vector(Vector &&other) noexcept;
  Vector &operator=(Vector &&other) noexcept;

  ~Vector();

  reference At(size_type pos);
  reference operator[](size_type pos);
  const_reference Front() const;
  const_reference Back() const;
  T *Data();

  bool Empty();
  size_type Size();
  size_type MaxSize();
  void Reserve(size_type size);
  size_type Capacity();
  void ShrinkToFit();

  void Clear();

  void PushBack(const_reference value);
  void PopBack();
  void Swap(Vector &other);

  // additional methods
  void Print();

  struct iterator {
    iterator();
    explicit iterator(value_type *it);
    value_type operator*();
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

    value_type *it_;
  };

  iterator Begin();
  iterator End();
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);

  // additional part3
  template <class... Args>
  iterator InsertMany(const iterator pos, Args &&...args);  // Not implemented

  template <class... Args>
  void InsertManyBack(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  value_type *array_;
};

template <typename value_type>
Vector<value_type>::Vector() : size_(0), capacity_(0), array_(nullptr) {}

template <typename value_type>
Vector<value_type>::Vector(size_type n) : size_(n), capacity_(n) {
  array_ = new value_type[capacity_]{};
}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const &items)
    : size_(0),
      capacity_(std::distance(items.begin(), items.end())),
      array_(nullptr) {
  array_ = new value_type[capacity_];
  size_type i = 0;
  for (auto element : items) {
    array_[i] = element;
    ++i;
    ++size_;
  }
}

template <typename value_type>
Vector<value_type>::Vector(const Vector &other)
    : size_(other.size_), capacity_(other.capacity_), array_(nullptr) {
  array_ = new value_type[capacity_];
  for (size_type i = 0; i != other.size_; ++i) {
    array_[i] = other.array_[i];
  }
}

template <typename value_type>
Vector<value_type> &Vector<value_type>::operator=(const Vector &other) {
  if (this == &other) return *this;
  delete[] array_;
  array_ = new value_type[other.capacity_];
  for (size_type i = 0; i != other.size_; ++i) {
    array_[i] = other.array_[i];
  }
  size_ = other.size_;
  return *this;
}

template <typename value_type>
Vector<value_type>::Vector(Vector &&other) noexcept
    : size_(other.size_), capacity_(other.capacity_), array_(other.array_) {
  other.size_ = 0;
  other.capacity_ = 0;
  other.array_ = nullptr;
}

template <typename value_type>
Vector<value_type> &Vector<value_type>::operator=(Vector &&other) noexcept {
  if (this == &other) return *this;
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(array_, other.array_);
  return *this;
}

template <typename value_type>
Vector<value_type>::~Vector() {
  delete[] array_;
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::At(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Index out of range");
  return array_[pos];
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  if (pos >= size_) throw std::out_of_range("Index out of range");
  return array_[pos];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::Front() const {
  return array_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::Back() const {
  return array_[size_ - 1];
}

template <typename value_type>
typename Vector<value_type>::value_type *Vector<value_type>::Data() {
  return &array_[0];
}

template <typename value_type>
bool Vector<value_type>::Empty() {
  return !size_;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::Size() {
  return size_;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::MaxSize() {
  return (std::numeric_limits<std::size_t>::max() / sizeof(value_type)) / 2;
}

template <typename value_type>
void Vector<value_type>::Reserve(size_type size) {
  if (capacity_ < size) {
    auto *tmp = new value_type[size];
    std::move(array_, array_ + size_, tmp);
    delete[] array_;
    array_ = tmp;
    capacity_ = size;
  }
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::Capacity() {
  return capacity_;
}

template <typename value_type>
void Vector<value_type>::ShrinkToFit() {
  if (size_ < capacity_) {
    auto *newArray = new value_type[size_];
    std::move(array_, array_ + size_, newArray);
    delete[] array_;
    array_ = newArray;
    capacity_ = size_;
  }
}

template <typename value_type>
void Vector<value_type>::Clear() {
  for (size_t i = 0; i < size_; ++i) array_[i].~value_type();
  size_ = 0;
}

template <typename value_type>
void Vector<value_type>::PushBack(const_reference value) {
  if (size_ == 0) {
    array_ = new value_type[1];
    array_[0] = value;
    size_ = 1;
    capacity_ = 1;
  } else if (size_ >= capacity_) {
    auto *copy = new value_type[capacity_ * 2];
    std::move(array_, array_ + size_, copy);
    delete[] array_;
    array_ = copy;
    array_[size_] = value;
    ++size_;
    capacity_ *= 2;
  } else {
    array_[size_] = value;
    ++size_;
  }
}

template <typename value_type>
void Vector<value_type>::PopBack() {
  array_[size_ - 1].~value_type();
  --size_;
}

template <typename value_type>
void Vector<value_type>::Swap(Vector &other) {
  if (this == &other) return;
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(array_, other.array_);
}

template <typename value_type>
Vector<value_type>::iterator::iterator() : it_(nullptr) {}

template <typename value_type>
Vector<value_type>::iterator::iterator(value_type *it) : it_(it) {}

template <typename value_type>
typename Vector<value_type>::value_type
Vector<value_type>::iterator::operator*() {
  if (it_ == nullptr) {
    throw std::out_of_range("Iterator is dereferenced at end");
  }
  return *it_;
}

template <typename value_type>
typename Vector<value_type>::iterator &
Vector<value_type>::iterator::operator++() {
  if (it_ != nullptr) ++it_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator++(
    int) {
  iterator tmp = *this;
  if (it_ != nullptr) ++it_;
  return tmp;
}

template <typename value_type>
typename Vector<value_type>::iterator &
Vector<value_type>::iterator::operator--() {
  if (it_ != nullptr) --it_;
  return *this;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator--(
    int) {
  iterator tmp = *this;
  if (it_ != nullptr) --it_;
  return tmp;
}

template <typename value_type>
bool Vector<value_type>::iterator::operator==(const iterator &other) const {
  return it_ == other.it_;
}

template <typename value_type>
bool Vector<value_type>::iterator::operator!=(const iterator &other) const {
  return it_ != other.it_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::Begin() {
  if (array_ == nullptr) return End();
  return iterator(array_);
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::End() {
  return iterator(array_ + size_);
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::Insert(
    iterator pos, const_reference value) {
  // может быть не совместимость так как выделение памяти может расти в другую
  // сторону
  size_type insertPos = pos.it_ - array_;

  if (size_ == capacity_) {
    size_type newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    value_type *newArray = new value_type[newCapacity];

    std::move(array_, array_ + insertPos, newArray);
    newArray[insertPos] = value;
    std::move(array_ + insertPos, array_ + size_, newArray + insertPos + 1);

    delete[] array_;
    array_ = newArray;
    capacity_ = newCapacity;
  } else {
    std::move_backward(array_ + insertPos, array_ + size_, array_ + size_ + 1);
    array_[insertPos] = value;
  }

  ++size_;
  return iterator(array_ + insertPos);
}

template <typename value_type>
void Vector<value_type>::Erase(iterator pos) {
  size_type erasePos = pos.it_ - array_;
  std::move(array_ + erasePos + 1, array_ + size_, array_ + erasePos);
  --size_;
  array_[size_].~value_type();
}

// additional methods
template <typename value_type>
void Vector<value_type>::Print() {
  for (size_t i = 0; i != size_; ++i) std::cout << array_[i] << ' ';
  std::cout << std::endl;
}

template <typename value_type>
template <class... Args>
typename Vector<value_type>::iterator Vector<value_type>::InsertMany(
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
void Vector<value_type>::InsertManyBack(Args &&...args) {
  (this->PushBack(std::forward<Args>(args)), ...);
}

}  // namespace s21

#endif  // S21Containers_SRC_S21_VECTOR_H_