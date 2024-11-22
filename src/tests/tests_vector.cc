#include <vector>

#include "tests.h"

TEST(Vector, AtHead) { std::cout << "\n------------------\n"; }

TEST(Vector, At1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At2) {
  // Arrange
  s21::Vector<int> MyVec{45, 89, 23, 23, 22, 22, 87};
  std::vector<int> StdVec{45, 89, 23, 23, 22, 22, 87};

  // Act

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  MyVec.PushBack(32.12);
  StdVec.push_back(32.12);

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At4) {
  // Arrange
  s21::Vector<std::string> MyVec{"serge", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"serge", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec.at(i).c_str());
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At5) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At6) {
  // Arrange
  size_t count = 10;
  s21::Vector<int> MyVec(count);
  std::vector<int> StdVec(count);

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  EXPECT_EQ(MyVec.At(0), StdVec.at(0));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, At7) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_ANY_THROW(MyVec.At(0));
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, BackHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Back1) {
  // Arrange
  s21::Vector<int> MyVec{3, 12, 99, 0, -1, -32};
  std::vector<int> StdVec{3, 12, 99, 0, -1, -32};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Back(), StdVec.back());
}

TEST(Vector, Back2) {
  // Arrange
  s21::Vector<char> MyVec{'i', '*', '%', '(', '-', '_'};
  std::vector<char> StdVec{'i', '*', '%', '(', '-', '_'};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Back(), StdVec.back());
}

TEST(Vector, Back3) {
  // Arrange
  s21::Vector<double> MyVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  std::vector<double> StdVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  // Act

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.Back(), StdVec.back());
}

TEST(Vector, Back4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school",
                                 "what is your problem?"};
  std::vector<std::string> StdVec{"suzyheim", "s21school",
                                  "what is your problem?"};

  // Act

  // Assert
  EXPECT_STREQ(MyVec.Back().c_str(), StdVec.back().c_str());
}

TEST(Vector, Back5) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "ravil", "timur", "ruslan"};
  std::vector<std::string> StdVec{"sergei", "ravil", "timur", "ruslan"};
  // Act

  // Assert
  EXPECT_STREQ(MyVec.Back().c_str(), StdVec.back().c_str());
}

TEST(Vector, Back6) {
  // Arrange
  s21::Vector<double> MyVec{9.99, 5.845, 983.123, 88.09, 234};
  std::vector<double> StdVec{9.99, 5.845, 983.123, 88.09, 234};
  // Act

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.Back(), StdVec.back());
}

TEST(Vector, Back7) {
  // Arrange
  s21::Vector<char> MyVec{'*', '%', '(', '-', '_'};
  std::vector<char> StdVec{'*', '%', '(', '-', '_'};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Back(), StdVec.back());
}

TEST(Vector, CapacityHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Capacity1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;
  size_t count = 100;

  // Act
  for (size_t i = 0; i != count; ++i) {
    MyVec.PushBack(i);
    StdVec.push_back(i);
  }

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  MyVec.PushBack(32.12);
  StdVec.push_back(32.12);

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity4) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"sergei", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity5) {
  // Arrange
  s21::Vector<char> MyVec;
  std::vector<char> StdVec;
  size_t count = 100;

  // Act
  for (size_t i = 1; i != count; ++i) {
    MyVec.PushBack(i);
    StdVec.push_back(i);
  }

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity6) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};
  size_t count = 100;

  // Act
  for (size_t i = 1; i != count; --count) {
    MyVec.PushBack(count);
    StdVec.push_back(count);
  }

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Capacity7) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"sergei", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignHead) { std::cout << "\n------------------\n"; }

TEST(Vector, CopyAssignBack1) {
  // Arrange
  s21::Vector<int> MyVec{2};
  s21::Vector<int> MyVec2(MyVec);
  std::vector<int> StdVec{2};
  std::vector<int> StdVec2(StdVec);

  // Act

  // Assert
  EXPECT_EQ(MyVec.At(0), MyVec2.At(0));
  EXPECT_EQ(StdVec.at(0), StdVec2.at(0));

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignBack2) {
  // Arrange
  s21::Vector<int> MyVec{834, 21, 89, 33};
  std::vector<int> StdVec{834, 21, 89, 33};

  // Act
  s21::Vector<int> MyVec2(MyVec);
  std::vector<int> StdVec2(StdVec);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_EQ(StdVec.at(i), StdVec2.at(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignBack3) {
  // Arrange
  s21::Vector<double> MyVec{45.123, 88.38, 99.12, 889.21};
  std::vector<double> StdVec{45.123, 88.38, 99.12, 889.21};

  // Act
  s21::Vector<double> MyVec2(MyVec);
  std::vector<double> StdVec2(StdVec);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyVec.At(i), MyVec2.At(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_DOUBLE_EQ(StdVec.at(i), StdVec2.at(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignBack4) {
  // Arrange
  s21::Vector<char> MyVec{'$', '\'', '*', '#'};
  std::vector<char> StdVec{'$', '\'', '*', '#'};

  // Act
  s21::Vector<char> MyVec2(MyVec);
  std::vector<char> StdVec2(StdVec);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_EQ(StdVec.at(i), StdVec2.at(i));
  }

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignBack5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};

  // Act
  s21::Vector<std::string> MyVec2(MyVec);
  std::vector<std::string> StdVec2(StdVec);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec2.at(i).c_str());
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_STREQ(StdVec.at(i).c_str(), MyVec2.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, CopyAssignBack6) {
  // Arrange
  s21::Vector<std::string> MyVec{"why", "is", "you", "checking"};
  std::vector<std::string> StdVec{"why", "is", "you", "checking"};

  // Act
  s21::Vector<std::string> MyVec2(MyVec);
  std::vector<std::string> StdVec2(StdVec);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec2.at(i).c_str());
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_STREQ(StdVec.at(i).c_str(), MyVec2.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, ClearHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Clear1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(10);
  StdVec.push_back(10);
  MyVec.Clear();
  StdVec.clear();

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Clear2) {
  // Arrange
  s21::Vector<int> MyVec{45, 88, 201, 333, -1342};
  std::vector<int> StdVec{45, 88, 201, 333, -1342};

  // Act
  MyVec.Clear();
  StdVec.clear();

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Clear3) {
  // Arrange
  s21::Vector<int> MyVec{45, 88, 201, 333, -1342};
  std::vector<int> StdVec{45, 88, 201, 333, -1342};

  // Act
  MyVec.Clear();
  StdVec.clear();

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Clear4) {
  // Arrange
  s21::Vector<double> MyVec{45.231, 88.943, 201.123, 333.321, -1342.321, 0};
  std::vector<double> StdVec{45.231, 88.943, 201.123, 333.321, -1342.321, 0};

  // Act
  MyVec.Clear();
  StdVec.clear();

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Clear5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};

  // Act
  MyVec.Clear();
  StdVec.clear();

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Clear6) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  std::vector<char> StdVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};

  // Act
  MyVec.Clear();
  StdVec.clear();

  // Assert
  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, DataHead) { std::cout << "\n------------------\n"; }

