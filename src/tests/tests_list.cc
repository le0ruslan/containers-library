#include <list>

#include "tests.h"

TEST(List, BackHead) { std::cout << "\n------------------\n"; }

TEST(List, BackChar1) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('c');
  StdList.push_back('q');

  // Assert
  EXPECT_NE(MyList.Back(), StdList.back());
}

TEST(List, BackChar2) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('c');
  StdList.push_back('c');

  // Assert
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackChar3) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('1');
  StdList.push_back('3');

  // Assert
  EXPECT_NE(MyList.Back(), StdList.back());
}

TEST(List, BackChar4) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('1');
  StdList.push_back('1');

  // Assert
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackInt1) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(10);
  StdList.push_back(3);

  // Assert
  EXPECT_NE(MyList.Back(), StdList.back());
}

TEST(List, BackInt2) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(12309);
  StdList.push_back(12309);

  // Assert
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackDouble1) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act
  MyList.PushBack(10.1220);
  StdList.push_back(10.1220);

  // Assert
  EXPECT_DOUBLE_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackDouble2) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act
  MyList.PushBack(12309.1234);
  StdList.push_back(12309.1234);

  // Assert
  EXPECT_DOUBLE_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackStr1) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act
  MyList.PushBack("sergei");
  StdList.push_back("sergei");
  MyList.PushBack("suzyheim");
  StdList.push_back("suzyheim");

  // Assert
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, BackStr2) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act
  MyList.PushBack("12309.1234");
  StdList.push_back("12309.1234");
  MyList.PushBack("89.9876");
  StdList.push_back("89.9876");

  // Assert
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, BeginHead) { std::cout << "\n------------------\n"; }

TEST(List, Begin1) {
  // Arrange
  s21::List<int> MyList{1, 2, 3};
  std::list<int> StdList{1, 2, 3};

  // Act
  std::list<int>::iterator itStd = StdList.begin();
  s21::List<int>::iterator itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Begin2) {
  // Arrange
  s21::List<double> MyList{34.123, 2.345, 3.874};
  std::list<double> StdList{34.123, 2.345, 3.874};

  // Act
  std::list<double>::iterator itStd = StdList.begin();
  s21::List<double>::iterator itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itMy, ++itStd) {
    EXPECT_DOUBLE_EQ(*itMy, *itStd);
  }
}

TEST(List, Begin3) {
  // Arrange
  s21::List<std::string> MyList{"34.123", "2.345", "3.874"};
  std::list<std::string> StdList{"34.123", "2.345", "3.874"};

  // Act
  std::list<std::string>::iterator itStd = StdList.begin();
  s21::List<std::string>::iterator itMy = MyList.Begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) EXPECT_EQ(*itMy, *itStd);
}

TEST(List, Begin4) {
  // Arrange
  s21::List<char> MyList{'a', 'y', 'u', 'i', 'o', 't'};
  std::list<char> StdList{'a', 'y', 'u', 'i', 'o', 't'};

  // Act
  MyList.Reverse();
  StdList.reverse();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) EXPECT_EQ(*itMy, *itStd);
}

TEST(List, ClearHead) { std::cout << "\n------------------\n"; }

TEST(List, Clear1) {
  // Arrange
  s21::List<int> MyList{1, 3, 4};
  std::list<int> StdList{1, 3, 4};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  MyList.Clear();
  StdList.clear();
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Clear2) {
  // Arrange
  s21::List<double> MyList{1.1, 3.3, 4.4};
  std::list<double> StdList{1.1, 3.4, 4.4};

  // Act
  StdList.push_back(34.34);
  StdList.push_back(6854.6854);
  MyList.PushBack(34.34);
  MyList.PushBack(6854.6854);

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  MyList.Clear();
  StdList.clear();
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Clear3) {
  // Arrange
  s21::List<std::string> MyList{"1.1", "3.3", "4.4"};
  std::list<std::string> StdList{"1.1", "3.4", "4.4"};

  // Act
  StdList.push_back("34.34");
  StdList.push_back("6854.6854");
  MyList.PushBack("34.34");
  MyList.PushBack("6854.6854");

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  MyList.Clear();
  StdList.clear();
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Clear4) {
  // Arrange
  s21::List<double> MyList{123.123, 389.389, 4.444};
  std::list<double> StdList{1.23, 39.89, 4.4};

  // Act
  StdList.push_back(34.34);
  StdList.push_back(64.64);
  MyList.PushBack(34.34);
  MyList.PushBack(6854.6854);

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  MyList.Clear();
  StdList.clear();
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Clear5) {
  // Arrange
  s21::List<std::string> MyList{"1.1", "3.3", "4.4"};

  // Act
  MyList.PushBack("34.34");
  MyList.PushBack("6854.6854");

  // Assert
  EXPECT_EQ(MyList.Size(), 5);
  MyList.Clear();
  EXPECT_EQ(MyList.Size(), 0);
}

TEST(List, ConstHead) { std::cout << "\n------------------\n"; }

TEST(List, ConstructorDefault1) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, ConstructorDefault2) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, ConstructorOne1) {
  // Arrange
  s21::List<int> MyList{1};
  std::list<int> StdList{1};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, ConstructorOne2) {
  // Arrange
  s21::List<int> MyList{2};
  std::list<int> StdList{2};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, ConstructorOne3) {
  // Arrange
  s21::List<char> MyList{'1'};
  std::list<char> StdList{'3'};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_NE(MyList.Front(), StdList.front());
}

TEST(List, ConstructorOne4) {
  // Arrange
  s21::List<double> MyList{3.1};
  std::list<double> StdList{3.1};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
}

