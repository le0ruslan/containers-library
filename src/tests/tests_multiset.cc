#include <set>

#include "tests.h"

TEST(Multiset, BeginHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, Begin1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);

  // Assert
  EXPECT_EQ(*MyMultiset.Begin(), *StdMultiset.begin());
}

TEST(Multiset, Begin2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, Begin12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  EXPECT_EQ(*itMy1, *itStd1);
}

TEST(Multiset, CountHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, Count1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto countMy = MyMultiset.Count(3);
  auto countStd = StdMultiset.count(3);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto countMy = MyMultiset.Count(3);
  auto countStd = StdMultiset.count(3);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto countMy = MyMultiset.Count(3);
  auto countStd = StdMultiset.count(3);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto countMy = MyMultiset.Count(-1.12);
  auto countStd = StdMultiset.count(-1.12);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto countMy = MyMultiset.Count(-0.1);
  auto countStd = StdMultiset.count(-0.1);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto countMy = MyMultiset.Count(1.001);
  auto countStd = StdMultiset.count(1.001);

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto countMy = MyMultiset.Count("sergei");
  auto countStd = StdMultiset.count("sergei");

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto countMy = MyMultiset.Count("ser");
  auto countStd = StdMultiset.count("ser");

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto countMy = MyMultiset.Count("is");
  auto countStd = StdMultiset.count("is");

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto countMy = MyMultiset.Count('*');
  auto countStd = StdMultiset.count('*');

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto countMy = MyMultiset.Count(' ');
  auto countStd = StdMultiset.count(' ');

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto countMy = MyMultiset.Count('!');
  auto countStd = StdMultiset.count('!');

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, Count13) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto countMy = MyMultiset.Count('s');
  auto countStd = StdMultiset.count('s');

  // Assert
  EXPECT_EQ(countMy, countStd);
}

TEST(Multiset, EqualRangeHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, EqualRange1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto equal_rangeMy = MyMultiset.EqualRange(3);
  auto equal_rangeStd = StdMultiset.equal_range(3);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto equal_rangeMy = MyMultiset.EqualRange(3);
  auto equal_rangeStd = StdMultiset.equal_range(3);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_ANY_THROW(*equal_rangeMy.second);
}

TEST(Multiset, EqualRange3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto equal_rangeMy = MyMultiset.EqualRange(3);
  auto equal_rangeStd = StdMultiset.equal_range(3);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto equal_rangeMy = MyMultiset.EqualRange(-1.12);
  auto equal_rangeStd = StdMultiset.equal_range(-1.12);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto equal_rangeMy = MyMultiset.EqualRange(-0.1);
  auto equal_rangeStd = StdMultiset.equal_range(-0.1);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_ANY_THROW(*equal_rangeMy.second);
}

TEST(Multiset, EqualRange6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto equal_rangeMy = MyMultiset.EqualRange(1.001);
  auto equal_rangeStd = StdMultiset.equal_range(1.001);

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto equal_rangeMy = MyMultiset.EqualRange("sergei");
  auto equal_rangeStd = StdMultiset.equal_range("sergei");

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto equal_rangeMy = MyMultiset.EqualRange("ser");
  // auto equal_rangeStd = StdMultiset.equal_range("ser");

  // Assert
  EXPECT_ANY_THROW(*equal_rangeMy.first);
  EXPECT_ANY_THROW(*equal_rangeMy.second);
}

TEST(Multiset, EqualRange9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto equal_rangeMy = MyMultiset.EqualRange("is");
  auto equal_rangeStd = StdMultiset.equal_range("is");

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto equal_rangeMy = MyMultiset.EqualRange('*');
  auto equal_rangeStd = StdMultiset.equal_range('*');

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_ANY_THROW(*equal_rangeMy.second);
}

