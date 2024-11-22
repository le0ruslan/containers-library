#include <array>

#include "tests.h"

TEST(Array, AtHead) { std::cout << "\n------------------\n"; }

TEST(Array, At1) {
  // Arrange
  s21::Array<int, 3> MyArr;
  std::array<int, 3> StdArr;

  // Act

  // Assert
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At2) {
  // Arrange
  s21::Array<int, 7> MyArr{45, 89, 23, 23, 22, 22, 87};
  std::array<int, 7> StdArr{45, 89, 23, 23, 22, 22, 87};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i)
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At3) {
  // Arrange
  s21::Array<double, 5> MyArr{3.34, 10.1, 11, 23.41, 42};
  std::array<double, 5> StdArr{3.34, 10.1, 11, 23.41, 42};

  // Act

  // Assert
  for (size_t i = 0; i != StdArr.size(); ++i)
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At4) {
  // Arrange
  s21::Array<std::string, 3> MyArr{"serge", "suzyheim", "s21school"};
  std::array<std::string, 3> StdArr{"serge", "suzyheim", "s21school"};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i)
    EXPECT_STREQ(MyArr.At(i).c_str(), StdArr.at(i).c_str());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At5) {
  // Arrange
  s21::Array<int, 4> MyArr{123, 122, 9, 87};
  std::array<int, 4> StdArr{123, 122, 9, 87};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i)
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At6) {
  // Arrange
  s21::Array<char, 7> MyArr{'&', '*', '(', '1', 'y', '8', '+'};
  std::array<char, 7> StdArr{'&', '*', '(', '1', 'y', '8', '+'};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i)
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, At7) {
  // Arrange
  s21::Array<std::string, 4> MyArr{"serge", "suzyheim", "s21school"};
  std::array<std::string, 4> StdArr{"serge", "suzyheim", "s21school"};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i)
    EXPECT_STREQ(MyArr.At(i).c_str(), StdArr.at(i).c_str());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, BeginHead) { std::cout << "\n------------------\n"; }

TEST(Array, BeginBack1) {
  // Arrange
  s21::Array<int, 5> MyVec{3, 8, 10, 98, 100};
  std::array<int, 5> StdVec{3, 8, 10, 98, 100};

  // Act
  auto myPtr = MyVec.Begin();
  auto stdPtr = StdVec.begin();
  *myPtr = 845;
  *stdPtr = 845;

  // Assert
  EXPECT_EQ(*MyVec.Begin(), *StdVec.begin());
}

TEST(Array, BeginBack2) {
  // Arrange
  s21::Array<int, 3> MyVec{10, 98, 100};
  std::array<int, 3> StdVec{10, 98, 100};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Begin(), *StdVec.begin());
}

TEST(Array, BeginBack3) {
  // Arrange
  const int size = 3;
  s21::Array<std::string, size> MyVec{"sergei", "what", "is"};
  std::array<std::string, size> StdVec{"sergei", "what", "is"};

  // Act
  auto myPtr = MyVec.Begin();
  auto stdPtr = StdVec.begin();
  ++myPtr;
  ++stdPtr;
  *myPtr = -123;
  *stdPtr = -123;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());
}

TEST(Array, BeginBack4) {
  // Arrange
  const int size = 3;
  s21::Array<std::string, size> MyVec{"sergei", "what", "is"};
  std::array<std::string, size> StdVec{"sergei", "what", "is"};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Begin(), *StdVec.begin());
}

TEST(Array, BeginBack5) {
  // Arrange
  const int size = 3;
  s21::Array<char, size> MyVec{'q', 'i', 'i'};
  std::array<char, size> StdVec{'q', 'i', 'i'};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Begin(), *StdVec.begin());
}