TEST(List, ConstList1) {
  // Arrange
  s21::List<char> MyList{'a', '1', 'q'};
  std::list<char> StdList{'a', '1', 'q'};

  // Act

  // Assert
  for (size_t i = 0; i != MyList.Size(); ++i) {
    EXPECT_EQ(MyList.Front(), StdList.front());
    EXPECT_EQ(MyList.Back(), StdList.back());
    EXPECT_EQ(MyList.Size(), StdList.size());
  }
}

TEST(List, ConstrDefault1) {
  // Arrange
  s21::List<int> MyList{3};
  std::list<int> StdList{3};

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, ConstrDefault2) {
  // Arrange
  s21::List<int> MyList(3);
  std::list<int> StdList(3);

  // Act

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, CopyConstrHead) { std::cout << "\n------------------\n"; }

TEST(List, CopyConstr1) {
  // Arrange
  s21::List<int> MyList{3, 78, 98};
  std::list<int> StdList{3, 78, 98};

  // Act
  s21::List<int> MyList2(MyList);
  std::list<int> StdList2(StdList);

  // Assert
  EXPECT_EQ(MyList2.Front(), StdList2.front());
  EXPECT_EQ(MyList2.Back(), StdList2.back());
}

TEST(List, CopyConstr2) {
  // Arrange
  s21::List<double> MyList{3.33, 78.78, 98.98};
  std::list<double> StdList{3.33, 78.78, 98.98};

  // Act
  s21::List<double> MyList2(MyList);
  std::list<double> StdList2(StdList);

  // Assert
  EXPECT_DOUBLE_EQ(MyList2.Front(), StdList2.front());
  EXPECT_DOUBLE_EQ(MyList2.Back(), StdList2.back());
}

TEST(List, CopyConstr3) {
  // Arrange
  s21::List<double> MyList{3.1234, 78.9876, 123.456};
  std::list<double> StdList{3.1234, 78.9876, 123.456};

  // Act
  s21::List<double> MyList2(MyList);
  std::list<double> StdList2(StdList);

  // Assert
  EXPECT_DOUBLE_EQ(MyList2.Front(), StdList2.front());
  EXPECT_DOUBLE_EQ(MyList2.Back(), StdList2.back());
}

TEST(List, CopyConstr4) {
  // Arrange
  s21::List<std::string> MyList{"car", "my", "?"};
  std::list<std::string> StdList{"car", "my", "?"};

  // Act
  s21::List<std::string> MyList2(MyList);
  std::list<std::string> StdList2(StdList);
  int isFront = strcmp(MyList2.Front().c_str(), StdList2.front().c_str());
  int isBack = strcmp(MyList2.Back().c_str(), StdList2.back().c_str());

  // Assert
  EXPECT_EQ(isFront, 0);
  EXPECT_EQ(isBack, 0);
}

TEST(List, CopyConstr5) {
  // Arrange
  s21::List<std::string> MyList{"my", "Sergei"};
  std::list<std::string> StdList{"my", "Sergei"};

  // Act
  s21::List<std::string> MyList2(MyList);
  std::list<std::string> StdList2(StdList);
  int isFront = strcmp(MyList2.Front().c_str(), StdList2.front().c_str());
  int isBack = strcmp(MyList2.Back().c_str(), StdList2.back().c_str());

  // Assert
  EXPECT_EQ(isFront, 0);
  EXPECT_EQ(isBack, 0);
}

TEST(List, CopyConstr6) {
  // Arrange
  s21::List<std::string> MyList{"S21School", "suzyheim"};
  std::list<std::string> StdList{"S21School", "suzyheim"};

  // Act
  s21::List<std::string> MyList2(MyList);
  std::list<std::string> StdList2(StdList);
  int isFront = strcmp(MyList2.Front().c_str(), StdList2.front().c_str());
  int isBack = strcmp(MyList2.Back().c_str(), StdList2.back().c_str());

  // Assert
  EXPECT_EQ(isFront, 0);
  EXPECT_EQ(isBack, 0);
}

TEST(List, EmptyHead) { std::cout << "\n------------------\n"; }

TEST(List, Empty1) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty2) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty3) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty4) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty5) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(14);
  StdList.push_back(14);

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty6) {
  // Arrange
  s21::List<double> MyList{33.321, 43.09, 32.123};
  std::list<double> StdList{33.321, 43.09, 32.123};

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty7) {
  // Arrange
  s21::List<std::string> MyList{"sergei", "suzyheim"};
  std::list<std::string> StdList{"sergei", "suzyheim"};

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, Empty8) {
  // Arrange
  s21::List<char> MyList{'3', 'd', '4', 'a', 'e', 'u'};
  std::list<char> StdList{'3', 'd', '4', 'a', 'e', 'u'};

  // Act

  // Assert
  EXPECT_EQ(MyList.IsEmpty(), StdList.empty());
}

TEST(List, EraseHead) { std::cout << "\n------------------\n"; }

TEST(List, Erase1) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4};
  std::list<int> StdList{1, 2, 3, 4};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  MyList.Erase(itMy);
  StdList.erase(itStd);

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Erase2) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4};
  std::list<int> StdList{1, 2, 3, 4};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();
  MyList.Erase(itMy);
  StdList.erase(itStd);

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount)
    EXPECT_EQ(*itMyCount, *itStdCount);
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Erase3) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4};
  std::list<int> StdList{1, 2, 3, 4};

  // Act
  MyList.Reverse();
  StdList.reverse();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();
  MyList.Erase(itMy);
  StdList.erase(itStd);

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount)
    EXPECT_EQ(*itMyCount, *itStdCount);
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Erase4) {
  // Arrange
  s21::List<double> MyList{345.1234, 4567.12, 34.87, 9.453};
  std::list<double> StdList{345.1234, 4567.12, 34.87, 9.453};

  // Act
  MyList.Reverse();
  StdList.reverse();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();
  MyList.Erase(itMy);
  StdList.erase(itStd);

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount)
    EXPECT_DOUBLE_EQ(*itMyCount, *itStdCount);
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, FrontHead) { std::cout << "\n------------------\n"; }

