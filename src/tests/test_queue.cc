#include <queue>

#include "tests.h"

TEST(Queue, Default) {
  s21::Queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.Empty(), std_queue.empty());
}

TEST(Queue, Int_Elements) {
  s21::Queue<int> our_queue = {14, 2, 1992};
  std::queue<int> std_queue;
  std_queue.push(14);
  std_queue.push(2);
  std_queue.push(1992);
  EXPECT_EQ(our_queue.Front(), std_queue.front());
  EXPECT_EQ(our_queue.Back(), std_queue.back());
}

TEST(Queue, Copy) {
  s21::Queue<int> our_queue = {14, 2, 1992};
  s21::Queue<int> our_copy(our_queue);
  std::queue<int> std_queue;
  std_queue.push(14);
  std_queue.push(2);
  std_queue.push(1992);
  std::queue<int> std_copy(std_queue);
  EXPECT_EQ(our_copy.Front(), std_copy.front());
  EXPECT_EQ(our_copy.Back(), std_copy.back());
}

TEST(Queue, Copy_Operator) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  s21::Queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = our_queue_int;
  std_queue_empty = std_queue_int;
  EXPECT_EQ(our_queue_empty.Front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.Back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.Empty(), std_queue_int.empty());
}

TEST(Queue, Move) {
  s21::Queue<int> our_queue = {14, 2, 1992};
  s21::Queue<int> our_move(std::move(our_queue));
  std::queue<int> std_queue;
  std_queue.push(14);
  std_queue.push(2);
  std_queue.push(1992);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.Front(), std_move.front());
  EXPECT_EQ(our_move.Back(), std_move.back());
  EXPECT_EQ(our_queue.Empty(), std_queue.empty());
}

TEST(Queue, Move_Operator) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  s21::Queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = std::move(our_queue_int);
  std_queue_empty = std::move(std_queue_int);
  EXPECT_EQ(our_queue_empty.Front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.Back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.Empty(), std_queue_int.empty());
}

TEST(Queue, Check_Front_And_Back) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  s21::Queue<double> our_queue_double = {1.1f, 2.1f, 3.1f};
  std::queue<double> std_queue_double;
  std_queue_double.push(1.1f);
  std_queue_double.push(2.1f);
  std_queue_double.push(3.1f);
  s21::Queue<std::string> our_queue_string = {"rus", "lan", "c++"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("rus");
  std_queue_string.push("lan");
  std_queue_string.push("c++");
  EXPECT_EQ(our_queue_int.Front(), std_queue_int.front());
  EXPECT_EQ(our_queue_double.Front(), std_queue_double.front());
  EXPECT_EQ(our_queue_string.Front(), std_queue_string.front());
  EXPECT_EQ(our_queue_int.Back(), std_queue_int.back());
  EXPECT_EQ(our_queue_double.Back(), std_queue_double.back());
  EXPECT_EQ(our_queue_string.Back(), std_queue_string.back());
}

TEST(Queue, Empty) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  EXPECT_EQ(our_queue_int.Empty(), std_queue_int.empty());
  s21::Queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.Empty(), std_queue_empty.empty());
}

TEST(Queue, Size) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  EXPECT_EQ(our_queue_int.Size(), std_queue_int.size());
  s21::Queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.Size(), std_queue_empty.size());
}

TEST(Queue, Push) {
  s21::Queue<int> our_queue_int;
  our_queue_int.Push(14);
  our_queue_int.Push(2);
  our_queue_int.Push(1992);
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  EXPECT_EQ(our_queue_int.Front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.Back(), std_queue_int.back());
}

TEST(Queue, Pop) {
  s21::Queue<int> our_queue_int;
  our_queue_int.Push(14);
  our_queue_int.Push(2);
  our_queue_int.Push(1992);
  our_queue_int.Pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.Front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.Back(), std_queue_int.back());
  EXPECT_EQ(our_queue_int.Empty(), std_queue_int.empty());
}

TEST(Queue, Swap) {
  s21::Queue<int> our_queue_int = {14, 2, 1992};
  std::queue<int> std_queue_int;
  std_queue_int.push(14);
  std_queue_int.push(2);
  std_queue_int.push(1992);
  s21::Queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty.Swap(our_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(our_queue_empty.Front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.Back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.Empty(), std_queue_int.empty());
}

TEST(Queue, InsertManyBack) {
  s21::Queue<int> our_queue_int;
  our_queue_int.InsertManyBack(14, 2, 1992);
  EXPECT_EQ(our_queue_int.Front(), 14);
  EXPECT_EQ(our_queue_int.Back(), 1992);
}