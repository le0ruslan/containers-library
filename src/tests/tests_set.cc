#include <set>

#include "tests.h"

TEST(Set, BeginHead) { std::cout << "\n------------------\n"; }

TEST(Set, Begin1) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  auto myIt = MySet.Begin();
  auto stdIt = StdSet.begin();

  // Assert
  EXPECT_EQ(*myIt, *stdIt);
}

TEST(Set, Begin2) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto stdIt = StdSet.begin();

  // Assert
  EXPECT_DOUBLE_EQ(*myIt, *stdIt);
}

TEST(Set, Begin3) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto stdIt = StdSet.begin();

  // Assert
  EXPECT_DOUBLE_EQ(*myIt, *stdIt);
}

TEST(Set, Begin4) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto stdIt = StdSet.begin();

  // Assert
  EXPECT_DOUBLE_EQ(*myIt, *stdIt);
}

TEST(Set, ClearHead) { std::cout << "\n------------------\n"; }

TEST(Set, Clear) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear2) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  std::set<int> StdSet{9, 30, 11, 34, 54};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear3) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Clear8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  MySet.Clear();
  StdSet.clear();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ContainsHead) { std::cout << "\n------------------\n"; }

TEST(Set, Contains1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};

  // Act
  auto flagsMy = MySet.Contains(3);

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains2) {
  // Arrange
  s21::Set<int> MySet{10, 3, 4, 8, 0, 11};

  // Act
  auto flagsMy = MySet.Contains(11);

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains3) {
  // Arrange
  s21::Set<double> MySet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  // Act
  auto flagsMy = MySet.Contains(0.15);

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains4) {
  // Arrange
  s21::Set<char> MySet{'a', '3', '4', 'i', '!', '*', '('};

  // Act
  auto flagsMy = MySet.Contains('!');

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains5) {
  // Arrange
  s21::Set<char> MySet{'1', '2', '3', '4', '9'};

  // Act
  auto flagsMy = MySet.Contains('9');

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains6) {
  // Arrange
  s21::Set<char> MySet{'u', '%', '8', '2', ','};

  // Act
  auto flagsMy = MySet.Contains('%');

  // Assert
  EXPECT_EQ(flagsMy, true);
}

TEST(Set, Contains7) {
  // Arrange
  s21::Set<double> MySet{4.432, 1.234, 1.324, 0.43, 88.123};

  // Act
  auto flagsMy = MySet.Contains(5);

  // Assert
  EXPECT_EQ(flagsMy, false);
}

TEST(Set, Contains8) {
  // Arrange
  s21::Set<int> MySet{3, 85, 9, 12, 11, 10};

  // Act
  auto flagsMy = MySet.Contains(5);

  // Assert
  EXPECT_EQ(flagsMy, false);
}

TEST(Set, CopyConstrHead) { std::cout << "\n------------------\n"; }

TEST(Set, CopyConstr1) {
  // Arrange
  s21::Set<int> MySet{3, 78, 98};
  std::set<int> StdSet{3, 78, 98};

  // Act
  s21::Set<int> MySet2(MySet);
  std::set<int> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr2) {
  // Arrange
  s21::Set<double> MySet{3.33, 78.78, 98.98};
  std::set<double> StdSet{3.33, 78.78, 98.98};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr3) {
  // Arrange
  s21::Set<double> MySet{3.1234, 78.9876, 123.456};
  std::set<double> StdSet{3.1234, 78.9876, 123.456};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2(MySet);
  std::set<char> StdSet2(StdSet);
  auto myIt = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, CopyConstr7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2(MySet);
  std::set<char> StdSet2(StdSet);
  auto myIt = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, CopyConstr9) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr10) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2(MySet);
  std::set<char> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr11) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyConstr12) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2(MySet);
  std::set<char> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperatorHead) { std::cout << "\n------------------\n"; }