TEST(List, FrontChar1) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('c');
  StdList.push_back('q');

  // Assert
  EXPECT_NE(MyList.Front(), StdList.front());
}

TEST(List, FrontChar2) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('c');
  StdList.push_back('c');

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontChar3) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('1');
  StdList.push_back('3');

  // Assert
  EXPECT_NE(MyList.Front(), StdList.front());
}

TEST(List, FrontChar4) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('1');
  StdList.push_back('1');

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontInt1) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(10);
  StdList.push_back(3);

  // Assert
  EXPECT_NE(MyList.Front(), StdList.front());
}

TEST(List, FrontInt2) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(12309);
  StdList.push_back(12309);

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontDouble1) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act
  MyList.PushBack(10.1220);
  StdList.push_back(10.1220);

  // Assert
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontDouble2) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act
  MyList.PushBack(12309.1234);
  StdList.push_back(12309.1234);

  // Assert
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontStr1) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act
  MyList.PushBack("sergei");
  StdList.push_back("sergei");

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, FrontStr2) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act
  MyList.PushBack("12309.1234");
  StdList.push_back("12309.1234");

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, InsertHead) { std::cout << "\n------------------\n"; }

TEST(List, Insert1) {
  // Arrange
  int num = 34;
  s21::List<int> MyList{1, 2, 3};
  std::list<int> StdList{1, 2, 3};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  MyList.Insert(itMy, num);
  StdList.insert(itStd, num);

  // Assert
  EXPECT_EQ(*(--itMy), num);
  EXPECT_EQ(*(--itStd), num);
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Insert2) {
  // Arrange
  double num = 456.123;
  s21::List<double> MyList{1.123, 2.234, 3.456};
  std::list<double> StdList{1.123, 2.234, 3.456};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  auto itMyCount = MyList.Begin();
  auto itStdCount = MyList.Begin();
  MyList.Insert(itMy, num);
  StdList.insert(itStd, num);

  // Assert
  EXPECT_DOUBLE_EQ(*(--itMy), num);
  EXPECT_DOUBLE_EQ(*(--itStd), num);
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_DOUBLE_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Insert3) {
  // Arrange
  char num = 'b';
  s21::List<char> MyList{'a', 'c', 'd'};
  std::list<char> StdList{'a', 'c', 'd'};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  auto itMyCount = MyList.Begin();
  auto itStdCount = MyList.Begin();
  MyList.Insert(itMy, num);
  StdList.insert(itStd, num);

  // Assert
  EXPECT_EQ(*(--itMy), num);
  EXPECT_EQ(*(--itStd), num);
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, Insert4) {
  // Arrange
  char num = 'q';
  s21::List<char> MyList{'a', 'c', 'd', 'a', 'i', 'i', 'q'};
  std::list<char> StdList{'a', 'c', 'd', 'a', 'i', 'i', 'q'};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  auto itMyCount = MyList.Begin();
  auto itStdCount = MyList.Begin();
  MyList.Insert(itMy, num);
  StdList.insert(itStd, num);

  // Assert
  EXPECT_EQ(*(--itMy), num);
  EXPECT_EQ(*(--itStd), num);
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Size(), StdList.size());
}

TEST(List, MaxSizeHead) { std::cout << "\n------------------\n"; }

TEST(List, MaxSize1) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.MaxSize(), StdList.max_size());
}

TEST(List, MaxSize2) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.MaxSize(), StdList.max_size());
}

TEST(List, MaxSize3) {
  // Arrange
  s21::List<float> MyList;
  std::list<float> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.MaxSize(), StdList.max_size());
}

TEST(List, MaxSize4) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.MaxSize(), StdList.max_size());
}

TEST(List, MaxSize5) {
  // Arrange
  s21::List<std::vector<int>> MyList;
  std::list<std::vector<int>> StdList;

  // Act

  // Assert
  EXPECT_EQ(MyList.MaxSize(), StdList.max_size());
}

TEST(List, MergeHead) { std::cout << "\n------------------\n"; }