TEST(Vector, DataBack1) {
  // Arrange
  s21::Vector<int> MyVec{3, 8, 10, 98, 100};
  std::vector<int> StdVec{3, 8, 10, 98, 100};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, DataBack2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.Data(), StdVec.data());

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, DataBack3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 8, 10, 98, 100};
  std::vector<double> StdVec{3.34, 8, 10, 98, 100};

  // Act

  // Assert
  EXPECT_DOUBLE_EQ(*MyVec.Data(), *StdVec.data());

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, DataBack4) {
  // Arrange
  s21::Vector<double> MyVec;
  std::vector<double> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.Data(), StdVec.data());

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, DataBack5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};

  // Act

  // Assert
  EXPECT_STREQ(MyVec.Data()->c_str(), StdVec.data()->c_str());

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, DataBack6) {
  // Arrange
  s21::Vector<double> MyVec{8.123, 10, 98, 100};
  std::vector<double> StdVec{8.123, 10, 98, 100};

  // Act

  // Assert
  EXPECT_DOUBLE_EQ(*MyVec.Data(), *StdVec.data());

  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, DataBack7) {
  // Arrange
  s21::Vector<char> MyVec{'*', '(', '&', ')'};
  std::vector<char> StdVec{'*', '(', '&', ')'};

  // Act

  // Assert
  EXPECT_EQ(*MyVec.Data(), *StdVec.data());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, EmptyHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Empty1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Empty2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(13);
  StdVec.push_back(13);

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Empty3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  MyVec.PushBack(32.12);
  StdVec.push_back(32.12);

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Empty4) {
  // Arrange
  s21::Vector<std::string> MyVec{"serge", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"serge", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Empty5) {
  // Arrange
  s21::Vector<char> MyVec;
  std::vector<char> StdVec;

  // Act
  MyVec.PushBack('a');
  MyVec.PushBack('b');
  StdVec.push_back('a');
  StdVec.push_back('b');

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Empty6) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  EXPECT_EQ(MyVec.Empty(), StdVec.empty());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, EraseHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Erase1) {
  // Arrange
  s21::Vector<int> MyVec{1, 3, 4, 5, 6};
  std::vector<int> StdVec{1, 3, 4, 5, 6};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  MyVec.Erase(itMy);
  StdVec.erase(itStd);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Erase2) {
  // Arrange
  s21::Vector<char> MyVec{'^', '!', '*', '9'};
  std::vector<char> StdVec{'^', '!', '*', '9'};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  ++itStd;
  MyVec.Erase(itMy);
  StdVec.erase(itStd);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Erase3) {
  // Arrange
  s21::Vector<double> MyVec{8.123, 9.348, 87.32, 45.1};
  std::vector<double> StdVec{8.123, 9.348, 87.32, 45.1};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itStd;
  MyVec.Erase(itMy);
  StdVec.erase(itStd);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_DOUBLE_EQ(MyVec[i], StdVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Erase4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  MyVec.Erase(itMy);
  StdVec.erase(itStd);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Erase5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itStd;
  ++itStd;
  ++itMy;
  ++itMy;
  MyVec.Erase(itMy);
  StdVec.erase(itStd);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, FrontHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Front1) {
  // Arrange
  s21::Vector<int> MyVec{3, 12, 99, 0, -1, -32};
  std::vector<int> StdVec{3, 12, 99, 0, -1, -32};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Front(), StdVec.front());
}

TEST(Vector, Front2) {
  // Arrange
  s21::Vector<char> MyVec{'i', '*', '%', '(', '-', '_'};
  std::vector<char> StdVec{'i', '*', '%', '(', '-', '_'};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Front(), StdVec.front());
}

TEST(Vector, Front3) {
  // Arrange
  s21::Vector<double> MyVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  std::vector<double> StdVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  // Act

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.Front(), StdVec.front());
}

TEST(Vector, Front4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school",
                                 "what is your problem?"};
  std::vector<std::string> StdVec{"suzyheim", "s21school",
                                  "what is your problem?"};

  // Act

  // Assert
  EXPECT_STREQ(MyVec.Front().c_str(), StdVec.front().c_str());
}

TEST(Vector, Front5) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "ravil", "timur", "ruslan"};
  std::vector<std::string> StdVec{"sergei", "ravil", "timur", "ruslan"};
  // Act

  // Assert
  EXPECT_STREQ(MyVec.Front().c_str(), StdVec.front().c_str());
}

TEST(Vector, Front6) {
  // Arrange
  s21::Vector<double> MyVec{9.99, 5.845, 983.123, 88.09, 234};
  std::vector<double> StdVec{9.99, 5.845, 983.123, 88.09, 234};
  // Act

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.Front(), StdVec.front());
}

TEST(Vector, Front7) {
  // Arrange
  s21::Vector<char> MyVec{'*', '%', '(', '-', '_'};
  std::vector<char> StdVec{'*', '%', '(', '-', '_'};
  // Act

  // Assert
  EXPECT_EQ(MyVec.Front(), StdVec.front());
}