TEST(Set, CopyOperator1) {
  // Arrange
  s21::Set<int> MySet{3, 78, 98};
  std::set<int> StdSet{3, 78, 98};

  // Act
  s21::Set<int> MySet2 = MySet;
  std::set<int> StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator2) {
  // Arrange
  s21::Set<double> MySet{3.33, 78.78, 98.98};
  std::set<double> StdSet{3.33, 78.78, 98.98};

  // Act
  s21::Set<double> MySet2 = MySet;
  std::set<double> StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator3) {
  // Arrange
  s21::Set<double> MySet{3.1234, 78.9876, 123.456};
  std::set<double> StdSet{3.1234, 78.9876, 123.456};

  // Act
  s21::Set<double> MySet2 = MySet;
  std::set<double> StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2 = MySet;
  std::set<double> StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2 = MySet;
  std::set<char> StdSet2 = StdSet;
  auto myIt = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, CopyOperator7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  MySet = MySet;
  StdSet = StdSet;
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  MySet = MySet;
  StdSet = StdSet;
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, CopyOperator9) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2 = MySet;
  std::set<double> StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator10) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  s21::Set<char> MySet2;
  std::set<char> StdSet2;
  MySet2 = MySet;
  StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator11) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  s21::Set<double> MySet2(MySet);
  std::set<double> StdSet2(StdSet);
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, CopyOperator12) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};
  s21::Set<char> MySet2{'5', '2', 'a', 'p', '='};
  std::set<char> StdSet2{'5', '2', 'a', 'p', '='};

  // Act
  MySet2 = MySet;
  StdSet2 = StdSet;
  auto itMy = MySet2.Begin();
  auto itStd = StdSet2.begin();

  // Assert
  for (; itMy != MySet2.End(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(Set, ConstrHead) { std::cout << "\n------------------\n"; }

TEST(Set, Constr) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act
  std::set<int>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr2) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  std::set<int> StdSet{9, 30, 11, 34, 54};

  // Act
  std::set<int>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr3) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  std::set<int>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  std::set<double>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  std::set<char>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  std::set<double>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, Constr8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  std::set<char>::iterator it = StdSet.begin();
  auto itMy = MySet.Begin();

  // Assert
  for (; itMy != MySet.End(); ++itMy, ++it) {
    EXPECT_EQ(*it, *itMy);
  }
}

TEST(Set, EmptyHead) { std::cout << "\n------------------\n"; }

TEST(Set, Empty) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty2) {
  // Arrange
  s21::Set<int> MySet;
  std::set<int> StdSet;

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty3) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  // std::set<char>::iterator it = StdSet.begin();

  // Assert
}

TEST(Set, Empty9) {
  // Arrange
  s21::Set<double> MySet;
  std::set<double> StdSet;

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, Empty10) {
  // Arrange
  s21::Set<char> MySet;
  std::set<char> StdSet;

  // Act

  // Assert
  EXPECT_EQ(MySet.Empty(), StdSet.empty());
}

TEST(Set, EraseHead) { std::cout << "\n------------------\n"; }