TEST(List, Merge1) {
  // Arrange
  s21::List<int> MyList1{3, 2, 5, 9};
  s21::List<int> MyList2{12, 3, 15, 129};
  std::list<int> StdList2{12, 3, 15, 129};
  std::list<int> StdList1{3, 2, 5, 9};

  // Act
  MyList1.Sort();
  MyList2.Sort();
  StdList1.sort();
  StdList2.sort();
  MyList1.Merge(MyList2);
  StdList1.merge(StdList2);
  auto itMy = MyList1.Begin();
  auto itStd = StdList1.begin();

  // Assert
  for (; itMy != MyList1.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Merge2) {
  // Arrange
  s21::List<int> MyList1{3, 2, 5, 9, 34, 10, 99};
  s21::List<int> MyList2{12, 3, 15, 129, 32, 12, 33};
  std::list<int> StdList2{12, 3, 15, 129, 32, 12, 33};
  std::list<int> StdList1{3, 2, 5, 9, 34, 10, 99};

  // Act
  MyList1.Sort();
  MyList2.Sort();
  StdList1.sort();
  StdList2.sort();
  MyList1.Merge(MyList2);
  StdList1.merge(StdList2);
  auto itMy = MyList1.Begin();
  auto itStd = StdList1.begin();

  // Assert
  for (; itMy != MyList1.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Merge3) {
  // Arrange
  s21::List<double> MyList1{3.88, 2.123, 5.987, 321.9, 123.34, 34123.10, 0.99};
  s21::List<double> MyList2{12, 3, 15, 129, 32, 12, 33};
  std::list<double> StdList2{12, 3, 15, 129, 32, 12, 33};
  std::list<double> StdList1{3.88, 2.123, 5.987, 321.9, 123.34, 34123.10, 0.99};

  // Act
  MyList1.Sort();
  MyList2.Sort();
  StdList1.sort();
  StdList2.sort();
  MyList1.Merge(MyList2);
  StdList1.merge(StdList2);
  auto itMy = MyList1.Begin();
  auto itStd = StdList1.begin();

  // Assert
  for (; itMy != MyList1.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Merge4) {
  // Arrange
  s21::List<char> MyList1{'b', 'D', 'e', '1', '8', '3', 'A'};
  s21::List<char> MyList2{'q', 'w', 'v', 'x'};
  std::list<char> StdList2{'b', 'D', 'e', '1', '8', '3', 'A'};
  std::list<char> StdList1{'q', 'w', 'v', 'x'};

  // Act
  MyList1.Sort();
  MyList2.Sort();
  StdList1.sort();
  StdList2.sort();
  MyList1.Merge(MyList2);
  StdList1.merge(StdList2);
  auto itMy = MyList1.Begin();
  auto itStd = StdList1.begin();

  // Assert
  for (; itMy != MyList1.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, MoveAssignHead) { std::cout << "\n------------------\n"; }

TEST(List, MoveAssign) {
  // Arrange
  s21::List<double> MyList{3.33, 8.88, 10.11};

  // Act
  s21::List<double> MyList2;
  MyList2 = std::move(MyList);

  // Assert
  EXPECT_DOUBLE_EQ(MyList2.Front(), 3.33);
  EXPECT_DOUBLE_EQ(MyList2.Back(), 10.11);
}

TEST(List, MoveAssign2) {
  // Arrange
  s21::List<std::string> MyList{"sergei", "8.88", "suzyheim"};

  // Act
  s21::List<std::string> MyList2;
  MyList2 = std::move(MyList);

  // Assert
  EXPECT_STREQ(MyList2.Front().c_str(), "sergei");
  EXPECT_STREQ(MyList2.Back().c_str(), "suzyheim");
}

TEST(List, MoveAssign3) {
  // Arrange
  s21::List<int> MyList{33, 88, 11};

  // Act
  s21::List<int> MyList2;
  MyList2 = std::move(MyList);

  // Assert
  EXPECT_EQ(MyList2.Front(), 33);
  EXPECT_EQ(MyList2.Back(), 11);
}

TEST(List, MoveAssign4) {
  // Arrange
  s21::List<std::string> MyList{"Sergei Popov", "8.88", "S21School"};

  // Act
  // MyList = std::move(MyList);

  // Assert
  EXPECT_STREQ(MyList.Front().c_str(), "Sergei Popov");
  EXPECT_STREQ(MyList.Back().c_str(), "S21School");
}

TEST(List, MoveAssign5) {
  // Arrange
  s21::List<std::string> MyList{"Popov", "8.88"};
  s21::List<std::string> MyList2{"Sergei", "s21School"};

  // Act
  MyList2 = std::move(MyList);

  // Assert
  EXPECT_STREQ(MyList2.Front().c_str(), "Popov");
  EXPECT_STREQ(MyList2.Back().c_str(), "8.88");

  EXPECT_STREQ(MyList.Front().c_str(), "Sergei");
  EXPECT_STREQ(MyList.Back().c_str(), "s21School");
}

TEST(List, MoveCstorHead) { std::cout << "\n------------------\n"; }

TEST(List, MoveCstor) {
  // Arrange
  s21::List<double> MyList{3.33, 8.88, 10.11};

  // Act
  s21::List<double> MyList2(std::move(MyList));

  // Assert
  EXPECT_DOUBLE_EQ(MyList2.Front(), 3.33);
  EXPECT_DOUBLE_EQ(MyList2.Back(), 10.11);
}

TEST(List, MoveCstor2) {
  // Arrange
  s21::List<std::string> MyList{"sergei", "8.88", "suzyheim"};

  // Act
  s21::List<std::string> MyList2(std::move(MyList));

  // Assert
  EXPECT_STREQ(MyList2.Front().c_str(), "sergei");
  EXPECT_STREQ(MyList2.Back().c_str(), "suzyheim");
}

TEST(List, MoveCstor3) {
  // Arrange
  s21::List<int> MyList{33, 88, 11};

  // Act
  s21::List<int> MyList2(std::move(MyList));

  // Assert
  EXPECT_EQ(MyList2.Front(), 33);
  EXPECT_EQ(MyList2.Back(), 11);
}

TEST(List, MoveCstor4) {
  // Arrange
  s21::List<std::string> MyList{"Sergei Popov", "8.88", "S21School"};

  // Act
  s21::List<std::string> MyList2(std::move(MyList));

  // Assert
  EXPECT_STREQ(MyList2.Front().c_str(), "Sergei Popov");
  EXPECT_STREQ(MyList2.Back().c_str(), "S21School");
}

TEST(List, MoveCstor5) {
  // Arrange
  s21::List<std::string> MyList{"Popov", "8.88"};

  // Act
  s21::List<std::string> MyList2(std::move(MyList));

  // Assert
  EXPECT_STREQ(MyList2.Front().c_str(), "Popov");
  EXPECT_STREQ(MyList2.Back().c_str(), "8.88");
}

TEST(List, OperAssigHead) { std::cout << "\n------------------\n"; }

TEST(List, OperAssign1) {
  // Arrange
  s21::List<std::string> MyList{"sergei", "s21school", "suzyheim"};
  s21::List<std::string> MyList2{"sergei2", "s21school2", "suzyheim2"};

  // Act

  // Assert
  EXPECT_STRNE(MyList.Back().c_str(), MyList2.Back().c_str());
  EXPECT_STRNE(MyList.Front().c_str(), MyList2.Front().c_str());

  MyList = MyList2;

  EXPECT_STREQ(MyList.Front().c_str(), MyList2.Front().c_str());
  EXPECT_STREQ(MyList.Back().c_str(), MyList2.Back().c_str());
}

TEST(List, OperAssign2) {
  // Arrange
  s21::List<std::string> MyList{"sergei", "s21school", "suzyheim"};
  s21::List<std::string> MyList2{"ruslan", "s21school2", "ros"};
  std::list<std::string> StdList{"sergei", "s21school", "suzyheim"};
  std::list<std::string> StdList2{"se2", "s212", "su2"};

  // Act

  // Assert
  EXPECT_STRNE(MyList.Back().c_str(), MyList2.Back().c_str());
  EXPECT_STRNE(MyList.Front().c_str(), MyList2.Front().c_str());

  EXPECT_STRNE(StdList.back().c_str(), StdList2.back().c_str());
  EXPECT_STRNE(StdList.front().c_str(), StdList2.front().c_str());

  MyList = MyList2;
  StdList = StdList2;

  EXPECT_STREQ(MyList.Front().c_str(), MyList2.Front().c_str());
  EXPECT_STREQ(MyList.Back().c_str(), MyList2.Back().c_str());

  EXPECT_STREQ(StdList.back().c_str(), StdList2.back().c_str());
  EXPECT_STREQ(StdList.front().c_str(), StdList2.front().c_str());
}

TEST(List, OperAssign3) {
  // Arrange
  s21::List<double> MyList;
  s21::List<double> MyList2{43.3402, 999.999, 321.123};

  // Act
  MyList = MyList2;

  // Assert
  EXPECT_EQ(MyList.Front(), MyList2.Front());
  EXPECT_EQ(MyList.Back(), MyList2.Back());
}

TEST(List, OperAssign4) {
  // Arrange
  s21::List<double> MyList2{43.3402, 999.999, 321.123};

  // Act
  MyList2 = MyList2;

  // Assert
  EXPECT_EQ(MyList2.Front(), 43.3402);
  EXPECT_EQ(MyList2.Back(), 321.123);
}

TEST(List, OperAssign5) {
  // Arrange
  s21::List<int> MyList2{43, 999, 321};
  s21::List<int> MyList;

  // Act
  MyList = MyList2;

  // Assert
  EXPECT_EQ(MyList.Front(), 43);
  EXPECT_EQ(MyList.Back(), 321);
}

TEST(List, PopBackHead) { std::cout << "\n------------------\n"; }

TEST(List, PopBack1) {
  // Arrange
  s21::List<int> MyList{3, 4, 5, 80};
  std::list<int> StdList{3, 4, 5, 80};

  // Act
  MyList.PopBack();
  StdList.pop_back();

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Back(), StdList.back());
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, PopBack2) {
  // Arrange
  s21::List<double> MyList{3.3212, 4.1234};
  std::list<double> StdList{3.3212, 4.1234};

  // Act
  MyList.PopBack();
  StdList.pop_back();

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_DOUBLE_EQ(MyList.Back(), StdList.back());
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
}

TEST(List, PopBack3) {
  // Arrange
  s21::List<char> MyList{'3', 'd', '5'};
  std::list<char> StdList{'3', 'd', '5'};

  // Act
  MyList.PopBack();
  StdList.pop_back();

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Back(), StdList.back());
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, PopBack4) {
  // Arrange
  s21::List<std::string> MyList{"3.444", "d", "sergei"};
  std::list<std::string> StdList{"3.444", "d", "suzyheim"};

  // Act
  MyList.PopBack();
  StdList.pop_back();

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_STREQ(MyList.Back().c_str(), StdList.back().c_str());
  EXPECT_STREQ(MyList.Front().c_str(), StdList.front().c_str());
}

TEST(List, PopBack5) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(12345);
  MyList.PushBack(342134);
  MyList.PushBack(893021);
  StdList.push_back(12345);
  StdList.push_back(342134);
  StdList.push_back(893021);
  MyList.PopBack();
  StdList.pop_back();

  // Assert
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Back(), StdList.back());
  EXPECT_EQ(MyList.Front(), StdList.front());
}