TEST(Vector, InsertHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Insert1) {
  // Arrange
  s21::Vector<int> MyVec{1, 3, 4, 5, 6};
  std::vector<int> StdVec{1, 3, 4, 5, 6};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itStd;
  MyVec.Insert(itMy, 2);
  StdVec.insert(itStd, 2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Insert2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  MyVec.Insert(itMy, 2);
  StdVec.insert(itStd, 2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Insert3) {
  // Arrange
  s21::Vector<int> MyVec{1};
  std::vector<int> StdVec{1};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  auto itMyPro = MyVec.Insert(itMy, 2);
  auto itStdPro = StdVec.insert(itStd, 2);

  // Assert
  EXPECT_EQ(*itMyPro, *itStdPro);
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Insert4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "s21school"};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itStd;
  // auto itMyProv = MyVec.Insert(itMy, "sergei");
  // auto itStdProv = StdVec.insert(itStd, "sergei");

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec[i].c_str());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Insert5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "s21school"};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  // auto itMyProv = MyVec.Insert(itMy, "sergei");
  // auto itStdProv = StdVec.insert(itStd, "sergei");

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec[i].c_str());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Insert6) {
  // Arrange
  s21::Vector<char> MyVec{'$', '%', '(', '='};
  std::vector<char> StdVec{'$', '%', '(', '='};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  ++itStd;
  MyVec.Insert(itMy, '@');
  StdVec.insert(itStd, '@');

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, IteratorHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Iterator1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(10);
  StdVec.push_back(10);
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  EXPECT_EQ(*itStd, *itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  auto itMy = MyVec.Begin();
  // auto itStd = StdVec.begin();

  // Assert
  EXPECT_ANY_THROW(*itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator3) {
  // Arrange
  s21::Vector<int> MyVec{3, 43, 123, 408, 987, 100};
  std::vector<int> StdVec{3, 43, 123, 408, 987, 100};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  for (; itStd != StdVec.end(); ++itStd, ++itMy) EXPECT_EQ(*itStd, *itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "popov"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "popov"};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  for (; itStd != StdVec.end(); ++itStd, ++itMy) EXPECT_EQ(*itStd, *itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator5) {
  // Arrange
  s21::Vector<std::string> MyVec(20);
  std::vector<std::string> StdVec(20);

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  for (; itMy != MyVec.End(); ++itStd, ++itMy) EXPECT_EQ(*itStd, *itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator6) {
  // Arrange
  s21::Vector<char> MyVec{'a', '*', '8', ')', '$'};
  std::vector<char> StdVec{'a', '*', '8', ')', '$'};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  for (; itMy != MyVec.End(); ++itStd, ++itMy) EXPECT_EQ(*itStd, *itMy);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator7) {
  // Arrange
  s21::Vector<double> MyVec{78.12, 99.12, 45.77, 984.321};
  std::vector<double> StdVec{78.12, 99.12, 45.77, 984.321};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();

  // Assert
  for (; itMy != MyVec.End(); ++itStd, ++itMy) EXPECT_DOUBLE_EQ(*itStd, *itMy);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator8) {
  // Arrange
  s21::Vector<double> MyVec{78.12, 99.12, 45.77, 984.321};
  std::vector<double> StdVec{78.12, 99.12, 45.77, 984.321};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  size_t i = 0;
  while (i != StdVec.size() - 1) {
    ++itStd;
    ++itMy;
    ++i;
  }

  // Assert
  i = 0;
  while (i != StdVec.size() - 1) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
    itMy--;
    itStd--;
    ++i;
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator9) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  std::vector<char> StdVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  size_t i = 0;
  while (i != StdVec.size() - 1) {
    ++itStd;
    ++itMy;
    ++i;
  }

  // Assert
  i = 0;
  while (i != StdVec.size() - 1) {
    EXPECT_EQ(*itMy, *itStd);
    itMy--;
    itStd--;
    ++i;
  }

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Iterator10) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  s21::Vector<char> MyVec2{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags = false;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec2.Begin();
  flags = itMy == itMy2;

  // Assert
  EXPECT_EQ(false, flags);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), MyVec2.Capacity());
  EXPECT_EQ(MyVec.Size(), MyVec2.Size());
}

TEST(Vector, Iterator11) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  s21::Vector<char> MyVec2{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags = false;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec2.Begin();
  flags = itMy != itMy2;

  // Assert
  EXPECT_EQ(true, flags);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), MyVec2.Capacity());
  EXPECT_EQ(MyVec.Size(), MyVec2.Size());
}

TEST(Vector, Iterator12) {
  // Arrange
  s21::Vector<int> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  s21::Vector<int> MyVec2{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags = false;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec2.Begin();
  flags = itMy == itMy2;

  // Assert
  EXPECT_EQ(false, flags);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), MyVec2.Capacity());
  EXPECT_EQ(MyVec.Size(), MyVec2.Size());
}

TEST(Vector, Iterator13) {
  // Arrange
  s21::Vector<double> MyVec{1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
  s21::Vector<double> MyVec2{1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
  bool flags = false;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec2.Begin();
  flags = itMy != itMy2;

  // Assert
  EXPECT_EQ(true, flags);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Capacity(), MyVec2.Capacity());
  EXPECT_EQ(MyVec.Size(), MyVec2.Size());
}

TEST(Vector, Iterator14) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec.Begin();
  flags = itMy != itMy2;

  // Assert
  EXPECT_EQ(false, flags);
}

TEST(Vector, Iterator15) {
  // Arrange
  s21::Vector<int> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec.Begin();
  flags = itMy == itMy2;

  // Assert
  EXPECT_EQ(true, flags);
}