TEST(Multiset, EqualRange11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto equal_rangeMy = MyMultiset.EqualRange(' ');
  auto equal_rangeStd = StdMultiset.equal_range(' ');

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto equal_rangeMy = MyMultiset.EqualRange('!');
  auto equal_rangeStd = StdMultiset.equal_range('!');

  // Assert
  EXPECT_EQ(*equal_rangeMy.first, *equal_rangeStd.first);
  EXPECT_EQ(*equal_rangeMy.second, *equal_rangeStd.second);
}

TEST(Multiset, EqualRange13) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto equal_rangeMy = MyMultiset.EqualRange('s');
  // auto equal_rangeStd = StdMultiset.equal_range('s');

  // Assert
  EXPECT_ANY_THROW(*equal_rangeMy.first);
  EXPECT_ANY_THROW(*equal_rangeMy.second);
}

TEST(Multiset, EraseHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, Erase1) {
  // Arrange
  s21::Multiset<int> MyMultiset{2, 3, 4, 1, 2, 3, 4};
  std::multiset<int> StdMultiset{2, 3, 4, 1, 2, 3, 4};

  // Act
  auto itMy = MyMultiset.Begin();
  MyMultiset.Erase(itMy);
  auto itStd = StdMultiset.begin();
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itM != MyMultiset.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase2) {
  // Arrange
  s21::Multiset<int> MyMultiset{10, 3, 4, 3, 8, 0, 11};
  std::multiset<int> StdMultiset{10, 3, 4, 3, 8, 0, 11};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itS != StdMultiset.end(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase3) {
  // Arrange
  s21::Multiset<double> MyMultiset{10.11, 3.12, 4.13, 4.13,
                                   4.12,  8.14, 0.15, 11.16};
  std::multiset<double> StdMultiset{10.11, 3.12, 4.13, 4.13,
                                    4.12,  8.14, 0.15, 11.16};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  ++itMy;
  ++itMy;
  ++itStd;
  ++itStd;
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itS != StdMultiset.end(); ++itM, ++itS) {
    EXPECT_DOUBLE_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase4) {
  // Arrange
  s21::Multiset<char> MyMultiset{'a', '3', '(', 'a', '3',
                                 '4', 'i', '!', '*', '('};
  std::multiset<char> StdMultiset{'a', '3', '(', 'a', '3',
                                  '4', 'i', '!', '*', '('};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  itMy--;
  ++itStd;
  ++itStd;
  ++itStd;
  itStd--;
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itS != StdMultiset.end(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase5) {
  // Arrange
  s21::Multiset<char> MyMultiset{'1', '2', '3', '1', '2', '3', '4', '9'};
  std::multiset<char> StdMultiset{'1', '2', '3', '1', '2', '3', '4', '9'};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  ++itMy;
  ++itMy;
  ++itMy;
  --itMy;
  ++itStd;
  ++itStd;
  ++itStd;
  --itStd;
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itM != MyMultiset.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase6) {
  // Arrange
  s21::Multiset<char> MyMultiset{'u', '%', '8', '2', ','};
  std::multiset<char> StdMultiset{'u', '%', '8', '2', ','};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  ++itMy;
  ++itMy;
  itMy--;
  ++itStd;
  ++itStd;
  itStd--;
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itM != MyMultiset.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase7) {
  // Arrange
  s21::Multiset<double> MyMultiset{4.432, 1.234, 1.324, 0.43, 88.123};
  std::multiset<double> StdMultiset{4.432, 1.234, 1.324, 0.43, 88.123};

  // Act
  auto itMy = MyMultiset.Begin();
  auto itStd = StdMultiset.begin();
  MyMultiset.Erase(itMy);
  StdMultiset.erase(itStd);

  auto itMy2 = MyMultiset.Begin();
  auto itStd2 = StdMultiset.begin();
  MyMultiset.Erase(itMy2);
  StdMultiset.erase(itStd2);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itM != MyMultiset.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, Erase8) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 85, 9, 12, 11, 10};
  std::multiset<int> StdMultiset{3, 85, 9, 12, 11, 10};

  // Act
  auto itMy = MyMultiset.Begin();
  MyMultiset.Erase(itMy);
  auto itStd = StdMultiset.begin();
  StdMultiset.erase(itStd);
  auto itM = MyMultiset.Begin();
  auto itS = StdMultiset.begin();

  // Assert
  for (; itM != MyMultiset.End(); ++itM, ++itS) {
    EXPECT_EQ(*itM, *itS);
  }
  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
}