TEST(Set, Erase1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};
  std::set<int> StdSet{1, 2, 3, 4};

  // Act
  auto itMy = MySet.Begin();
  MySet.Erase(itMy);
  auto itStd = StdSet.begin();
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itM != MySet.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase2) {
  // Arrange
  s21::Set<int> MySet{10, 3, 4, 8, 0, 11};
  std::set<int> StdSet{10, 3, 4, 8, 0, 11};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  MySet.Erase(itMy);
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itS != StdSet.end(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase3) {
  // Arrange
  s21::Set<double> MySet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> StdSet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  MySet.Erase(itMy);
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itS != StdSet.end(); ++itM, ++itS) {
    EXPECT_DOUBLE_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase4) {
  // Arrange
  s21::Set<char> MySet{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> StdSet{'a', '3', '4', 'i', '!', '*', '('};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  itMy--;
  ++itStd;
  ++itStd;
  ++itStd;
  itStd--;
  MySet.Erase(itMy);
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itS != StdSet.end(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase5) {
  // Arrange
  s21::Set<char> MySet{'1', '2', '3', '4', '9'};
  std::set<char> StdSet{'1', '2', '3', '4', '9'};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  --itMy;
  ++itStd;
  ++itStd;
  ++itStd;
  --itStd;
  MySet.Erase(itMy);
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itM != MySet.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase6) {
  // Arrange
  s21::Set<char> MySet{'u', '%', '8', '2', ','};
  std::set<char> StdSet{'u', '%', '8', '2', ','};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  ++itMy;
  ++itMy;
  itMy--;
  ++itStd;
  ++itStd;
  itStd--;
  MySet.Erase(itMy);
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itM != MySet.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase7) {
  // Arrange
  s21::Set<double> MySet{4.432, 1.234, 1.324, 0.43, 88.123};
  std::set<double> StdSet{4.432, 1.234, 1.324, 0.43, 88.123};

  // Act
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();
  MySet.Erase(itMy);
  StdSet.erase(itStd);

  auto itMy2 = MySet.Begin();
  auto itStd2 = StdSet.begin();
  MySet.Erase(itMy2);
  StdSet.erase(itStd2);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itM != MySet.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Erase8) {
  // Arrange
  s21::Set<int> MySet{3, 85, 9, 12, 11, 10};
  std::set<int> StdSet{3, 85, 9, 12, 11, 10};

  // Act
  auto itMy = MySet.Begin();
  MySet.Erase(itMy);
  auto itStd = StdSet.begin();
  StdSet.erase(itStd);
  auto itM = MySet.Begin();
  auto itS = StdSet.begin();

  // Assert
  for (; itM != MySet.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, FindHead) { std::cout << "\n------------------\n"; }

TEST(Set, Find1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};
  std::set<int> StdSet{1, 2, 3, 4};

  // Act
  auto serMy = MySet.Find(3);
  auto serStd = StdSet.find(3);

  // Assert
  EXPECT_EQ(*serMy, *serStd);
}

TEST(Set, Find2) {
  // Arrange
  s21::Set<int> MySet{10, 3, 4, 8, 0, 11};
  std::set<int> StdSet{10, 3, 4, 8, 0, 11};

  // Act
  auto serMy = MySet.Find(0);
  auto serStd = StdSet.find(0);

  // Assert
  EXPECT_EQ(*serMy, *serStd);
}

TEST(Set, Find3) {
  // Arrange
  s21::Set<double> MySet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> StdSet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  // Act
  auto serMy = MySet.Find(8.14);
  auto serStd = StdSet.find(8.14);

  // Assert
  EXPECT_DOUBLE_EQ(*serMy, *serStd);
}

TEST(Set, Find4) {
  // Arrange
  s21::Set<char> MySet{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> StdSet{'a', '3', '4', 'i', '!', '*', '('};

  // Act
  auto serMy = MySet.Find('a');
  auto serStd = StdSet.find('a');

  // Assert
  EXPECT_EQ(*serMy, *serStd);
}

TEST(Set, Find5) {
  // Arrange
  s21::Set<char> MySet{'1', '2', '3', '4', '9'};
  std::set<char> StdSet{'1', '2', '3', '4', '9'};

  // Act
  auto serMy = MySet.Find('3');
  auto serStd = StdSet.find('3');

  // Assert
  EXPECT_EQ(*serMy, *serStd);
}

TEST(Set, Find6) {
  // Arrange
  s21::Set<char> MySet{'u', '%', '8', '2', ','};
  std::set<char> StdSet{'u', '%', '8', '2', ','};

  // Act
  auto serMy = MySet.Find('%');
  auto serStd = StdSet.find('%');

  // Assert
  EXPECT_EQ(*serMy, *serStd);
}

TEST(Set, Find7) {
  // Arrange
  s21::Set<double> MySet{4.432, 1.234, 1.324, 0.43, 88.123};
  std::set<double> StdSet{4.432, 1.234, 1.324, 0.43, 88.123};
  bool flagsMy = true;
  bool flagsStd = true;

  // Act
  auto serMy = MySet.Find(5);
  auto serStd = StdSet.find(5);
  if (serMy != MySet.End()) flagsMy = false;
  if (serStd != StdSet.end()) flagsStd = false;

  // Assert
  EXPECT_EQ(flagsMy, flagsStd);
}

TEST(Set, Find8) {
  // Arrange
  s21::Set<int> MySet{3, 85, 9, 12, 11, 10};
  std::set<int> StdSet{3, 85, 9, 12, 11, 10};
  bool flagsMy = true;
  bool flagsStd = true;

  // Act
  auto serMy = MySet.Find(0);
  auto serStd = StdSet.find(0);
  if (serMy == MySet.End()) flagsMy = false;
  if (serStd == StdSet.end()) flagsStd = false;

  // Assert
  EXPECT_EQ(flagsMy, false);
  EXPECT_EQ(false, flagsStd);
}

TEST(Set, InsertHead) { std::cout << "\n------------------\n"; }

TEST(Set, Insert1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};
  std::set<int> StdSet{1, 2, 3, 4};

  // Act
  auto serMy = MySet.Insert(3);
  auto serStd = StdSet.insert(3);

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert2) {
  // Arrange
  s21::Set<int> MySet{10, 3, 4, 8, 0, 11};
  std::set<int> StdSet{10, 3, 4, 8, 0, 11};

  // Act
  auto serMy = MySet.Insert(13);
  auto serStd = StdSet.insert(13);

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert3) {
  // Arrange
  s21::Set<double> MySet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> StdSet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  // Act
  auto serMy = MySet.Insert(100);
  auto serStd = StdSet.insert(100);

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert4) {
  // Arrange
  s21::Set<char> MySet{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> StdSet{'a', '3', '4', 'i', '!', '*', '('};

  // Act
  auto serMy = MySet.Insert('a');
  auto serStd = StdSet.insert('a');

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert5) {
  // Arrange
  s21::Set<char> MySet{'1', '2', '3', '4', '9'};
  std::set<char> StdSet{'1', '2', '3', '4', '9'};

  // Act
  auto serMy = MySet.Insert('a');
  auto serStd = StdSet.insert('a');

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert6) {
  // Arrange
  s21::Set<char> MySet{'u', '%', '8', '2', ','};
  std::set<char> StdSet{'u', '%', '8', '2', ','};

  // Act
  auto serMy = MySet.Insert('q');
  auto serStd = StdSet.insert('q');

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert7) {
  // Arrange
  s21::Set<double> MySet{4.432, 1.234, 1.324, 0.43, 88.123};
  std::set<double> StdSet{4.432, 1.234, 1.324, 0.43, 88.123};

  // Act
  auto serMy = MySet.Insert(5);
  auto serStd = StdSet.insert(5);

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, Insert8) {
  // Arrange
  s21::Set<int> MySet{3, 85, 9, 12, 11, 10};
  std::set<int> StdSet{3, 85, 9, 12, 11, 10};

  // Act
  auto serMy = MySet.Insert(0);
  auto serStd = StdSet.insert(0);

  // Assert
  for (; serMy.first != MySet.End(); ++serMy.first, ++serStd.first)
    EXPECT_EQ(*serMy.first, *serStd.first);
  EXPECT_EQ(serMy.second, serStd.second);
}

TEST(Set, ItOperatorHead) { std::cout << "\n------------------\n"; }

TEST(Set, ItOperator) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator2) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  std::set<int> StdSet{9, 30, 11, 34, 54};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator3) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; myIt != MySet.End(); ++myIt, ++itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator9) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();
  ++itStd;
  ++itStd;
  ++itStd;
  ++myIt;
  ++myIt;
  ++myIt;

  // Assert
  for (; myIt != MySet.Begin(); --myIt, --itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator10) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  std::set<int> StdSet{9, 30, 11, 34, 54};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt, --itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator12) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  auto myIt = MySet.Begin();
  std::set<int>::iterator itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt, --itStd) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator13) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator14) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator15) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator16) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator17) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  s21::Set<char> MySet2{'t', 'e', 'w', '[', 'a', '1'};

  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet2{'t', 'e', 'w', '[', 'a', '1'};
  bool myFlags = false;
  bool stdFlags = false;

  // Act
  auto myIt = MySet.Begin();
  auto myIt2 = MySet2.Begin();
  auto itStd = StdSet.begin();
  auto itStd2 = StdSet2.begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++myIt2;
    ++itStd;
    ++itStd2;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt, --myIt2, --itStd, --itStd2) {
    stdFlags = itStd2 == itStd;
    myFlags = myIt == myIt2;
    EXPECT_EQ(false, myFlags);
    EXPECT_EQ(false, stdFlags);
  }
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, ItOperator18) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  bool flags = false;

  // Act
  auto myIt = MySet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt) {
    flags = myIt == myIt;
    EXPECT_EQ(true, flags);
  }
}