TEST(Array, BeginBack6) {
  // Arrange
  const int size = 4;
  s21::Array<double, size> MyVec{88.12, 802.31, 44.21, -13};
  std::array<double, size> StdVec{88.12, 802.31, 44.21, -13};

  // Act
  auto myPtr = MyVec.Begin();
  auto stdPtr = StdVec.begin();
  ++myPtr;
  ++stdPtr;
  *myPtr = -0.3;
  *stdPtr = -0.3;

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(MyVec.At(i), StdVec.at(i));
  }
}

TEST(Array, CopyAssignHead) { std::cout << "\n------------------\n"; }

TEST(Array, CopyAssign1) {
  // Arrange
  s21::Array<int, 4> MyArr{3, 4, 5, 6};
  std::array<int, 4> StdArr{3, 4, 5, 6};

  // Act
  s21::Array<int, 4> MyArr2 = MyArr;
  std::array<int, 4> StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, CopyAssign2) {
  // Arrange
  const int count = 4;
  s21::Array<double, count> MyArr{3.89, 4.12, 5.145, 6.894};
  std::array<double, count> StdArr{3.89, 4.12, 5.145, 6.894};

  // Act
  s21::Array<double, count> MyArr2 = MyArr;
  std::array<double, count> StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

// TEST(Array, CopyAssign3) {
//   // Arrange
//   const int count = 4;
//   s21::Array<std::string, count> MyArr{"suzyheim", "my good English",
//                                           "or not", "be and not to be"};
//   std::array<std::string, count> StdArr{"suzyheim", "my good English", "or
//   not",
//                                         "be and not to be"};
//
//   // Act
//   s21::Array<std::string, count> MyArr2 = MyArr;
//   std::array<std::string, count> StdArr2 = StdArr;
//
//   // Assert
//   for (size_t i = 0; i != MyArr2.Size(); ++i) {
//     EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
//   }
// }

TEST(Array, CopyAssign4) {
  // Arrange
  const int count = 4;
  s21::Array<std::string, count> MyArr{};
  std::array<std::string, count> StdArr{};

  // Act
  s21::Array<std::string, count> MyArr2 = MyArr;
  std::array<std::string, count> StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, CopyAssign5) {
  // Arrange
  const int count = 4;
  s21::Array<char, count> MyArr{'&', '*', '$', '!'};
  std::array<char, count> StdArr{'&', '*', '$', '!'};

  // Act
  s21::Array<char, count> MyArr2 = MyArr;
  std::array<char, count> StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, CopyAssign6) {
  // Arrange
  const int count = 4;
  s21::Array<char, count> MyArr{'&', '*', '$', '!'};
  std::array<char, count> StdArr{'&', '*', '$', '!'};

  // Act
  MyArr = MyArr;
  StdArr = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  }
}

TEST(Array, CopyAssign7) {
  // Arrange
  const int count = 4;
  s21::Array<char, count> MyArr{};
  std::array<char, count> StdArr{};

  // Act
  MyArr = MyArr;
  StdArr = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  }
}

TEST(Array, CopyConstructorHead) { std::cout << "\n------------------\n"; }