TEST(Vector, Iterator16) {
  // Arrange
  s21::Vector<double> MyVec{1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
  bool flags;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec.Begin();
  flags = itMy != itMy2;

  // Assert
  EXPECT_EQ(false, flags);
}

TEST(Vector, Iterator17) {
  // Arrange
  s21::Vector<char> MyVec{'s', 'u', 'z', 'y', 'h', 'e', 'i', 'm'};
  bool flags;

  // Act
  auto itMy = MyVec.Begin();
  auto itMy2 = MyVec.Begin();
  flags = itMy == itMy2;

  // Assert
  EXPECT_EQ(true, flags);
}

TEST(Vector, MoveAssignHead) { std::cout << "\n------------------\n"; }

TEST(Vector, MoveAssign1) {
  // Arrange
  s21::Vector<int> MyVec{3, 12, 99, 0, -1, -32};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<int> MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_EQ(MyVec2.At(0), 3);
  EXPECT_EQ(MyVec2.At(2), 99);
  EXPECT_EQ(MyVec2.At(4), -1);
  EXPECT_EQ(MyVec2.At(5), -32);
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign2) {
  // Arrange
  s21::Vector<int> MyVec{3, 12, 99, 0, -1, -32};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<int> MyVec2;
  MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_EQ(MyVec2.At(0), 3);
  EXPECT_EQ(MyVec2.At(2), 99);
  EXPECT_EQ(MyVec2.At(4), -1);
  EXPECT_EQ(MyVec2.At(5), -32);
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign3) {
  // Arrange
  s21::Vector<double> MyVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<double> MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_DOUBLE_EQ(MyVec2.At(0), 3.21);
  EXPECT_DOUBLE_EQ(MyVec2.At(2), 5.845);
  EXPECT_DOUBLE_EQ(MyVec2.At(4), 88.09);
  EXPECT_DOUBLE_EQ(MyVec2.At(5), 234);
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign4) {
  // Arrange
  s21::Vector<double> MyVec{3.21, 9.99, 5.845, 983.123, 88.09, 234};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<double> MyVec2;
  MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_DOUBLE_EQ(MyVec2.At(0), 3.21);
  EXPECT_DOUBLE_EQ(MyVec2.At(2), 5.845);
  EXPECT_DOUBLE_EQ(MyVec2.At(4), 88.09);
  EXPECT_DOUBLE_EQ(MyVec2.At(5), 234);
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign5) {
  // Arrange
  s21::Vector<char> MyVec{'i', '*', '%', '(', '-', '_'};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<char> MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_EQ(MyVec2.At(0), 'i');
  EXPECT_EQ(MyVec2.At(2), '%');
  EXPECT_EQ(MyVec2.At(4), '-');
  EXPECT_EQ(MyVec2.At(5), '_');
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign6) {
  // Arrange
  s21::Vector<char> MyVec{'^', 'g', '+', '"', ':', '~'};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<char> MyVec2;
  MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_EQ(MyVec2.At(0), '^');
  EXPECT_EQ(MyVec2.At(2), '+');
  EXPECT_EQ(MyVec2.At(4), ':');
  EXPECT_EQ(MyVec2.At(5), '~');
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign7) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "ravil", "timur", "ruslan"};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<std::string> MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_STREQ(MyVec2.At(0).c_str(), "sergei");
  EXPECT_STREQ(MyVec2.At(1).c_str(), "ravil");
  EXPECT_STREQ(MyVec2.At(2).c_str(), "timur");
  EXPECT_STREQ(MyVec2.At(3).c_str(), "ruslan");
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveAssign8) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school",
                                 "what is your problem?"};
  size_t sizeMyVec = MyVec.Size();
  size_t capacityMyVec = MyVec.Capacity();

  // Act
  s21::Vector<std::string> MyVec2;
  MyVec2 = std::move(MyVec);

  // Assert
  EXPECT_STREQ(MyVec2.At(0).c_str(), "suzyheim");
  EXPECT_STREQ(MyVec2.At(1).c_str(), "s21school");
  EXPECT_STREQ(MyVec2.At(2).c_str(), "what is your problem?");
  EXPECT_EQ(sizeMyVec, MyVec2.Size());
  EXPECT_EQ(capacityMyVec, MyVec2.Capacity());
}

TEST(Vector, MoveCstorHead) { std::cout << "\n------------------\n"; }

TEST(Vector, MoveCstorEqual1) {
  // Arrange
  s21::Vector<int> MyVec2{3, 2, 0, 32, -123, -1, -1000};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<int> MyVec(std::move(MyVec2));
  auto itMy = MyVec.Begin();

  // Assert
  EXPECT_EQ(*itMy, 3);
  ++itMy;
  EXPECT_EQ(*itMy, 2);
  ++itMy;
  EXPECT_EQ(*itMy, 0);

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MoveCstorEqual2) {
  // Arrange
  s21::Vector<double> MyVec2{0, -1.234, -1111, 985, 345};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<double> MyVec(std::move(MyVec2));
  // auto itMy = MyVec.Begin();

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.At(0), 0);
  EXPECT_DOUBLE_EQ(MyVec.At(1), -1.234);
  EXPECT_DOUBLE_EQ(MyVec.At(2), -1111);
  EXPECT_DOUBLE_EQ(MyVec.At(3), 985);

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MoveCstorEqual3) {
  // Arrange
  s21::Vector<double> MyVec2{0, -1.234, -1111, 985, 345};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<double> MyVec(std::move(MyVec2));

  // Assert
  EXPECT_DOUBLE_EQ(MyVec.At(0), 0);
  EXPECT_DOUBLE_EQ(MyVec.At(1), -1.234);
  EXPECT_DOUBLE_EQ(MyVec.At(2), -1111);
  EXPECT_DOUBLE_EQ(MyVec.At(3), 985);

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MoveCstorEqual4) {
  // Arrange
  s21::Vector<char> MyVec2{'a', '$', 'i', '9', '*'};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<char> MyVec(std::move(MyVec2));

  // Assert
  EXPECT_EQ(MyVec.At(0), 'a');
  EXPECT_EQ(MyVec.At(1), '$');
  EXPECT_EQ(MyVec.At(2), 'i');
  EXPECT_EQ(MyVec.At(3), '9');
  EXPECT_EQ(MyVec.At(4), '*');

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MoveCstorEqual5) {
  // Arrange
  s21::Vector<char> MyVec2{'t', 'k', '&', '(', '!'};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<char> MyVec(std::move(MyVec2));

  // Assert
  EXPECT_EQ(MyVec.At(0), 't');
  EXPECT_EQ(MyVec.At(1), 'k');
  EXPECT_EQ(MyVec.At(2), '&');
  EXPECT_EQ(MyVec.At(3), '(');
  EXPECT_EQ(MyVec.At(4), '!');

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MoveCstorEqual6) {
  // Arrange
  s21::Vector<std::string> MyVec2{"sergei", "suzyheim", "ruslan", "timur",
                                  "ravil"};
  size_t size = MyVec2.Size();
  size_t capacity = MyVec2.Capacity();

  // Act
  s21::Vector<std::string> MyVec(std::move(MyVec2));

  // Assert
  EXPECT_STREQ(MyVec.At(0).c_str(), "sergei");
  EXPECT_STREQ(MyVec.At(1).c_str(), "suzyheim");
  EXPECT_STREQ(MyVec.At(2).c_str(), "ruslan");
  EXPECT_STREQ(MyVec.At(3).c_str(), "timur");
  EXPECT_STREQ(MyVec.At(4).c_str(), "ravil");

  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, MaxSizeHead) { std::cout << "\n------------------\n"; }