TEST(Set, ItOperator19) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  bool flags = false;

  // Act
  auto myIt = MySet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt) {
    flags = myIt == myIt;
    EXPECT_EQ(true, flags);
  }
}

TEST(Set, ItOperator20) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  bool flags = false;

  // Act
  auto myIt = MySet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt) {
    flags = myIt == myIt;
    EXPECT_EQ(true, flags);
  }
}

TEST(Set, ItOperator21) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  s21::Set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  bool flags = true;

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    flags = myIt != itStd;
    EXPECT_EQ(flags, true);
  }
  EXPECT_EQ(MySet.Size(), StdSet.Size());
}

TEST(Set, ItOperator22) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  s21::Set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};
  bool flags = false;

  // Act
  auto myIt = MySet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); --myIt) {
    flags = myIt != myIt;
    EXPECT_EQ(false, flags);
  }
}

TEST(Set, ItOperator23) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  s21::Set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};
  bool flags = true;

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    flags = myIt != itStd;
    EXPECT_EQ(flags, true);
  }
  EXPECT_EQ(MySet.Size(), StdSet.Size());
}

TEST(Set, ItOperator24) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  s21::Set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  auto myIt = MySet.Begin();
  auto itStd = StdSet.Begin();
  size_t i = 0;
  while (i < MySet.Size() - 1) {
    ++myIt;
    ++itStd;
    ++i;
  }

  // Assert
  for (; myIt != MySet.Begin(); myIt--, itStd--) {
    EXPECT_EQ(*myIt, *itStd);
  }
  EXPECT_EQ(MySet.Size(), StdSet.Size());
}
// проверить на школьном маке
TEST(Set, MaxSizeHead) { std::cout << "\n------------------\n"; }

