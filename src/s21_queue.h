#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "s21_list.h"

namespace s21 {
template <typename T, class Container = s21::List<T>>
class Queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = T const&;
  using size_type = size_t;

  Queue() : container_(){};
  Queue(std::initializer_list<value_type> const& items) : container_(items){};
  Queue(Queue const& q) : container_(q.container_){};

  Queue& operator=(Queue const& q) {
    container_ = q.container_;
    return *this;
  }

  Queue(Queue&& q) noexcept : container_(std::move(q.container_)){};

  Queue& operator=(Queue&& q) noexcept {
    container_ = std::move(q.container_);
    return *this;
  }

  ~Queue() = default;

  const_reference Front() { return container_.Front(); }
  const_reference Back() { return container_.Back(); }
  bool Empty() { return container_.IsEmpty(); }
  size_type Size() { return container_.Size(); }
  void Push(const_reference value) { container_.PushBack(value); }
  void Pop() { container_.PopFront(); }
  void Swap(Queue& other) { container_.Swap(other.container_); }

  template <typename... Args>
  void InsertManyBack(Args&&... args) {
    container_.InsertManyBack(args...);
  }

 private:
  Container container_;
};
}  // namespace s21

#endif  // S21_QUEUE_H