TEST(List, PopFrontHead) { std::cout << "\n------------------\n"; }

TEST(List, PopFront) {
  // Arrange
  int value = 2;
  int size = 3;
  s21::List<int> MyList{1, 2, 3, 4};
  std::list<int> StdList{1, 2, 3, 4};

  // Act
  MyList.PopFront();
  StdList.pop_front();

  // Assert
  EXPECT_EQ(MyList.Size(), size);
  EXPECT_EQ(StdList.size(), size);
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Front(), value);
}

TEST(List, PopFront2) {
  // Arrange
  double value = 2.4321;
  int size = 3;
  s21::List<double> MyList{1.1234, 2.4321, 3, 4};
  std::list<double> StdList{1.1234, 2.4321, 3, 4};

  // Act
  MyList.PopFront();
  StdList.pop_front();

  // Assert
  EXPECT_EQ(MyList.Size(), size);
  EXPECT_EQ(StdList.size(), size);
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
  EXPECT_DOUBLE_EQ(MyList.Front(), value);
}

TEST(List, PopFront3) {
  // Arrange
  double value = 1.1234;
  int size = 3;
  s21::List<double> MyList{2.4321, 1.1234, 3, 4};
  std::list<double> StdList{2.4321, 1.1234, 3, 4};

  // Act
  MyList.PopFront();
  StdList.pop_front();

  // Assert
  EXPECT_EQ(MyList.Size(), size);
  EXPECT_EQ(StdList.size(), size);
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
  EXPECT_DOUBLE_EQ(MyList.Front(), value);
}