TEST(Set, MaxSize4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act

  // Assert
  EXPECT_EQ(MySet.MaxSize(), StdSet.max_size());
}

TEST(Set, MaxSize7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act

  // Assert
  EXPECT_EQ(MySet.MaxSize(), StdSet.max_size());
}

TEST(Set, MergeHead) { std::cout << "\n------------------\n"; }

TEST(Set, Merge1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};
  s21::Set<int> MySet2{5, 6, 7, 8};
  std::set<int> StdSet{1, 2, 3, 4};
  std::set<int> StdSet2{5, 6, 7, 8};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
}

TEST(Set, Merge2) {
  // Arrange
  s21::Set<int> MySet{10, 3, 4, 8, 0, 11};
  s21::Set<int> MySet2{10, 3, 4, 8, 0, 11};
  std::set<int> StdSet{10, 3, 4, 8, 0, 11};
  std::set<int> StdSet2{10, 3, 4, 8, 0, 11};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge3) {
  // Arrange
  s21::Set<double> MySet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  s21::Set<double> MySet2{34.33, 0.88, 123.3, 333};
  std::set<double> StdSet{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> StdSet2{34.33, 0.88, 123.3, 333};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge4) {
  // Arrange
  s21::Set<char> MySet{'a', '3', '4', 'i', '!', '*', '('};
  s21::Set<char> MySet2{'e', 'q', 'e', 'q'};
  std::set<char> StdSet{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> StdSet2{'e', 'q', 'e', 'q'};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge5) {
  // Arrange
  s21::Set<char> MySet{'1', '2', '3', '4', '9'};
  s21::Set<char> MySet2{'a', '!', ';', '*'};
  std::set<char> StdSet{'1', '2', '3', '4', '9'};
  std::set<char> StdSet2{'a', '!', ';', '*'};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge6) {
  // Arrange
  s21::Set<char> MySet{'u', '%', '8', '2', ','};
  s21::Set<char> MySet2{'c', 'h', 'a', 'r'};
  std::set<char> StdSet{'u', '%', '8', '2', ','};
  std::set<char> StdSet2{'c', 'h', 'a', 'r'};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge7) {
  // Arrange
  s21::Set<double> MySet{4.432, 1.234, 1.324, 0.43, 88.123};
  s21::Set<double> MySet2{4.432, 1.234, 1.324, 0.43, 88.123};
  std::set<double> StdSet{4.432, 1.234, 1.324, 0.43, 88.123};
  std::set<double> StdSet2{4.432, 1.234, 1.324, 0.43, 88.123};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, Merge8) {
  // Arrange
  s21::Set<int> MySet{3, 85, 9, 12, 11, 10};
  s21::Set<int> MySet2{123, 32, 444, 5534, 123232};
  std::set<int> StdSet{3, 85, 9, 12, 11, 10};
  std::set<int> StdSet2{123, 32, 444, 5534, 123232};

  // Act
  MySet.Merge(MySet2);
  StdSet.merge(StdSet2);
  auto itMy = MySet.Begin();
  auto itStd = StdSet.begin();

  // Assert
  for (; itStd != StdSet.end(); ++itMy, ++itStd) EXPECT_EQ(*itStd, *itMy);
  EXPECT_EQ(MySet.Size(), StdSet.size());
  EXPECT_EQ(MySet2.Size(), StdSet2.size());
}

TEST(Set, MoveAssignHead) { std::cout << "\n------------------\n"; }

TEST(Set, MoveAssign) {
  // Arrange
  s21::Set<double> MySet{3.33, 8.88, 10.11};

  // Act
  s21::Set<double> MySet2 = std::move(MySet);
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 3.33);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 8.88);
}