TEST(Array, CopyConstructor1) {
  // Arrange
  s21::Array<int, 4> MyArr{3, 4, 5, 6};
  std::array<int, 4> StdArr{3, 4, 5, 6};

  // Act
  s21::Array<int, 4> MyArr2(MyArr);
  std::array<int, 4> StdArr2(StdArr);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, CopyConstructor2) {
  // Arrange
  const int count = 4;
  s21::Array<double, count> MyArr{3.89, 4.12, 5.145, 6.894};
  std::array<double, count> StdArr{3.89, 4.12, 5.145, 6.894};

  // Act
  s21::Array<double, count> MyArr2(MyArr);
  std::array<double, count> StdArr2(StdArr);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

// TEST(Array, CopyConstructor3) {
//   // Arrange
//   const int count = 4;
//   s21::Array<std::string, count> MyArr{"suzyheim", "my good English",
//                                           "or not", "be and not to be"};
//   std::array<std::string, count> StdArr{"suzyheim", "my good English", "or
//   not",
//                                         "be and not to be"};
//
//   // Act
//   s21::Array<std::string, count> MyArr2(MyArr);
//   std::array<std::string, count> StdArr2(StdArr);
//
//   // Assert
//   for (size_t i = 0; i != MyArr2.Size(); ++i) {
//     EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
//   }
// }

TEST(Array, CopyConstructor4) {
  // Arrange
  const int count = 4;
  s21::Array<std::string, count> MyArr{};
  std::array<std::string, count> StdArr{};

  // Act
  s21::Array<std::string, count> MyArr2(MyArr);
  std::array<std::string, count> StdArr2(StdArr);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, CopyConstructor5) {
  // Arrange
  const int count = 4;
  s21::Array<char, count> MyArr{'&', '*', '$', '!'};
  std::array<char, count> StdArr{'&', '*', '$', '!'};

  // Act
  s21::Array<char, count> MyArr2(MyArr);
  std::array<char, count> StdArr2(StdArr);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, DataHead) { std::cout << "\n------------------\n"; }

TEST(Array, DataBack1) {
  // Arrange
  s21::Array<int, 5> MyVec{3, 8, 10, 98, 100};
  std::array<int, 5> StdVec{3, 8, 10, 98, 100};

  // Act
  auto myPtr = MyVec.Data();
  auto stdPtr = StdVec.data();
  *myPtr = 845;
  *stdPtr = 845;

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());
}

TEST(Array, DataBack2) {
  // Arrange
  s21::Array<int, 3> MyVec{10, 98, 100};
  std::array<int, 3> StdVec{10, 98, 100};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());
}

TEST(Array, DataBack3) {
  // Arrange
  const int size = 3;
  s21::Array<std::string, size> MyVec{"sergei", "what", "is"};
  std::array<std::string, size> StdVec{"sergei", "what", "is"};

  // Act
  auto myPtr = MyVec.Data();
  auto stdPtr = StdVec.data();
  ++myPtr;
  ++stdPtr;
  *myPtr = -123;
  *stdPtr = -123;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());
}

TEST(Array, DataBack4) {
  // Arrange
  const int size = 3;
  s21::Array<std::string, size> MyVec{"sergei", "what", "is"};
  std::array<std::string, size> StdVec{"sergei", "what", "is"};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());
}

TEST(Array, DataBack5) {
  // Arrange
  const int size = 3;
  s21::Array<char, size> MyVec{'q', 'i', 'i'};
  std::array<char, size> StdVec{'q', 'i', 'i'};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());
}

TEST(Array, DataBack6) {
  // Arrange
  const int size = 4;
  s21::Array<double, size> MyVec{88.12, 802.31, 44.21, -13};
  std::array<double, size> StdVec{88.12, 802.31, 44.21, -13};

  // Act
  auto myPtr = MyVec.Data();
  auto stdPtr = StdVec.data();
  ++myPtr;
  ++stdPtr;
  *myPtr = -0.3;
  *stdPtr = -0.3;

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(MyVec.At(i), StdVec.at(i));
  }
}

TEST(Array, EmptyHead) { std::cout << "\n------------------\n"; }