TEST(List, PopFront4) {
  // Arrange
  std::string value = "1.1234";
  int size = 2;
  s21::List<std::string> MyList{"2.4321", "1.1234", "3"};
  std::list<std::string> StdList{"2.4321", "1.1234", "3"};

  // Act
  MyList.PopFront();
  StdList.pop_front();

  // Assert
  EXPECT_EQ(MyList.Size(), size);
  EXPECT_EQ(StdList.size(), size);
  EXPECT_STREQ(MyList.Front().c_str(), StdList.front().c_str());
  EXPECT_STREQ(MyList.Front().c_str(), value.c_str());
}

TEST(List, PopFront5) {
  // Arrange
  char value = '2';
  int size = 3;
  s21::List<char> MyList{'1', '2', '3', '4'};
  std::list<char> StdList{'1', '2', '3', '4'};

  // Act
  MyList.PopFront();
  StdList.pop_front();

  // Assert
  EXPECT_EQ(MyList.Size(), size);
  EXPECT_EQ(StdList.size(), size);
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Front(), value);
}

TEST(List, PushBackHead) { std::cout << "\n------------------\n"; }

TEST(List, PushBack) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(10);
  StdList.push_back(10);

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, PushBack2) {
  // Arrange
  s21::List<double> MyList;
  std::list<double> StdList;

  // Act
  MyList.PushBack(10.1234);
  StdList.push_back(10.1234);

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, PushBack3) {
  // Arrange
  s21::List<char> MyList;
  std::list<char> StdList;

  // Act
  MyList.PushBack('c');
  StdList.push_back('c');

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, PushBack4) {
  // Arrange
  s21::List<int> MyList;
  std::list<int> StdList;

  // Act
  MyList.PushBack(1343);
  MyList.PushBack(134);
  MyList.PushBack(8456);
  StdList.push_back(1343);
  StdList.push_back(134);
  StdList.push_back(8456);

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, PushBack5) {
  // Arrange
  s21::List<std::string> MyList;
  std::list<std::string> StdList;

  // Act
  MyList.PushBack("1343");
  MyList.PushBack("134");
  MyList.PushBack("8456");
  StdList.push_back("1343");
  StdList.push_back("134");
  StdList.push_back("8456");

  // Assert
  EXPECT_STREQ(MyList.Front().c_str(), StdList.front().c_str());
  EXPECT_STREQ(MyList.Back().c_str(), StdList.back().c_str());
}

TEST(List, PushFrontHead) { std::cout << "\n------------------\n"; }

TEST(List, PushFront1) {
  // Arrange
  s21::List<int> MyList{1, -1, 11};
  std::list<int> StdList{1, -1, 11};

  // Act
  MyList.PushFront(555);
  StdList.push_front(555);

  // Assert
  EXPECT_EQ(MyList.Front(), 555);
  EXPECT_EQ(StdList.front(), 555);
}

TEST(List, PushFront2) {
  // Arrange
  int num = 9879;
  s21::List<int> MyList{89, 1, 9911};
  std::list<int> StdList{89, 1, 9911};

  // Act
  MyList.PushFront(num);
  StdList.push_front(num);

  // Assert
  EXPECT_EQ(MyList.Front(), num);
  EXPECT_EQ(StdList.front(), num);
}

TEST(List, PushFront3) {
  // Arrange
  double num = -1234.9876;
  s21::List<double> MyList{89, 1, 9911};
  std::list<double> StdList{89, 1, 9911};

  // Act
  MyList.PushFront(num);
  StdList.push_front(num);

  // Assert
  EXPECT_EQ(MyList.Front(), num);
  EXPECT_EQ(StdList.front(), num);
}

TEST(List, PushFront4) {
  // Arrange
  std::string value = "sergei";
  s21::List<std::string> MyList{"89", "1", "9911"};
  std::list<std::string> StdList{"89", "1", "9911"};

  // Act
  MyList.PushFront(value);
  StdList.push_front(value);

  // Assert
  EXPECT_STREQ(MyList.Front().c_str(), value.c_str());
  EXPECT_STREQ(StdList.front().c_str(), value.c_str());
  EXPECT_EQ(MyList.Size(), 4);
  EXPECT_EQ(StdList.size(), 4);
}

TEST(List, PushFront5) {
  // Arrange
  std::string value = "suzyheim";
  s21::List<std::string> MyList{"Sergei", "3", "1", "9911"};
  std::list<std::string> StdList{"89", "3", "1", "9911"};

  // Act
  MyList.PushFront(value);
  StdList.push_front(value);

  // Assert
  EXPECT_STREQ(MyList.Front().c_str(), value.c_str());
  EXPECT_STREQ(StdList.front().c_str(), value.c_str());
  EXPECT_STREQ(MyList.Back().c_str(), "9911");
  EXPECT_STREQ(StdList.back().c_str(), "9911");
  EXPECT_EQ(MyList.Size(), 5);
  EXPECT_EQ(StdList.size(), 5);
}

TEST(List, ReverseHead) { std::cout << "\n------------------\n"; }