TEST(Set, MoveAssign2) {
  // Arrange
  s21::Set<double> MySet{3.1234, 78.9876, 123.456};
  std::set<double> StdSet{3.1234, 78.9876, 123.456};

  // Act
  s21::Set<double> MySet2;
  MySet2 = std::move(MySet);
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 3.1234);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 78.9876);
}

TEST(Set, MoveAssign3) {
  // Arrange
  s21::Set<int> MySet{33, 88, 11};

  // Act
  s21::Set<int> MySet2 = std::move(MySet);
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 11);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 33);
}

TEST(Set, MoveAssign4) {
  // Arrange
  s21::Set<std::string> MySet{"Sergei Popov", "8.88", "S21School"};
  std::set<std::string> StdSet{"Sergei Popov", "8.88", "S21School"};

  // Act
  s21::Set<std::string> MySet2 = std::move(MySet);
  auto itStd = StdSet.begin();
  auto itMy = MySet2.Begin();

  // Assert
  for (; itMy != MySet.Begin(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
}

TEST(Set, MoveAssign5) {
  // Arrange
  s21::Set<std::string> MySet{"sergei", "int", "double"};
  std::set<std::string> StdSet{"sergei", "int", "double"};

  // Act
  s21::Set<std::string> MySet2 = std::move(MySet);
  auto itStd = StdSet.begin();
  auto itMy = MySet2.Begin();

  // Assert
  for (; itMy != MySet.Begin(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
}

TEST(Set, MoveCstorHead) { std::cout << "\n------------------\n"; }

TEST(Set, MoveCstor) {
  // Arrange
  s21::Set<double> MySet{3.33, 8.88, 10.11};

  // Act
  s21::Set<double> MySet2(std::move(MySet));
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 3.33);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 8.88);
}

TEST(Set, MoveCstor2) {
  // Arrange
  s21::Set<double> MySet{3.1234, 78.9876, 123.456};
  std::set<double> StdSet{3.1234, 78.9876, 123.456};

  // Act
  s21::Set<double> MySet2(std::move(MySet));
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 3.1234);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 78.9876);
}