TEST(Array, Empty1) {
  // Arrange
  s21::Array<int, 4> MyArr;
  std::array<int, 4> StdArr;

  // Act

  // Assert
  EXPECT_EQ(MyArr.Empty(), StdArr.empty());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, Empty2) {
  // Arrange
  s21::Array<std::string, 3> MyArr;
  std::array<std::string, 3> StdArr;

  // Act

  // Assert
  EXPECT_EQ(MyArr.Empty(), StdArr.empty());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, Empty3) {
  // Arrange
  s21::Array<std::string, 4> MyArr{"sergei", "ruslan", "timur", "ravil"};
  std::array<std::string, 4> StdArr{"sergei", "ruslan", "timur", "ravil"};

  // Act

  // Assert
  EXPECT_EQ(MyArr.Empty(), StdArr.empty());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, Empty4) {
  // Arrange
  s21::Array<int, 0> MyArr;
  std::array<int, 0> StdArr;

  // Act

  // Assert
  EXPECT_EQ(MyArr.Empty(), StdArr.empty());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, Empty5) {
  // Arrange
  s21::Array<std::string, 0> MyArr;
  std::array<std::string, 0> StdArr;

  // Act
  bool flags = MyArr.Empty();
  bool flags2 = StdArr.empty();

  // Assert
  EXPECT_EQ(flags, flags2);
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, Empty6) {
  // Arrange
  s21::Array<char, 3> MyArr{'t', 'i', 'o'};
  std::array<char, 3> StdArr{'t', 'i', 'o'};

  // Act
  bool flags = MyArr.Empty();
  bool flags2 = StdArr.empty();

  // Assert
  EXPECT_EQ(flags, flags2);
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FillHead) { std::cout << "\n------------------\n"; }

TEST(Array, Fill1) {
  // Arrange
  const int size = 1;
  int value = 123;
  s21::Array<int, size> MyArr{1};
  std::array<int, size> StdArr{1};

  // Act
  MyArr.Fill(value);
  StdArr.fill(value);

  // Assert
  EXPECT_EQ(MyArr.Front(), StdArr.front());
}

TEST(Array, Fill2) {
  // Arrange
  const int size = 5;
  int value = -184;
  s21::Array<int, size> MyArr{1, 8, 0, 0, 3};
  std::array<int, size> StdArr{1, -1, 0, -3, 1};

  // Act
  MyArr.Fill(value);
  StdArr.fill(value);

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  }
}

TEST(Array, Fill3) {
  // Arrange
  const int size = 5;
  double value = -0.298;
  s21::Array<double, size> MyArr{1.23, 8.830, 12.0, 0, 3};
  std::array<double, size> StdArr{1, -1, 0.09, -3, 1.13};

  // Act
  MyArr.Fill(value);
  StdArr.fill(value);

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyArr.At(i), StdArr.at(i));
  }
}

TEST(Array, Fill4) {
  // Arrange
  const int size = 5;
  std::string value = "S21School!";
  s21::Array<std::string, size> MyArr{"My", "name", "is", "Sergei", "!"};
  std::array<std::string, size> StdArr{"My", "name", "is", "Sergei", "!"};

  // Act
  MyArr.Fill(value);
  StdArr.fill(value);

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_STREQ(MyArr.At(i).c_str(), StdArr.at(i).c_str());
  }
}

TEST(Array, Fill5) {
  // Arrange
  const int size = 4;
  char value = '8';
  s21::Array<int, size> MyArr{'*', '(', ')', '+'};
  std::array<int, size> StdArr{'y', 'i', 'i', 'd'};

  // Act
  MyArr.Fill(value);
  StdArr.fill(value);

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_EQ(MyArr.At(i), StdArr.at(i));
  }
}

TEST(Array, FrontBackHead) { std::cout << "\n------------------\n"; }