TEST(List, Reverse1) {
  // Arrange
  s21::List<int> MyList{0, 1, 2, 3, 4, 5, 6, 7};
  std::list<int> StdList{0, 1, 2, 3, 4, 5, 6, 7};

  // Act
  MyList.Reverse();
  StdList.reverse();

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, Reverse2) {
  // Arrange
  s21::List<std::string> MyList{"sergei",
                                "school"
                                "suzyheim"};
  std::list<std::string> StdList{"sergei",
                                 "school"
                                 "suzyheim"};

  // Act
  MyList.Reverse();
  StdList.reverse();

  // Assert
  EXPECT_STREQ(MyList.Front().c_str(), StdList.front().c_str());
  EXPECT_STREQ(MyList.Back().c_str(), StdList.back().c_str());
}

TEST(List, Reverse3) {
  // Arrange
  s21::List<double> MyList{0.1234, 1, 2, 3, 4, 5, 6, 7.4321};
  std::list<double> StdList{0.1234, 1, 2, 3, 4, 5, 6, 7.4321};

  // Act
  MyList.Reverse();
  StdList.reverse();

  // Assert
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, SortHead) { std::cout << "\n------------------\n"; }

TEST(List, Sort1) {
  // Arrange
  s21::List<int> MyList{4, 3, 2, 6, 8, 9};
  std::list<int> StdList{4, 3, 2, 6, 8, 9};

  // Act
  MyList.Sort();
  StdList.sort();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Sort2) {
  // Arrange
  s21::List<int> MyList{-12, -3, 12, 86, 98, 109};
  std::list<int> StdList{-12, -3, 12, 86, 98, 109};

  // Act
  MyList.Sort();
  StdList.sort();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Sort3) {
  // Arrange
  s21::List<double> MyList{121.4, 1.233, 43.2, 32.6, 90.8, 1.239};
  std::list<double> StdList{121.4, 1.233, 43.2, 32.6, 90.8, 1.239};

  // Act
  MyList.Sort();
  StdList.sort();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, Sort4) {
  // Arrange
  s21::List<char> MyList{'b', 'c', 'e', 't', 'i', 'B', 'C'};
  std::list<char> StdList{'b', 'c', 'e', 't', 'i', 'B', 'C'};

  // Act
  MyList.Sort();
  StdList.sort();
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  // Assert
  for (; itMy != MyList.End(); ++itMy, ++itStd) {
    EXPECT_EQ(*itMy, *itStd);
  }
}

TEST(List, SpliceHead) { std::cout << "\n------------------\n"; }

TEST(List, Splice1) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4, 5};
  s21::List<int> MyList2{10, 20, 30, 40, 50};
  std::list<int> StdList{1, 2, 3, 4, 5};
  std::list<int> StdList2{10, 20, 30, 40, 50};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, Splice2) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4, 5};
  s21::List<int> MyList2{10, 20, 30, 40, 50};
  std::list<int> StdList{1, 2, 3, 4, 5};
  std::list<int> StdList2{10, 20, 30, 40, 50};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, Splice3) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4, 5};
  s21::List<int> MyList2{10, 20, 30, 40, 50};
  std::list<int> StdList{1, 2, 3, 4, 5};
  std::list<int> StdList2{10, 20, 30, 40, 50};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  std::advance(itStd, 4);
  for (int i = 0; i < 3; ++i) ++itMy;

  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  // auto itMyCount = MyList.Begin();
  // auto itStdCount = StdList.begin();

  // Assert
  std::cout << std::endl;
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, Splice4) {
  // Arrange
  s21::List<double> MyList{1.321, 0.2, 34.3, 48.4, 44.5};
  s21::List<double> MyList2{10.34, 20, 30, 40, 50.12};
  std::list<double> StdList{1.321, 0.2, 34.3, 48.4, 44.5};
  std::list<double> StdList2{10.34, 20, 30, 40, 50.12};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();
  ++itMy;
  ++itStd;
  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_DOUBLE_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_DOUBLE_EQ(MyList.Front(), StdList.front());
  EXPECT_DOUBLE_EQ(MyList.Back(), StdList.back());
}

TEST(List, Splice5) {
  // Arrange
  s21::List<char> MyList{'a', 'c', 't', 'i'};
  s21::List<char> MyList2{'t', 'e', 'i', 'e'};
  std::list<char> StdList{'a', 'c', 't', 'i'};
  std::list<char> StdList2{'t', 'e', 'i', 'e'};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, Splice6) {
  // Arrange
  s21::List<char> MyList{'t', 'q', 'o', 'q'};
  s21::List<char> MyList2{'l', 'i', 'q', 'p', 'y'};
  std::list<char> StdList{'t', 'q', 'o', 'q'};
  std::list<char> StdList2{'l', 'i', 'q', 'p', 'y'};

  // Act
  auto itMy = MyList.Begin();
  auto itStd = StdList.begin();

  MyList.Splice(itMy, MyList2);
  StdList.splice(itStd, StdList2);
  auto itMyCount = MyList.Begin();
  auto itStdCount = StdList.begin();

  // Assert
  for (; itMyCount != MyList.End(); ++itMyCount, ++itStdCount) {
    EXPECT_EQ(*itMyCount, *itStdCount);
  }
  EXPECT_EQ(MyList.Size(), StdList.size());
  EXPECT_EQ(MyList.Front(), StdList.front());
  EXPECT_EQ(MyList.Back(), StdList.back());
}

TEST(List, SwapHead) { std::cout << "\n------------------\n"; }