TEST(Vector, MaxSize1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, MaxSize2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(13);
  StdVec.push_back(13);

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, MaxSize3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  MyVec.PushBack(32.12);
  StdVec.push_back(32.12);

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, MaxSize4) {
  // Arrange
  s21::Vector<std::string> MyVec{"serge", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"serge", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, MaxSizi5) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, MaxSizi6) {
  // Arrange
  size_t count = 10;
  s21::Vector<int> MyVec(count);
  std::vector<int> StdVec(count);

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperatorEqualHead) { std::cout << "\n------------------\n"; }

TEST(Vector, OperatorEqual1) {
  // Arrange
  s21::Vector<int> MyVec;
  s21::Vector<int> MyVec2{3, 2, 0, 32, -123, -1, -1000};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual2) {
  // Arrange
  s21::Vector<int> MyVec2{3, 2, 0, 32, -123, -1, -1000};
  s21::Vector<int> MyVec{3, 2, 0, 32, -123, -1, -1000};

  // Act
  MyVec2 = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual3) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "what is your doing"};
  s21::Vector<std::string> MyVec2{"s21school", "suzyheim", "ruslan", "ravil"};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), MyVec2.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual4) {
  // Arrange
  s21::Vector<std::string> MyVec;
  s21::Vector<std::string> MyVec2{"s21school", "suzyheim", "ruslan", "ravil"};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), MyVec2.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual5) {
  // Arrange
  s21::Vector<char> MyVec;
  s21::Vector<char> MyVec2{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual6) {
  // Arrange
  s21::Vector<char> MyVec{'3', '*', '@', '!', ',', ':'};
  s21::Vector<char> MyVec2{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual7) {
  // Arrange
  s21::Vector<char> MyVec2{'3', '*', '@', '!', ',', ':'};
  s21::Vector<char> MyVec{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual8) {
  // Arrange
  s21::Vector<char> MyVec;
  s21::Vector<char> MyVec2;

  // Act
  MyVec = MyVec2;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperatorEqual9) {
  // Arrange
  s21::Vector<double> MyVec2{33.21, 88.343, 99.45, 9};
  s21::Vector<double> MyVec{3, 2, 0, 32, -123, -1, -1000};

  // Act
  MyVec2 = MyVec;

  // Assert
  for (size_t i = 0; i != MyVec2.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyVec.At(i), MyVec2.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), MyVec2.MaxSize());
  EXPECT_EQ(MyVec.Size(), MyVec.Size());
  EXPECT_EQ(MyVec.Capacity(), MyVec.Capacity());
}

TEST(Vector, OperSquareHead) { std::cout << "\n------------------\n"; }

TEST(Vector, OperSquare1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  for (size_t i = 0; i != StdVec.size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare2) {
  // Arrange
  s21::Vector<int> MyVec{45, 89, 23, 23, 22, 22, 87};
  std::vector<int> StdVec{45, 89, 23, 23, 22, 22, 87};

  // Act

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  MyVec.PushBack(32.12);
  StdVec.push_back(32.12);

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare4) {
  // Arrange
  s21::Vector<std::string> MyVec{"serge", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"serge", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare5) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) EXPECT_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare6) {
  // Arrange
  size_t count = 10;
  s21::Vector<int> MyVec(count);
  std::vector<int> StdVec(count);

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);
  //  auto it = MyVec.Begin();
  //  for(;it != MyVec.End();++it)
  //      std::cout << *it << ' ';
  //  std::cout << '\n';
  //
  //    auto its = StdVec.begin();
  //    for(;its != StdVec.end();++its)
  //        std::cout << *its << ' ';
  //        std::cout << '\n';

  // Assert
  EXPECT_EQ(MyVec[9], StdVec[9]);
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, OperSquare7) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_ANY_THROW(MyVec[0]);
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, PushBackHead) { std::cout << "\n------------------\n"; }

TEST(Vector, PushBack1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(10);
  StdVec.push_back(10);

  // Assert
  EXPECT_EQ(MyVec.At(0), StdVec.at(0));
  EXPECT_EQ(MyVec[0], StdVec[0]);
  EXPECT_EQ(MyVec.Front(), StdVec.front());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PushBack2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(10);
  MyVec.PushBack(23);
  MyVec.PushBack(44);
  MyVec.PushBack(99);
  MyVec.PushBack(44);
  StdVec.push_back(10);
  StdVec.push_back(23);
  StdVec.push_back(44);
  StdVec.push_back(99);
  StdVec.push_back(44);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
    EXPECT_EQ(MyVec[i], StdVec[i]);
  }
  EXPECT_EQ(MyVec.Front(), StdVec.front());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PushBack3) {
  // Arrange
  s21::Vector<double> MyVec;
  std::vector<double> StdVec;

  // Act
  MyVec.PushBack(7.12);
  MyVec.PushBack(9.32);
  MyVec.PushBack(43.123);
  MyVec.PushBack(88.99);
  MyVec.PushBack(0.123);
  StdVec.push_back(7.12);
  StdVec.push_back(9.32);
  StdVec.push_back(43.123);
  StdVec.push_back(88.99);
  StdVec.push_back(0.123);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_DOUBLE_EQ(MyVec.At(i), StdVec.at(i));
    EXPECT_DOUBLE_EQ(MyVec[i], StdVec[i]);
  }
  EXPECT_DOUBLE_EQ(MyVec.Front(), StdVec.front());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PushBack4) {
  // Arrange
  s21::Vector<std::string> MyVec;
  std::vector<std::string> StdVec;

  // Act
  MyVec.PushBack("sergei");
  MyVec.PushBack("ravil");
  MyVec.PushBack("timur");
  MyVec.PushBack("ruslan");
  MyVec.PushBack("nataxa");
  StdVec.push_back("sergei");
  StdVec.push_back("ravil");
  StdVec.push_back("timur");
  StdVec.push_back("ruslan");
  StdVec.push_back("nataxa");

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec.at(i).c_str());
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());
  }
  EXPECT_STREQ(MyVec.Front().c_str(), StdVec.front().c_str());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PushBack5) {
  // Arrange
  s21::Vector<char> MyVec;
  std::vector<char> StdVec;

  // Act
  MyVec.PushBack('9');
  MyVec.PushBack('a');
  MyVec.PushBack('=');
  MyVec.PushBack('*');
  MyVec.PushBack(')');
  StdVec.push_back('9');
  StdVec.push_back('a');
  StdVec.push_back('=');
  StdVec.push_back('*');
  StdVec.push_back(')');

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
    EXPECT_EQ(MyVec[i], StdVec[i]);
  }
  EXPECT_EQ(MyVec.Front(), StdVec.front());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBackHead) { std::cout << "\n------------------\n"; }