TEST(Array, FrontBack1) {
  // Arrange
  s21::Array<int, 1> MyArr{-1};
  std::array<int, 1> StdArr{-1};

  // Act

  // Assert
  EXPECT_EQ(MyArr.Front(), StdArr.front());
  EXPECT_EQ(MyArr.Back(), StdArr.back());

  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack2) {
  // Arrange
  s21::Array<int, 7> MyArr{45, 89, 23, 23, 22, 22, 87};
  std::array<int, 7> StdArr{45, 89, 23, 23, 22, 22, 87};

  // Act

  // Assert
  EXPECT_EQ(MyArr.Front(), StdArr.front());
  EXPECT_EQ(MyArr.Back(), StdArr.back());

  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack3) {
  // Arrange
  s21::Array<double, 5> MyArr{3.34, 10.1, 11, 23.41, 42};
  std::array<double, 5> StdArr{3.34, 10.1, 11, 23.41, 42};

  // Act

  // Assert
  EXPECT_DOUBLE_EQ(MyArr.Front(), StdArr.front());
  EXPECT_DOUBLE_EQ(MyArr.Back(), StdArr.back());

  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack4) {
  // Arrange
  s21::Array<std::string, 3> MyArr{"serge", "suzyheim", "s21school"};
  std::array<std::string, 3> StdArr{"serge", "suzyheim", "s21school"};

  // Act

  // Assert
  EXPECT_STREQ(MyArr.Front().c_str(), StdArr.front().c_str());
  EXPECT_STREQ(MyArr.Back().c_str(), StdArr.back().c_str());

  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack5) {
  // Arrange
  s21::Array<int, 4> MyArr{123, 122, 9, 87};
  std::array<int, 4> StdArr{123, 122, 9, 87};

  // Act

  // Assert
  EXPECT_EQ(MyArr.Front(), StdArr.front());
  EXPECT_EQ(MyArr.Back(), StdArr.back());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack6) {
  // Arrange
  s21::Array<char, 7> MyArr{'&', '*', '(', '1', 'y', '8', '+'};
  std::array<char, 7> StdArr{'&', '*', '(', '1', 'y', '8', '+'};

  // Act

  // Assert
  EXPECT_EQ(MyArr.Front(), StdArr.front());
  EXPECT_EQ(MyArr.Back(), StdArr.back());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, FrontBack7) {
  // Arrange
  s21::Array<std::string, 4> MyArr{"serge", "suzyheim", "s21school"};
  std::array<std::string, 4> StdArr{"serge", "suzyheim", "s21school"};

  // Act

  // Assert
  EXPECT_STREQ(MyArr.Front().c_str(), StdArr.front().c_str());
  EXPECT_STREQ(MyArr.Back().c_str(), StdArr.back().c_str());
  EXPECT_EQ(MyArr.MaxSize(), StdArr.max_size());
  EXPECT_EQ(MyArr.Size(), StdArr.size());
}

TEST(Array, MoveAssignmentHead) { std::cout << "\n------------------\n"; }

TEST(Array, MoveAssignment1) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{3, 4, 5, 6};
  std::array<int, size> StdArr{3, 4, 5, 6};
  s21::Array<int, size> MyArr2{3, 42, 21, 0};
  std::array<int, size> StdArr2{3, 42, 21, 0};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveAssignment2) {
  // Arrange
  const int size = 6;
  s21::Array<int, size> MyArr{3, 4, 5, 6, 98, 0};
  std::array<int, size> StdArr{3, 4, 5, 6, 98, 0};
  s21::Array<int, size> MyArr2{3, 42, 21, 0, -1, -3};
  std::array<int, size> StdArr2{3, 42, 21, 0, -1, -3};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveAssignment3) {
  // Arrange
  const int size = 6;
  s21::Array<std::string, size> MyArr{"size", "my",   "program",
                                      "is",   "very", "bag"};
  std::array<std::string, size> StdArr{"size", "my",   "program",
                                       "is",   "very", "bag"};
  s21::Array<std::string, size> MyArr2{"s", "i", "o", "q", "o", "q"};
  std::array<std::string, size> StdArr2{"s", "i", "o", "q", "o", "q"};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, MoveAssignment4) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{'i', 'a', 'o', 'q'};
  std::array<int, size> StdArr{'i', 'a', 'o', 'q'};
  s21::Array<int, size> MyArr2{'&', '0', '1', 'i'};
  std::array<int, size> StdArr2{'&', '0', '1', 'i'};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveAssignment5) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{'i', 'a', 'o', 'q'};
  std::array<int, size> StdArr{'i', 'a', 'o', 'q'};
  s21::Array<int, size> MyArr2;
  std::array<int, size> StdArr2;

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveConstructorHead) { std::cout << "\n------------------\n"; }