TEST(Multiset, InsertHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, Insert1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itMy1 != MyMultiset.End(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itMy1 != MyMultiset.End(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itMy1 != MyMultiset.End(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itMy1 != MyMultiset.End(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, Insert12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto itMy1 = MyMultiset.Begin();
  auto itStd1 = StdMultiset.begin();

  // Assert
  for (; itStd1 != StdMultiset.end(); ++itMy1, ++itStd1)
    EXPECT_EQ(*itMy1, *itStd1);

  EXPECT_EQ(MyMultiset.Size(), StdMultiset.size());
  //  EXPECT_EQ(MyMultiset.MaxSize(), StdMultiset.max_size());
  EXPECT_EQ(MyMultiset.Empty(), StdMultiset.empty());
}

TEST(Multiset, LowerBoundHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, LowerBound1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto lower_boundMy = MyMultiset.LowerBound(3);
  auto lower_boundStd = StdMultiset.lower_bound(3);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto lower_boundMy = MyMultiset.LowerBound(3);
  auto lower_boundStd = StdMultiset.lower_bound(3);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto lower_boundMy = MyMultiset.LowerBound(3);
  auto lower_boundStd = StdMultiset.lower_bound(3);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto lower_boundMy = MyMultiset.LowerBound(-1.12);
  auto lower_boundStd = StdMultiset.lower_bound(-1.12);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto lower_boundMy = MyMultiset.LowerBound(-0.1);
  auto lower_boundStd = StdMultiset.lower_bound(-0.1);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto lower_boundMy = MyMultiset.LowerBound(1.001);
  auto lower_boundStd = StdMultiset.lower_bound(1.001);

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto lower_boundMy = MyMultiset.LowerBound("sergei");
  auto lower_boundStd = StdMultiset.lower_bound("sergei");

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto lower_boundMy = MyMultiset.LowerBound("ser");
  // auto lower_boundStd = StdMultiset.lower_bound("ser");

  // Assert
  EXPECT_ANY_THROW(*lower_boundMy);
}

TEST(Multiset, LowerBound9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto lower_boundMy = MyMultiset.LowerBound("is");
  auto lower_boundStd = StdMultiset.lower_bound("is");

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto lower_boundMy = MyMultiset.LowerBound('*');
  auto lower_boundStd = StdMultiset.lower_bound('*');

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto lower_boundMy = MyMultiset.LowerBound(' ');
  auto lower_boundStd = StdMultiset.lower_bound(' ');

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto lower_boundMy = MyMultiset.LowerBound('!');
  auto lower_boundStd = StdMultiset.lower_bound('!');

  // Assert
  EXPECT_EQ(*lower_boundMy, *lower_boundStd);
}

TEST(Multiset, LowerBound13) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto lower_boundMy = MyMultiset.LowerBound('s');
  // auto lower_boundStd = StdMultiset.lower_bound('s');

  // Assert
  EXPECT_ANY_THROW(*lower_boundMy);
}

TEST(Multiset, UpperBoundHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, UpperBound1) {
  // Arrange
  s21::Multiset<int> MyMultiset{1, 2, 3, 4};
  std::multiset<int> StdMultiset{1, 2, 3, 4};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto upper_boundMy = MyMultiset.UpperBound(3);
  auto upper_boundStd = StdMultiset.upper_bound(3);

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound2) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  std::multiset<int> StdMultiset;

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto upper_boundMy = MyMultiset.UpperBound(3);
  // auto upper_boundStd = StdMultiset.upper_bound(3);

  // Assert
  EXPECT_ANY_THROW(*upper_boundMy);
}

TEST(Multiset, UpperBound3) {
  // Arrange
  s21::Multiset<int> MyMultiset{3, 3, 1, 4, 99, -1};
  std::multiset<int> StdMultiset{3, 3, 1, 4, 99, -1};

  // Act
  MyMultiset.Insert(3);
  StdMultiset.insert(3);
  auto upper_boundMy = MyMultiset.UpperBound(3);
  auto upper_boundStd = StdMultiset.upper_bound(3);

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound4) {
  // Arrange
  s21::Multiset<double> MyMultiset{-1.09, -1.08, -1.12, -1.12};
  std::multiset<double> StdMultiset{-1.09, -1.08, -1.12, -1.12};

  // Act
  MyMultiset.Insert(-1.09);
  StdMultiset.insert(-1.09);
  auto upper_boundMy = MyMultiset.UpperBound(-1.12);
  auto upper_boundStd = StdMultiset.upper_bound(-1.12);

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound5) {
  // Arrange
  s21::Multiset<double> MyMultiset;
  std::multiset<double> StdMultiset;

  // Act
  MyMultiset.Insert(-0.1);
  MyMultiset.Insert(-0.1);
  StdMultiset.insert(-0.1);
  StdMultiset.insert(-0.1);
  auto upper_boundMy = MyMultiset.UpperBound(-0.1);
  // auto upper_boundStd = StdMultiset.upper_bound(-0.1);

  // Assert
  EXPECT_ANY_THROW(*upper_boundMy);
}

TEST(Multiset, UpperBound6) {
  // Arrange
  s21::Multiset<double> MyMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};
  std::multiset<double> StdMultiset{3.013, 3.012, 1.001, 4.001, 99.32, -1.09};

  // Act
  MyMultiset.Insert(3.013);
  StdMultiset.insert(3.013);
  auto upper_boundMy = MyMultiset.UpperBound(1.001);
  auto upper_boundStd = StdMultiset.upper_bound(1.001);

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound7) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"sergei", "ravil", "ruslan", "timur"};
  std::multiset<std::string> StdMultiset{"sergei", "ravil", "ruslan", "timur"};

  // Act
  MyMultiset.Insert("sergei");
  StdMultiset.insert("sergei");
  auto upper_boundMy = MyMultiset.UpperBound("sergei");
  auto upper_boundStd = StdMultiset.upper_bound("sergei");

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound8) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;
  std::multiset<std::string> StdMultiset;

  // Act
  MyMultiset.Insert("s21school");
  MyMultiset.Insert("s21school");
  StdMultiset.insert("s21school");
  StdMultiset.insert("s21school");
  auto upper_boundMy = MyMultiset.UpperBound("ser");
  // auto upper_boundStd = StdMultiset.upper_bound("ser");

  // Assert
  EXPECT_ANY_THROW(*upper_boundMy);
}