TEST(Vector, PopBack1) {
  // Arrange
  s21::Vector<int> MyVec{78, 12, 32, 29, 1989, 9};
  std::vector<int> StdVec{78, 12, 32, 29, 1989, 9};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_EQ(StdVec.back(), MyVec.Back());
  for (size_t i = 0; i != StdVec.size(); ++i) EXPECT_EQ(StdVec[i], MyVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBack2) {
  // Arrange
  s21::Vector<double> MyVec{88.123, 7.23, 8.99, 9.88};
  std::vector<double> StdVec{88.123, 7.23, 8.99, 9.88};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_DOUBLE_EQ(StdVec.back(), MyVec.Back());
  for (size_t i = 0; i != StdVec.size(); ++i) EXPECT_EQ(StdVec[i], MyVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBack3) {
  // Arrange
  s21::Vector<double> MyVec{88.123, 7.23, 8.99};
  std::vector<double> StdVec{88.123, 7.23, 8.99};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_DOUBLE_EQ(StdVec.back(), MyVec.Back());
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_DOUBLE_EQ(StdVec[i], MyVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBack4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school", "sergei"};
  std::vector<std::string> StdVec{"suzyheim", "s21school", "sergei"};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_STREQ(StdVec.back().c_str(), MyVec.Back().c_str());
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_STREQ(StdVec[i].c_str(), MyVec[i].c_str());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBack5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school", "sergei", "suzyheim"};
  std::vector<std::string> StdVec{"suzyheim", "s21school", "sergei",
                                  "suzyheim"};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_STREQ(StdVec.back().c_str(), MyVec.Back().c_str());
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_STREQ(StdVec[i].c_str(), MyVec[i].c_str());

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, PopBack6) {
  // Arrange
  s21::Vector<char> MyVec{'a', 'b', 'c', 'd'};
  std::vector<char> StdVec{'a', 'b', 'c', 'd'};

  // Act
  StdVec.pop_back();
  MyVec.PopBack();

  // Assert
  EXPECT_EQ(StdVec.back(), MyVec.Back());
  for (size_t i = 0; i != StdVec.size(); ++i) EXPECT_EQ(StdVec[i], MyVec[i]);

  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ReserveHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Reserve1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.Reserve(10);
  StdVec.reserve(10);

  // Assert
  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Reserve2) {
  // Arrange
  s21::Vector<int> MyVec{32, 1, 98, 21};
  std::vector<int> StdVec{32, 1, 98, 21};

  // Act

  // Assert
  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(StdVec.at(i), MyVec.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  MyVec.Reserve(10);
  StdVec.reserve(10);

  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(StdVec.at(i), MyVec.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Reserve3) {
  // Arrange
  s21::Vector<double> MyVec{3.12, 4.543, 8.123, 898.584};
  std::vector<double> StdVec{3.12, 4.543, 8.123, 898.584};

  // Act

  // Assert
  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(StdVec.at(i), MyVec.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  MyVec.Reserve(10);
  StdVec.reserve(10);

  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_DOUBLE_EQ(StdVec.at(i), MyVec.At(i));
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, Reserve4) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "i am developer", "or not"};
  std::vector<std::string> StdVec{"suzyheim", "i am developer", "or not"};

  // Act

  // Assert
  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_STREQ(StdVec.at(i).c_str(), MyVec.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());

  MyVec.Reserve(10);
  StdVec.reserve(10);

  for (size_t i = 0; i < StdVec.size(); ++i) {
    EXPECT_STREQ(StdVec.at(i).c_str(), MyVec.At(i).c_str());
  }

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFitHead) { std::cout << "\n------------------\n"; }

TEST(Vector, ShrinkToFit1) {
  // Arrange
  s21::Vector<int> MyVec{1, 3, 4, 5, 6};
  std::vector<int> StdVec{1, 3, 4, 5, 6};

  // Act
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  StdVec.reserve(100);
  MyVec.Reserve(100);
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit3) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  StdVec.push_back(100);
  StdVec.push_back(200);
  MyVec.PushBack(100);
  MyVec.PushBack(200);
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit4) {
  // Arrange
  s21::Vector<int> MyVec{123, 123, 123};
  std::vector<int> StdVec{123, 123, 123};

  // Act
  StdVec.push_back(100);
  StdVec.push_back(200);
  MyVec.PushBack(100);
  MyVec.PushBack(200);
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit5) {
  // Arrange
  s21::Vector<double> MyVec{123.45, 123.786, 123.785};
  std::vector<double> StdVec{123.45, 123.786, 123.785};

  // Act
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit6) {
  // Arrange
  s21::Vector<double> MyVec{123.45, 123.786, 123.785};
  std::vector<double> StdVec{123.45, 123.786, 123.785};

  // Act
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  StdVec.erase(itStd);
  MyVec.Erase(itMy);
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, ShrinkToFit7) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "ruslan", "timur", "ravil"};
  std::vector<std::string> StdVec{"sergei", "ruslan", "timur", "ravil"};

  // Act
  MyVec.PushBack("friends forever");
  StdVec.push_back("friends forever");
  auto itMy = MyVec.Begin();
  auto itStd = StdVec.begin();
  StdVec.erase(itStd);
  MyVec.Erase(itMy);
  StdVec.shrink_to_fit();
  MyVec.ShrinkToFit();

  // Assert
  EXPECT_EQ(MyVec.Size(), StdVec.size());
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
}

TEST(Vector, SizeHead) { std::cout << "\n------------------\n"; }

TEST(Vector, Size1) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Size2) {
  // Arrange
  s21::Vector<int> MyVec;
  std::vector<int> StdVec;

  // Act
  MyVec.PushBack(13);
  StdVec.push_back(13);

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Size3) {
  // Arrange
  s21::Vector<double> MyVec{3.34, 10.1, 11, 23.41, 42};
  std::vector<double> StdVec{3.34, 10.1, 11, 23.41, 42};

  // Act
  //  MyVec.PushBack(32.12);
  //  StdVec.push_back(32.12);

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Size4) {
  // Arrange
  s21::Vector<std::string> MyVec{"serge", "suzyheim", "s21school"};
  std::vector<std::string> StdVec{"serge", "suzyheim", "s21school"};

  // Act
  MyVec.PushBack("exam-exam");
  StdVec.push_back("exam-exam");

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Size5) {
  // Arrange
  s21::Vector<char> MyVec;
  std::vector<char> StdVec;

  // Act
  MyVec.PushBack('a');
  MyVec.PushBack('b');
  StdVec.push_back('a');
  StdVec.push_back('b');

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, Size6) {
  // Arrange
  s21::Vector<int> MyVec{123, 122, 9, 87};
  std::vector<int> StdVec{123, 122, 9, 87};

  // Act
  MyVec.PushBack(123);
  StdVec.push_back(123);

  // Assert
  EXPECT_EQ(MyVec.Capacity(), StdVec.capacity());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, SwapHead) { std::cout << "\n------------------\n"; }

