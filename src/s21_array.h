#ifndef S21Containers_SRC_S21_ARRAY_H_
#define S21Containers_SRC_S21_ARRAY_H_

#include <algorithm>  // std::copy std::move std::fill and std::swap_ranges
#include <initializer_list>
#include <stdexcept>  // using for std::out_of_range
#include <utility>    // using for std::move and std::swap

namespace s21 {
template <typename T, std::size_t N>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  Array();
  Array(std::initializer_list<value_type> const &items);

  Array(const Array &other);
  Array &operator=(const Array &other);

  Array(Array &&other) noexcept;
  Array &operator=(Array &&other) noexcept;

  ~Array();

  reference At(size_type pos);
  reference operator[](size_type pos);
  const_reference Front() const;
  const_reference Back() const;

  bool Empty();
  size_type Size();
  size_type MaxSize();

  void Swap(Array &other);
  void Fill(const_reference value);

  struct iter {
    iter();
    explicit iter(iterator it);
    value_type operator*();
    iter &operator++();
    iter operator++(int);
    iter &operator--();
    iter operator--(int);
    bool operator==(const_iterator &other) const;
    bool operator!=(const_iterator &other) const;
    iterator it_;
  };

  iterator Data();

  iterator Begin();
  iterator End();

 private:
  value_type array_[N > 0 ? N : 1];
};

template <typename value_type, std::size_t N>
Array<value_type, N>::Array() : array_{} {}

template <typename value_type, std::size_t N>
Array<value_type, N>::Array(std::initializer_list<value_type> const &items) {
  if (items.size() > N) {
    throw std::out_of_range("Initializer list size exceeds array size");
  }
  std::copy(items.begin(), items.end(), array_);
}

template <typename value_type, std::size_t N>
Array<value_type, N>::Array(const Array &other) {
  for (size_t i = 0; i != N; ++i) {
    array_[i] = other.array_[i];
  }
}

template <typename value_type, std::size_t N>
Array<value_type, N> &Array<value_type, N>::operator=(const Array &other) {
  if (this == &other) return *this;
  for (size_t i = 0; i != N; ++i) array_[i] = other.array_[i];
  return *this;
}

template <typename value_type, std::size_t N>
Array<value_type, N>::Array(Array &&other) noexcept {
  std::move(other.array_, other.array_ + N, array_);
}

template <typename value_type, std::size_t N>
Array<value_type, N> &Array<value_type, N>::operator=(Array &&other) noexcept {
  if (this == &other) return *this;
  std::move(other.array_, other.array_ + N, array_);
  return *this;
}

template <typename value_type, std::size_t N>
Array<value_type, N>::~Array() {
  for (size_t i = 0; i != N; ++i) {
    array_[i].~value_type();
  }
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::reference Array<value_type, N>::At(
    size_type pos) {
  if (pos >= N) throw std::out_of_range("Index out of range");
  return array_[pos];
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::reference Array<value_type, N>::operator[](
    size_type pos) {
  if (pos >= N) throw std::out_of_range("Index out of range");
  return array_[pos];
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::const_reference Array<value_type, N>::Front()
    const {
  return array_[0];
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::const_reference Array<value_type, N>::Back()
    const {
  return array_[N - 1];
}

template <typename value_type, std::size_t N>
bool Array<value_type, N>::Empty() {
  return N <= 0 ? true : false;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::size_type Array<value_type, N>::Size() {
  return N;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::size_type Array<value_type, N>::MaxSize() {
  return N;
}

template <typename value_type, std::size_t N>
void Array<value_type, N>::Swap(Array &other) {
  if (this == &other) return;
  std::swap(array_, other.array_);
}

template <typename value_type, std::size_t N>
void Array<value_type, N>::Fill(const_reference value) {
  for (size_t i = 0; i != Size(); ++i) array_[i] = value;
}

template <typename value_type, std::size_t N>
Array<value_type, N>::iter::iter() : it_(nullptr) {}

template <typename value_type, std::size_t N>
Array<value_type, N>::iter::iter(iterator it) : it_(it) {}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::value_type
Array<value_type, N>::iter::operator*() {
  if (it_ == nullptr)
    throw std::out_of_range("Iterator is dereferenced at end");
  return *it_;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iter &Array<value_type, N>::iter::operator++() {
  if (it_ != nullptr) ++it_;
  return *this;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iter Array<value_type, N>::iter::operator++(
    int) {
  iter tmp = *this;
  if (it_ != nullptr) ++it_;
  return tmp;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iter &Array<value_type, N>::iter::operator--() {
  if (it_ != nullptr) --it_;
  return *this;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iter Array<value_type, N>::iter::operator--(
    int) {
  iter tmp = *this;
  if (it_ != nullptr) --it_;
  return tmp;
}

template <typename value_type, std::size_t N>
bool Array<value_type, N>::iter::operator==(const_iterator &other) const {
  return it_ == other->it_;
}

template <typename value_type, std::size_t N>
bool Array<value_type, N>::iter::operator!=(const_iterator &other) const {
  return it_ != other->it_;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iterator Array<value_type, N>::Data() {
  return array_;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iterator Array<value_type, N>::Begin() {
  return array_;
}

template <typename value_type, std::size_t N>
typename Array<value_type, N>::iterator Array<value_type, N>::End() {
  return array_ + N;
}

}  // namespace s21

#endif  // S21Containers_SRC_S21_ARRAY_H_