TEST(Multiset, UpperBound9) {
  // Arrange
  s21::Multiset<std::string> MyMultiset{"My", "name", "is", "Sergei!"};
  std::multiset<std::string> StdMultiset{"My", "name", "is", "Sergei!"};

  // Act
  MyMultiset.Insert("My");
  MyMultiset.Insert("name");
  MyMultiset.Insert("is");
  MyMultiset.Insert("Sergei!");
  StdMultiset.insert("My");
  StdMultiset.insert("name");
  StdMultiset.insert("is");
  StdMultiset.insert("Sergei!");
  auto upper_boundMy = MyMultiset.UpperBound("is");
  auto upper_boundStd = StdMultiset.upper_bound("is");

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound10) {
  // Arrange
  s21::Multiset<char> MyMultiset{'*', '*', '(', '(', ')', ')'};
  std::multiset<char> StdMultiset{'*', '*', '(', '(', ')', ')'};

  // Act
  MyMultiset.Insert('*');
  StdMultiset.insert('*');
  auto upper_boundMy = MyMultiset.UpperBound('*');
  // auto upper_boundStd = StdMultiset.upper_bound('*');

  // Assert
  EXPECT_ANY_THROW(*upper_boundMy);
}

TEST(Multiset, UpperBound11) {
  // Arrange
  s21::Multiset<char> MyMultiset;
  std::multiset<char> StdMultiset;

  // Act
  MyMultiset.Insert('@');
  MyMultiset.Insert('@');
  StdMultiset.insert('@');
  StdMultiset.insert('@');
  auto upper_boundMy = MyMultiset.UpperBound(' ');
  auto upper_boundStd = StdMultiset.upper_bound(' ');

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound12) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto upper_boundMy = MyMultiset.UpperBound('!');
  auto upper_boundStd = StdMultiset.upper_bound('!');

  // Assert
  EXPECT_EQ(*upper_boundMy, *upper_boundStd);
}