TEST(Vector, SwapBack1) {
  // Arrange
  s21::Vector<int> MyVec{2};
  s21::Vector<int> MyVec2{2};
  std::vector<int> StdVec{2};
  std::vector<int> StdVec2{2};

  // Act
  auto *myVector = &MyVec[0];
  auto *myVector2 = &MyVec2[0];
  auto *my = &MyVec;
  auto *my2 = &MyVec2;
  MyVec.Swap(MyVec2);

  auto *stdVector = &StdVec[0];
  auto *stdVector2 = &StdVec2[0];
  auto *std = &StdVec;
  auto *std2 = &StdVec2;
  StdVec.swap(StdVec2);

  // Assert
  EXPECT_EQ(myVector, &MyVec2[0]);
  EXPECT_EQ(myVector2, &MyVec[0]);
  EXPECT_EQ(stdVector, &StdVec2[0]);
  EXPECT_EQ(stdVector2, &StdVec[0]);

  EXPECT_NE(my, &MyVec2);
  EXPECT_NE(my2, &MyVec);
  EXPECT_NE(std, &StdVec2);
  EXPECT_NE(std2, &StdVec);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, SwapBack2) {
  // Arrange
  s21::Vector<int> MyVec{2, 3, 4, 5};
  s21::Vector<int> MyVec2{834, 21, 89, 33};
  std::vector<int> StdVec{2, 3, 4, 5};
  std::vector<int> StdVec2{834, 21, 89, 33};

  // Act
  auto *myVector = &MyVec[0];
  auto *myVector2 = &MyVec2[0];
  auto *my = &MyVec;
  auto *my2 = &MyVec2;
  MyVec.Swap(MyVec2);

  auto *stdVector = &StdVec[0];
  auto *stdVector2 = &StdVec2[0];
  auto *std = &StdVec;
  auto *std2 = &StdVec2;
  StdVec.swap(StdVec2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_EQ(MyVec2.At(i), StdVec2.at(i));
  }
  EXPECT_EQ(myVector, &MyVec2[0]);
  EXPECT_EQ(myVector2, &MyVec[0]);
  EXPECT_EQ(stdVector, &StdVec2[0]);
  EXPECT_EQ(stdVector2, &StdVec[0]);

  EXPECT_NE(my, &MyVec2);
  EXPECT_NE(my2, &MyVec);
  EXPECT_NE(std, &StdVec2);
  EXPECT_NE(std2, &StdVec);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, SwapBack3) {
  // Arrange
  s21::Vector<double> MyVec{45.123, 88.38, 99.12, 889.21};
  s21::Vector<double> MyVec2{77.123, 1.23, 32.12, 88.1};
  std::vector<double> StdVec{45.123, 88.38, 99.12, 889.21};
  std::vector<double> StdVec2{77.123, 1.23, 32.12, 88.1};

  // Act
  auto *myVector = &MyVec[0];
  auto *myVector2 = &MyVec2[0];
  auto *my = &MyVec;
  auto *my2 = &MyVec2;
  MyVec.Swap(MyVec2);

  auto *stdVector = &StdVec[0];
  auto *stdVector2 = &StdVec2[0];
  auto *std = &StdVec;
  auto *std2 = &StdVec2;
  StdVec.swap(StdVec2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_EQ(MyVec2.At(i), StdVec2.at(i));
  }
  EXPECT_EQ(myVector, &MyVec2[0]);
  EXPECT_EQ(myVector2, &MyVec[0]);
  EXPECT_EQ(stdVector, &StdVec2[0]);
  EXPECT_EQ(stdVector2, &StdVec[0]);

  EXPECT_NE(my, &MyVec2);
  EXPECT_NE(my2, &MyVec);
  EXPECT_NE(std, &StdVec2);
  EXPECT_NE(std2, &StdVec);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, SwapBack4) {
  // Arrange
  s21::Vector<char> MyVec{'$', '\'', '*', '#'};
  s21::Vector<char> MyVec2{'a', 'b', '5', '%', ',', ')'};
  std::vector<char> StdVec{'$', '\'', '*', '#'};
  std::vector<char> StdVec2{'a', 'b', '5', '%', ',', ')'};

  // Act
  auto *myVector = &MyVec[0];
  auto *myVector2 = &MyVec2[0];
  auto *my = &MyVec;
  auto *my2 = &MyVec2;
  MyVec.Swap(MyVec2);

  auto *stdVector = &StdVec[0];
  auto *stdVector2 = &StdVec2[0];
  auto *std = &StdVec;
  auto *std2 = &StdVec2;
  StdVec.swap(StdVec2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_EQ(MyVec2.At(i), StdVec2.at(i));
  }

  EXPECT_EQ(MyVec.At(0), 'a');
  EXPECT_EQ(MyVec2.At(0), '$');
  EXPECT_EQ(StdVec.at(0), 'a');
  EXPECT_EQ(StdVec2.at(0), '$');

  EXPECT_EQ(myVector, &MyVec2[0]);
  EXPECT_EQ(myVector2, &MyVec[0]);
  EXPECT_EQ(stdVector, &StdVec2[0]);
  EXPECT_EQ(stdVector2, &StdVec[0]);

  EXPECT_NE(my, &MyVec2);
  EXPECT_NE(my2, &MyVec);
  EXPECT_NE(std, &StdVec2);
  EXPECT_NE(std2, &StdVec);

  //	EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, SwapBack5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "sergei", "s21school"};
  s21::Vector<std::string> MyVec2{"marina", "irina", "nady"};
  std::vector<std::string> StdVec{"suzyheim", "sergei", "s21school"};
  std::vector<std::string> StdVec2{"marina", "irina", "nady"};

  // Act
  auto *myVector = &MyVec[0];
  auto *myVector2 = &MyVec2[0];
  auto *my = &MyVec;
  auto *my2 = &MyVec2;
  MyVec.Swap(MyVec2);

  auto *stdVector = &StdVec[0];
  auto *stdVector2 = &StdVec2[0];
  auto *std = &StdVec;
  auto *std2 = &StdVec2;
  StdVec.swap(StdVec2);

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i) {
    EXPECT_STREQ(MyVec.At(i).c_str(), StdVec.at(i).c_str());
  }
  for (size_t i = 0; i != StdVec2.size(); ++i) {
    EXPECT_STREQ(MyVec2.At(i).c_str(), StdVec2.at(i).c_str());
  }
  EXPECT_EQ(myVector, &MyVec2[0]);
  EXPECT_EQ(myVector2, &MyVec[0]);
  EXPECT_EQ(stdVector, &StdVec2[0]);
  EXPECT_EQ(stdVector2, &StdVec[0]);

  EXPECT_NE(my, &MyVec2);
  EXPECT_NE(my2, &MyVec);
  EXPECT_NE(std, &StdVec2);
  EXPECT_NE(std2, &StdVec);

  EXPECT_EQ(MyVec.MaxSize(), StdVec.max_size());
  EXPECT_EQ(MyVec.Size(), StdVec.size());
}