TEST(Set, MoveCstor3) {
  // Arrange
  s21::Set<int> MySet{33, 88, 11};

  // Act
  s21::Set<int> MySet2(std::move(MySet));
  auto itMy = MySet2.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(*itMy, 11);
  ++itMy;
  EXPECT_DOUBLE_EQ(*itMy, 33);
}

TEST(Set, MoveCstor4) {
  // Arrange
  s21::Set<std::string> MySet{"Sergei Popov", "8.88", "S21School"};
  std::set<std::string> StdSet{"Sergei Popov", "8.88", "S21School"};

  // Act
  s21::Set<std::string> MySet2(std::move(MySet));
  auto itStd = StdSet.begin();
  auto itMy = MySet2.Begin();

  // Assert
  for (; itMy != MySet.Begin(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
}

TEST(Set, MoveCstor5) {
  // Arrange
  s21::Set<std::string> MySet{"sergei", "int", "double"};
  std::set<std::string> StdSet{"sergei", "int", "double"};

  // Act
  s21::Set<std::string> MySet2(std::move(MySet));
  auto itStd = StdSet.begin();
  auto itMy = MySet2.Begin();

  // Assert
  for (; itMy != MySet.Begin(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
}

TEST(Set, SizeHead) { std::cout << "\n------------------\n"; }

TEST(Set, Size) {
  // Arrange
  s21::Set<int> MySet{1, 3, 4, 4, 5};
  std::set<int> StdSet{1, 3, 4, 4, 5};

  // Act
  // std::set<int>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size2) {
  // Arrange
  s21::Set<int> MySet{9, 30, 11, 34, 54};
  std::set<int> StdSet{9, 30, 11, 34, 54};

  // Act
  // std::set<int>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size3) {
  // Arrange
  s21::Set<int> MySet{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> StdSet{1, 3, 54, 33, 1, 43, 34, 43};

  // Act
  // std::set<int>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size4) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89, 2.12, 1.11, 8.321, 9.222, 10.321};

  // Act
  // std::set<double>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size5) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 't', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 't', 'w', '[', 'a', '1'};

  // Act
  // std::set<char>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size7) {
  // Arrange
  s21::Set<double> MySet{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};
  std::set<double> StdSet{45.123, 3.89,  2.12,  45.123,
                          1.11,   8.321, 9.222, 10.321};

  // Act
  // std::set<double>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, Size8) {
  // Arrange
  s21::Set<char> MySet{'t', 'e', 'w', '[', 'a', '1'};
  std::set<char> StdSet{'t', 'e', 'w', '[', 'a', '1'};

  // Act
  // std::set<char>::iterator it = StdSet.begin();

  // Assert
  EXPECT_EQ(MySet.Size(), StdSet.size());
}

TEST(Set, SwapHead) { std::cout << "\n------------------\n"; }

TEST(Set, Swap1) {
  // Arrange
  s21::Set<int> MySet{1, 2, 3, 4};
  s21::Set<int> MySet2{5, 6, 7};

  // Act
  MySet.Swap(MySet2);
  auto itMy = MySet.Begin();
  auto itMy2 = MySet2.Begin();

  // Assert
  for (int i = 5; itMy != MySet.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (int i = 1; itMy2 != MySet2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(Set, Swap2) {
  // Arrange
  s21::Set<int> MySet{10, 11, 12, 13, 14};
  s21::Set<int> MySet2{111, 112, 113, 114};

  // Act
  MySet.Swap(MySet2);
  auto itMy = MySet.Begin();
  auto itMy2 = MySet2.Begin();

  // Assert
  for (int i = 111; itMy != MySet.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (int i = 10; itMy2 != MySet2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(Set, Swap3) {
  // Arrange
  s21::Set<double> MySet{10.123, 11.123, 12.123, 13.123, 14.123};
  s21::Set<double> MySet2{111.999, 112.999, 113.999, 114.999};

  // Act
  MySet.Swap(MySet2);
  auto itMy = MySet.Begin();
  auto itMy2 = MySet2.Begin();

  // Assert
  for (double i = 111.999; itMy != MySet.End(); ++itMy, ++i)
    EXPECT_EQ(*itMy, i);

  for (double i = 10.123; itMy2 != MySet2.End(); ++itMy2, ++i)
    EXPECT_EQ(*itMy2, i);
}

TEST(Set, Swap4) {
  // Arrange
  s21::Set<char> MySet{'a', 'b', 'c', 'd'};
  s21::Set<char> MySet2{'e', 'f', 'g', 'h', 'i'};

  // Act
  MySet.Swap(MySet2);
  auto itMy = MySet.Begin();
  auto itMy2 = MySet2.Begin();

  // Assert
  for (char i = 'e'; itMy != MySet.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (char i = 'a'; itMy2 != MySet2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(Set, Swap5) {
  // Arrange
  s21::Set<char> MySet{'c', 'b', 'a'};
  s21::Set<char> MySet2{'i', 'h', 'g', 'f', 'e', 'd'};

  // Act
  MySet.Swap(MySet2);
  auto itMy = MySet.Begin();
  auto itMy2 = MySet2.Begin();

  // Assert
  for (char i = 'd'; itMy != MySet.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (char i = 'a'; itMy2 != MySet2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(Set, InsertManyHead) { std::cout << "\n------------------\n"; }

TEST(Set, InsertMany1) {
  // Arrange
  s21::Set<int> MySet;
  size_t j = 1;

  // Act
  MySet.InsertMany(1, 2, 3, 4, 5);
  auto it = MySet.Begin();

  // Assert
  for (size_t i = 0; i != MySet.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Set, InsertMany2) {
  // Arrange
  s21::Set<int> MySet{-4, -3, -2, -1, 0};
  size_t j = -4;

  // Act
  MySet.InsertMany(1, 2, 3, 4, 5);
  auto it = MySet.Begin();

  // Assert
  for (size_t i = 0; i != MySet.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Set, InsertMany3) {
  // Arrange
  s21::Set<int> MySet{-4, -3, -2, -1, 0};
  int j = -4;

  // Act
  MySet.InsertMany(1, 2, 3, 4, 5);
  auto it = MySet.Begin();

  // Assert
  for (size_t i = 0; i != MySet.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Set, InsertMany4) {
  // Arrange
  s21::Set<int> MySet{4, 3, 2, 1};
  int j = -4;

  // Act
  MySet.InsertMany(0, -1, -2, -3, -4);
  auto it = MySet.Begin();

  // Assert
  for (size_t i = 0; i != MySet.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Set, InsertMany5) {
  // Arrange
  s21::Set<char> MySet{'0', '8', '9', '4', '3'};
  char ch = '0';

  // Act
  MySet.InsertMany('1', '5', '6', '2', '7');
  auto it = MySet.Begin();

  // Assert
  for (size_t i = 0; i != MySet.Size(); ++i, ++it) EXPECT_EQ(*it, ch++);
}

TEST(Set, InsertMany6) {
  // Arrange
  s21::Set<std::string> MySet;

  // Act
  MySet.InsertMany("suzyheim", "abc", "bcd");
  auto it = MySet.Contains("suzyheim");
  auto it2 = MySet.Contains("abc");
  auto it3 = MySet.Contains("bcd");

  // Assert
  EXPECT_EQ(it, true);
  EXPECT_EQ(it2, true);
  EXPECT_EQ(it3, true);
}