TEST(List, Swap1) {
  // Arrange
  s21::List<int> MyList{1, 2, 3, 4};
  s21::List<int> MyList2{5, 6, 7};

  // Act
  MyList.Swap(MyList2);
  auto itMy = MyList.Begin();
  auto itMy2 = MyList2.Begin();

  // Assert
  for (int i = 5; itMy != MyList.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (int i = 1; itMy2 != MyList2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(List, Swap2) {
  // Arrange
  s21::List<int> MyList{10, 11, 12, 13, 14};
  s21::List<int> MyList2{111, 112, 113, 114};

  // Act
  MyList.Swap(MyList2);
  auto itMy = MyList.Begin();
  auto itMy2 = MyList2.Begin();

  // Assert
  for (int i = 111; itMy != MyList.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (int i = 10; itMy2 != MyList2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(List, Swap3) {
  // Arrange
  s21::List<double> MyList{10.123, 11.123, 12.123, 13.123, 14.123};
  s21::List<double> MyList2{111.999, 112.999, 113.999, 114.999};

  // Act
  MyList.Swap(MyList2);
  auto itMy = MyList.Begin();
  auto itMy2 = MyList2.Begin();

  // Assert
  for (double i = 111.999; itMy != MyList.End(); ++itMy, ++i)
    EXPECT_EQ(*itMy, i);

  for (double i = 10.123; itMy2 != MyList2.End(); ++itMy2, ++i)
    EXPECT_EQ(*itMy2, i);
}

TEST(List, Swap4) {
  // Arrange
  s21::List<char> MyList{'a', 'b', 'c', 'd'};
  s21::List<char> MyList2{'e', 'f', 'g', 'h', 'i'};

  // Act
  MyList.Swap(MyList2);
  auto itMy = MyList.Begin();
  auto itMy2 = MyList2.Begin();

  // Assert
  for (char i = 'e'; itMy != MyList.End(); ++itMy, ++i) EXPECT_EQ(*itMy, i);

  for (char i = 'a'; itMy2 != MyList2.End(); ++itMy2, ++i) EXPECT_EQ(*itMy2, i);
}

TEST(List, Swap5) {
  // Arrange
  s21::List<char> MyList{'c', 'b', 'a'};
  s21::List<char> MyList2{'i', 'h', 'g', 'f', 'e'};

  // Act
  MyList.Swap(MyList2);
  auto itMy = MyList.Begin();
  auto itMy2 = MyList2.Begin();

  // Assert
  for (char i = 'i'; itMy != MyList.End(); ++itMy, --i) EXPECT_EQ(*itMy, i);

  for (char i = 'c'; itMy2 != MyList2.End(); ++itMy2, --i) EXPECT_EQ(*itMy2, i);
}

TEST(List, UniqueHead) { std::cout << "\n------------------\n"; }

TEST(List, Unique1) {
  // Arrange
  std::list<int> StdList{1, 1, 2, 2, 3, 4, 3, 4, 3, 4};
  s21::List<int> MyList{1, 1, 2, 2, 3, 4, 3, 4, 3, 4};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, Unique2) {
  // Arrange
  std::list<int> StdList{3,  3,  3,  4,  3,  4,  4,  1, 1,
                         32, 32, 32, 32, 32, 33, 33, 0};
  s21::List<int> MyList{3,  3,  3,  4,  3,  4,  4,  1, 1,
                        32, 32, 32, 32, 32, 33, 33, 0};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, Unique3) {
  // Arrange
  std::list<char> StdList{'a', 'a', 'b', 'a', 'b', 'b', 'e', 'e', 'f'};
  s21::List<char> MyList{'a', 'a', 'b', 'a', 'b', 'b', 'e', 'e', 'f'};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, Unique4) {
  // Arrange
  std::list<char> StdList{'z', 'a', 'z', 'z', 'z'};
  s21::List<char> MyList{'z', 'a', 'z', 'z', 'z'};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, Unique5) {
  // Arrange
  std::list<char> StdList{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  s21::List<char> MyList{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, Unique6) {
  // Arrange
  std::list<double> StdList{100.123, 100.123, 11.098, 11.098, 1.2, 3.2, 3, 3};
  s21::List<double> MyList{100.123, 100.123, 11.098, 11.098, 1.2, 3.2, 3, 3};

  // Act
  StdList.unique();
  MyList.Unique();
  auto itStd = StdList.begin();
  auto itMy = MyList.Begin();

  // Assert
  for (; itStd != StdList.end(); ++itStd, ++itMy) {
    EXPECT_EQ(*itStd, *itMy);
  }
  EXPECT_EQ(StdList.size(), MyList.Size());
  EXPECT_EQ(StdList.front(), MyList.Front());
  EXPECT_EQ(StdList.back(), MyList.Back());
}

TEST(List, InsertMany) {
  s21::List<int> MyList = {1, 5, 6};
  auto itMy = ++MyList.Begin();
  MyList.InsertMany(itMy, 2, 3, 4);
  int check = 1;
  for (auto it_temp = MyList.Begin(); it_temp != MyList.End(); ++it_temp) {
    EXPECT_EQ(check++, *it_temp);
  }
  EXPECT_EQ(7, check);
  EXPECT_EQ(6, MyList.Size());
  EXPECT_EQ(5, *itMy);
}

TEST(List, InsertManyFront) {
  s21::List<int> MyList = {3, 4, 5};
  MyList.InsertManyFront(2, 1, 0);
  int check = 0;
  for (auto it_temp = MyList.Begin(); it_temp != MyList.End(); ++it_temp) {
    EXPECT_EQ(check++, *it_temp);
  }
  EXPECT_EQ(6, check);
  EXPECT_EQ(6, MyList.Size());
}

TEST(List, InsertManyBack) {
  s21::List<int> MyList = {0, 1, 2};
  MyList.InsertManyBack(3, 4, 5, 6);
  int check = 0;
  for (auto it_temp = MyList.Begin(); it_temp != MyList.End(); ++it_temp) {
    EXPECT_EQ(check++, *it_temp);
  }
  EXPECT_EQ(7, check);
  EXPECT_EQ(7, MyList.Size());
}