TEST(Vector, InsertManyHead) { std::cout << "\n------------------\n"; }

TEST(Vector, InsertMany1) {
  // Arrange
  s21::Vector<int> MyVec;

  // Act
  MyVec.PushBack(0);
  MyVec.PushBack(6);
  auto it = MyVec.Begin();
  ++it;
  MyVec.InsertMany(it, 1, 2, 3, 4, 5);
  size_t j = 0;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i, ++j) EXPECT_EQ(MyVec.At(i), j);
}

TEST(Vector, InsertMany2) {
  // Arrange
  s21::Vector<int> MyVec;

  // Act
  MyVec.PushBack(100);
  MyVec.PushBack(600);
  auto it = MyVec.Begin();
  ++it;
  MyVec.InsertMany(it, 200, 300, 400, 500);
  size_t j = 100;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i, j += 100)
    EXPECT_EQ(MyVec.At(i), j);
}

TEST(Vector, InsertMany3) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "suzyheim"};
  std::vector<std::string> StdVec{"sergei", "suzyheim", "sos",
                                  "my",     "names",    "s21school"};

  // Act
  auto it = MyVec.Begin();
  ++it;
  ++it;
  MyVec.InsertMany(it, "sos", "my", "names", "s21school");

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
}

TEST(Vector, InsertMany4) {
  // Arrange
  s21::Vector<std::string> MyVec{"sergei", "suzyheim"};
  std::vector<std::string> StdVec{
      "sos", "my", "names", "s21school", "sergei", "suzyheim",
  };

  // Act
  auto it = MyVec.Begin();
  MyVec.InsertMany(it, "sos", "my", "names", "s21school");

  // Assert
  for (size_t i = 0; i != StdVec.size(); ++i)
    EXPECT_EQ(MyVec.At(i), StdVec.at(i));
}

TEST(Vector, InsertManyBackHead) { std::cout << "\n------------------\n"; }

TEST(Vector, InsertManyBack1) {
  // Arrange
  s21::Vector<int> MyVec{2, 3, 4, 5, 6};

  // Act
  MyVec.InsertManyBack(7, 8, 9, 10, 11);
  size_t size = 10;
  size_t capacity = 10;

  // Assert
  size_t j = 2;
  for (size_t i = 0; i != MyVec.Size(); ++i, ++j) EXPECT_EQ(MyVec[i], j);
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, InsertManyBack2) {
  // Arrange
  s21::Vector<int> MyVec{12, 11, 10, 9, 8, 7};

  // Act
  MyVec.InsertManyBack(6, 5, 4, 3, 2, 1);
  size_t size = 12;
  size_t capacity = 12;

  // Assert
  size_t j = 12;
  for (size_t i = 0; i != MyVec.Size(); ++i, --j) EXPECT_EQ(MyVec[i], j);
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, InsertManyBack3) {
  // Arrange
  s21::Vector<char> MyVec{'0', '1', '2', '3', '4'};

  // Act
  MyVec.InsertManyBack('5', '6', '7', '8', '9');
  size_t size = 10;
  size_t capacity = 10;

  // Assert
  size_t j = '0';
  for (size_t i = 0; i != MyVec.Size(); ++i, ++j) EXPECT_EQ(MyVec[i], j);
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, InsertManyBack4) {
  // Arrange
  s21::Vector<char> MyVec{'9', '8', '7', '6', '5'};

  // Act
  MyVec.InsertManyBack('4', '3', '2', '1', '0');
  size_t size = 10;
  size_t capacity = 10;

  // Assert
  size_t j = '9';
  for (size_t i = 0; i != MyVec.Size(); ++i, --j) EXPECT_EQ(MyVec[i], j);
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, InsertManyBack5) {
  // Arrange
  s21::Vector<std::string> MyVec{"suzyheim", "s21school"};
  std::vector<std::string> StdVec{"suzyheim", "s21school", "what", "is",
                                  "this"};

  // Act
  MyVec.InsertManyBack("what", "is", "this");
  size_t size = 5;
  size_t capacity = 8;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_STREQ(MyVec[i].c_str(), StdVec[i].c_str());
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}

TEST(Vector, InsertManyBack6) {
  // Arrange
  s21::Vector<double> MyVec{8.11, 3.00, 394.134};
  std::vector<double> StdVec{8.11, 3.00, 394.134, 33.1, -1.23, 9.11};

  // Act
  MyVec.InsertManyBack(33.1, -1.23, 9.11);
  size_t size = 6;
  size_t capacity = 6;

  // Assert
  for (size_t i = 0; i != MyVec.Size(); ++i)
    EXPECT_DOUBLE_EQ(MyVec[i], StdVec[i]);
  EXPECT_EQ(MyVec.Size(), size);
  EXPECT_EQ(MyVec.Capacity(), capacity);
}