TEST(Array, MoveConstructor1) {
  // Arrange
  s21::Array<int, 4> MyArr{3, 4, 5, 6};
  std::array<int, 4> StdArr{3, 4, 5, 6};

  // Act
  s21::Array<int, 4> MyArr2(std::move(MyArr));
  std::array<int, 4> StdArr2(std::move(StdArr));

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveConstructor2) {
  // Arrange
  const int size = 4;
  s21::Array<std::string, size> MyArr{"sergei", "denis", "s21school",
                                      "suzyhiem"};
  std::array<std::string, size> StdArr{"sergei", "denis", "s21school",
                                       "suzyhiem"};

  // Act
  s21::Array<std::string, size> MyArr2(std::move(MyArr));
  std::array<std::string, size> StdArr2(std::move(StdArr));

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, MoveConstructor3) {
  // Arrange
  const int size = 4;
  s21::Array<std::string, size> MyArr{};
  std::array<std::string, size> StdArr{};

  // Act
  s21::Array<std::string, size> MyArr2(std::move(MyArr));
  std::array<std::string, size> StdArr2(std::move(StdArr));

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2.At(i).c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, MoveConstructor4) {
  // Arrange
  const int size = 4;
  s21::Array<double, size> MyArr{54.34, 88.12, 32.88, 99.123};
  std::array<double, size> StdArr{54.34, 88.12, 32.88, 99.123};

  // Act
  s21::Array<double, size> MyArr2(std::move(MyArr));
  std::array<double, size> StdArr2(std::move(StdArr));

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, MoveConstructor5) {
  // Arrange
  const int size = 4;
  s21::Array<char, size> MyArr{'a', 'b', 'c', 'd'};
  std::array<char, size> StdArr{'a', 'b', 'c', 'd'};

  // Act
  s21::Array<char, size> MyArr2(std::move(MyArr));
  std::array<char, size> StdArr2(std::move(StdArr));

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.At(i), StdArr2.at(i));
  }
}

TEST(Array, OperatorSquareHead) { std::cout << "\n------------------\n"; }

TEST(Array, OperatorSquare1) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{3, 4, 5, 6};
  std::array<int, size> StdArr{3, 4, 5, 6};

  // Act

  // Assert
  for (size_t i = 0; i != MyArr.Size(); ++i) {
    EXPECT_EQ(MyArr[i], StdArr[i]);
  }
}

TEST(Array, OperatorSquare2) {
  // Arrange
  const int size = 6;
  s21::Array<int, size> MyArr{3, 4, 5, 6, 98, 0};
  std::array<int, size> StdArr{3, 4, 5, 6, 98, 0};
  s21::Array<int, size> MyArr2{3, 42, 21, 0, -1, -3};
  std::array<int, size> StdArr2{3, 42, 21, 0, -1, -3};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2[i], StdArr2.at(i));
  }
}

TEST(Array, OperatorSquare3) {
  // Arrange
  const int size = 6;
  s21::Array<std::string, size> MyArr{"size", "my",   "program",
                                      "is",   "very", "bag"};
  std::array<std::string, size> StdArr{"size", "my",   "program",
                                       "is",   "very", "bag"};
  s21::Array<std::string, size> MyArr2{"s", "i", "o", "q", "o", "q"};
  std::array<std::string, size> StdArr2{"s", "i", "o", "q", "o", "q"};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_STREQ(MyArr2[i].c_str(), StdArr2.at(i).c_str());
  }
}

TEST(Array, OperatorSquare4) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{'i', 'a', 'o', 'q'};
  std::array<int, size> StdArr{'i', 'a', 'o', 'q'};
  s21::Array<int, size> MyArr2{'&', '0', '1', 'i'};
  std::array<int, size> StdArr2{'&', '0', '1', 'i'};

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2[i], StdArr2.at(i));
  }
}

