#ifndef S21_STACK_H
#define S21_STACK_H

#include "s21_list.h"

namespace s21 {
template <typename T, class Container = s21::List<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = T const&;
  using size_type = size_t;

  Stack() : container_(){};
  Stack(std::initializer_list<value_type> const& items) : container_(items){};
  Stack(Stack const& s) : container_(s.container_){};

  Stack& operator=(Stack const& s) {
    container_ = s.container_;
    return *this;
  }

  Stack(Stack&& s) noexcept : container_(std::move(s.container_)){};

  Stack& operator=(Stack&& s) noexcept {
    container_ = std::move(s.container_);
    return *this;
  }

  ~Stack() = default;

  const_reference Top() { return container_.Back(); }
  bool Empty() { return container_.IsEmpty(); }
  size_type Size() { return container_.Size(); }
  void Push(const_reference value) { container_.PushBack(value); }
  void Pop() { container_.PopBack(); }
  void Swap(Stack& other) { container_.Swap(other.container_); }

  template <typename... Args>
  void InsertManyFront(Args&&... args) {
    container_.InsertManyFront(args...);
  }

 private:
  Container container_;
};
}  // namespace s21

#endif  // S21_STACK_H