TEST(Multiset, UpperBound13) {
  // Arrange
  s21::Multiset<char> MyMultiset{'!', '1', '2', '3', '4', '4'};
  std::multiset<char> StdMultiset{'!', '1', '2', '3', '4', '4'};

  // Act
  MyMultiset.Insert('!');
  MyMultiset.Insert('1');
  MyMultiset.Insert('2');
  MyMultiset.Insert('3');
  StdMultiset.insert('!');
  StdMultiset.insert('1');
  StdMultiset.insert('2');
  StdMultiset.insert('3');
  auto upper_boundMy = MyMultiset.UpperBound('s');
  // auto upper_boundStd = StdMultiset.upper_bound('s');

  // Assert
  EXPECT_ANY_THROW(*upper_boundMy);
}

TEST(Multiset, InsertManyHead) { std::cout << "\n------------------\n"; }

TEST(Multiset, InsertMany1) {
  // Arrange
  s21::Multiset<int> MyMultiset;
  size_t j = 1;

  // Act
  MyMultiset.InsertMany(1, 2, 3, 4, 5);
  auto it = MyMultiset.Begin();

  // Assert
  for (size_t i = 0; i != MyMultiset.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Multiset, InsertMany2) {
  // Arrange
  s21::Multiset<int> MyMultiset{-4, -3, -2, -1, 0};
  size_t j = -4;

  // Act
  MyMultiset.InsertMany(1, 2, 3, 4, 5);
  auto it = MyMultiset.Begin();

  // Assert
  for (size_t i = 0; i != MyMultiset.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Multiset, InsertMany3) {
  // Arrange
  s21::Multiset<int> MyMultiset{-4, -3, -2, -1, 0};
  int j = -4;

  // Act
  MyMultiset.InsertMany(1, 2, 3, 4, 5);
  auto it = MyMultiset.Begin();

  // Assert
  for (size_t i = 0; i != MyMultiset.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Multiset, InsertMany4) {
  // Arrange
  s21::Multiset<int> MyMultiset{4, 3, 2, 1};
  int j = -4;

  // Act
  MyMultiset.InsertMany(0, -1, -2, -3, -4);
  auto it = MyMultiset.Begin();

  // Assert
  for (size_t i = 0; i != MyMultiset.Size(); ++i, ++it) EXPECT_EQ(*it, j++);
}

TEST(Multiset, InsertMany5) {
  // Arrange
  s21::Multiset<char> MyMultiset{'0', '8', '9', '4', '3'};
  char ch = '0';

  // Act
  MyMultiset.InsertMany('1', '5', '6', '2', '7');
  auto it = MyMultiset.Begin();

  // Assert
  for (size_t i = 0; i != MyMultiset.Size(); ++i, ++it) EXPECT_EQ(*it, ch++);
}

TEST(Multiset, InsertMany6) {
  // Arrange
  s21::Multiset<std::string> MyMultiset;

  // Act
  MyMultiset.InsertMany("suzyheim", "abc", "bcd");
  auto it = MyMultiset.Contains("suzyheim");
  auto it2 = MyMultiset.Contains("abc");
  auto it3 = MyMultiset.Contains("bcd");

  // Assert
  EXPECT_EQ(it, true);
  EXPECT_EQ(it2, true);
  EXPECT_EQ(it3, true);
}