TEST(Array, OperatorSquare5) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{'i', 'a', 'o', 'q'};
  std::array<int, size> StdArr{'i', 'a', 'o', 'q'};
  s21::Array<int, size> MyArr2;
  std::array<int, size> StdArr2;

  // Act
  MyArr2 = MyArr;
  StdArr2 = StdArr;

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2[i], StdArr2.at(i));
  }
}

TEST(Array, SwapHead) { std::cout << "\n------------------\n"; }

TEST(Array, Swap1) {
  // Arrange
  const int size = 1;
  s21::Array<int, size> MyArr{-1};
  s21::Array<int, size> MyArr2{-2};
  std::array<int, size> StdArr{-1};
  std::array<int, size> StdArr2{-2};

  // Act
  MyArr.Swap(MyArr2);
  StdArr.swap(StdArr2);

  // Assert
  EXPECT_EQ(MyArr2.Front(), StdArr2.front());
  EXPECT_EQ(MyArr.Front(), StdArr.front());
}

TEST(Array, Swap2) {
  // Arrange
  const int size = 4;
  s21::Array<int, size> MyArr{-1, -22, -3, 0};
  s21::Array<int, size> MyArr2{-33, 1023, 0, -1};
  std::array<int, size> StdArr{-1, -22, -3, 0};
  std::array<int, size> StdArr2{-33, 1023, 0, -1};

  // Act
  MyArr.Swap(MyArr2);
  StdArr.swap(StdArr2);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2.Front(), StdArr2.front());
    EXPECT_EQ(MyArr.Front(), StdArr.front());
  }
}

TEST(Array, Swap3) {
  // Arrange
  const int size = 6;
  s21::Array<double, size> MyArr{-1.043, -22.98, -3.001, 0.123};
  s21::Array<double, size> MyArr2{-33.034, 1023.32, 0.1, -1.23};
  std::array<double, size> StdArr{-1.043, -22.98, -3.001, 0.123};
  std::array<double, size> StdArr2{-33.034, 1023.32, 0.1, -1.23};

  // Act
  MyArr.Swap(MyArr2);
  StdArr.swap(StdArr2);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyArr2.Front(), StdArr2.front());
    EXPECT_DOUBLE_EQ(MyArr.Front(), StdArr.front());
  }
}

TEST(Array, Swap4) {
  // Arrange
  const int size = 4;
  s21::Array<std::string, size> MyArr{"sergei", "timur", "ruslan", "ravil"};
  s21::Array<std::string, size> MyArr2{"suzyheim", "s21school", "hi", "my"};
  std::array<std::string, size> StdArr{"sergei", "timur", "ruslan", "ravil"};
  std::array<std::string, size> StdArr2{"suzyheim", "s21school", "hi", "my"};

  // Act
  MyArr.Swap(MyArr2);
  StdArr.swap(StdArr2);

  // Assert
  for (size_t i = 0; i != StdArr2.size(); ++i) {
    EXPECT_STREQ(MyArr2[i].c_str(), StdArr2[i].c_str());
    EXPECT_STREQ(MyArr[i].c_str(), StdArr[i].c_str());
  }
}

TEST(Array, Swap5) {
  // Arrange
  const int size = 4;
  s21::Array<char, size> MyArr{'i', 'q', '!', '@'};
  s21::Array<char, size> MyArr2{'k', 'l', ' ', 'I'};
  std::array<char, size> StdArr{'i', 'q', '!', '@'};
  std::array<char, size> StdArr2{'k', 'l', ' ', 'I'};

  // Act
  MyArr.Swap(MyArr2);
  StdArr.swap(StdArr2);

  // Assert
  for (size_t i = 0; i != MyArr2.Size(); ++i) {
    EXPECT_EQ(MyArr2[i], StdArr2[i]);
    EXPECT_EQ(MyArr[i], StdArr[i]);
  }
}