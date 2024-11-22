#include <stack>

#include "tests.h"

TEST(Stack, Default) {
  s21::Stack<int> our_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(our_stack.Empty(), std_stack.empty());
}

TEST(Stack, Int_Elements) {
  s21::Stack<int> our_stack = {14, 2, 1992};
  std::stack<int> std_stack;
  std_stack.push(14);
  std_stack.push(2);
  std_stack.push(1992);
  EXPECT_EQ(our_stack.Top(), std_stack.top());
}

TEST(Stack, Copy) {
  s21::Stack<int> our_stack = {14, 2, 1992};
  s21::Stack<int> our_copy(our_stack);
  std::stack<int> std_stack;
  std_stack.push(14);
  std_stack.push(2);
  std_stack.push(1992);
  std::stack<int> std_copy(std_stack);
  EXPECT_EQ(our_copy.Top(), std_copy.top());
}

TEST(Stack, Copy_Operator) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  s21::Stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.Top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.Empty(), std_stack_int.empty());
}

TEST(Stack, Move) {
  s21::Stack<int> our_stack = {14, 2, 1992};
  s21::Stack<int> our_move(std::move(our_stack));
  std::stack<int> std_stack;
  std_stack.push(14);
  std_stack.push(2);
  std_stack.push(1992);
  std::stack<int> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.Top(), std_move.top());
  EXPECT_EQ(our_stack.Empty(), std_stack.empty());
}

TEST(Stack, Move_Operator) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  s21::Stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = std::move(our_stack_int);
  std_stack_empty = std::move(std_stack_int);
  EXPECT_EQ(our_stack_empty.Top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.Empty(), std_stack_int.empty());
}

TEST(Stack, Top) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  s21::Stack<double> our_stack_double = {14.1f, 2.1f, 1992.1f};
  std::stack<double> std_stack_double;
  std_stack_double.push(14.1f);
  std_stack_double.push(2.1f);
  std_stack_double.push(1992.1f);
  s21::Stack<std::string> our_stack_string = {"Rus", "lan", "c++"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("Rus");
  std_stack_string.push("lan");
  std_stack_string.push("c++");
  EXPECT_EQ(our_stack_int.Top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.Top(), std_stack_double.top());
  EXPECT_EQ(our_stack_string.Top(), std_stack_string.top());
}

TEST(Stack, Empty) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  EXPECT_EQ(our_stack_int.Empty(), std_stack_int.empty());
  s21::Stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.Empty(), std_stack_empty.empty());
}

TEST(Stack, Size) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  EXPECT_EQ(our_stack_int.Size(), std_stack_int.size());
  s21::Stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.Size(), std_stack_empty.size());
}

TEST(Stack, Push) {
  s21::Stack<int> our_stack_int;
  our_stack_int.Push(14);
  our_stack_int.Push(2);
  our_stack_int.Push(1992);
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  EXPECT_EQ(our_stack_int.Top(), std_stack_int.top());
}

TEST(Stack, Pop) {
  s21::Stack<int> our_stack_int;
  our_stack_int.Push(14);
  our_stack_int.Push(2);
  our_stack_int.Push(1992);
  our_stack_int.Pop();
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1922);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.Top(), std_stack_int.top());
}

TEST(Stack, Swap) {
  s21::Stack<int> our_stack_int = {14, 2, 1992};
  std::stack<int> std_stack_int;
  std_stack_int.push(14);
  std_stack_int.push(2);
  std_stack_int.push(1992);
  s21::Stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty.Swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.Top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.Empty(), std_stack_int.empty());
}

TEST(Stack, InsertManyFront) {
  s21::Stack<int> our_stack_int;
  our_stack_int.InsertManyFront(1992, 14, 2);
  EXPECT_EQ(our_stack_int.Top(), 1992);
}
