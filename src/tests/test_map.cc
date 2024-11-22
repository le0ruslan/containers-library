#include <map>

#include "tests.h"

TEST(Map, Default) {
  s21::Map<int, char> my_empty_map;
  std::map<int, char> orig_empty_map;
  EXPECT_EQ(my_empty_map.Empty(), orig_empty_map.empty());
}

TEST(Map, With_Elements) {
  s21::Map<int, char> my_map = {{14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}};
  std::map<int, char> orig_map = {{14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}};
  EXPECT_EQ(my_map.Size(), orig_map.size());
  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(Map, Empty) {
  s21::Map<int, char> my_map = {};
  std::map<int, char> orig_map = {};
  EXPECT_EQ(my_map.Size(), orig_map.size());
  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(Map, Copy) {
  s21::Map<int, int> my_map = {{14, 2}, {1, 9}, {9, 2}};
  std::map<int, int> orig_map = {{14, 2}, {1, 9}, {9, 2}};
  s21::Map<int, int> my_map_copy = my_map;
  std::map<int, int> orig_map_copy = orig_map;
  EXPECT_EQ(my_map_copy.Size(), orig_map_copy.size());
  auto my_it = my_map_copy.Begin();
  auto orig_it = orig_map_copy.begin();
  for (; my_it != my_map_copy.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(Map, Move) {
  s21::Map<int, int> my_map = {{14, 2}, {1, 9}, {9, 2}};
  std::map<int, int> orig_map = {{14, 2}, {1, 9}, {9, 2}};
  s21::Map<int, int> my_map_copy = std::move(my_map);
  std::map<int, int> orig_map_copy = std::move(orig_map);
  EXPECT_EQ(my_map.Size(), orig_map.size());
  EXPECT_EQ(my_map_copy.Size(), orig_map_copy.size());
  auto my_it = my_map_copy.Begin();
  auto orig_it = orig_map_copy.begin();
  for (; my_it != my_map_copy.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(Map, Operator_) {
  s21::Map<char, std::string> my_map = {
      {'r', "Ruslan"}, {'s', "Serega"}, {'r', "Ravil"}};
  std::map<char, std::string> orig_map = {
      {'r', "Ruslan"}, {'s', "Serega"}, {'r', "Ravil"}};
  my_map['r'] = "Ruslan";
  orig_map['r'] = "Ruslan";
  orig_map['s'] = "Timur";
  EXPECT_TRUE(my_map['r'] == orig_map['r']);
  EXPECT_FALSE(my_map['s'] == orig_map['s']);
  EXPECT_TRUE(my_map['r'] == orig_map['r']);
}

TEST(Map, At_Operator) {
  s21::Map<char, std::string> my_map = {
      {'r', "Ruslan"}, {'s', "Serega"}, {'r', "Ravil"}};
  std::map<char, std::string> orig_map = {
      {'r', "Ruslan"}, {'s', "Serega"}, {'r', "Ravil"}};
  my_map.At('r') = "Ruslan";
  orig_map.at('r') = "Ruslan";
  orig_map.at('s') = "Timur";
  EXPECT_TRUE(my_map['r'] == orig_map['r']);
  EXPECT_FALSE(my_map['s'] == orig_map['s']);
  EXPECT_TRUE(my_map['r'] == orig_map['r']);
}

TEST(Map, Capacity) {
  s21::Map<char, std::string> my_map;
  std::map<char, std::string> orig_map;
  EXPECT_TRUE(my_map.Empty() == orig_map.empty());
  my_map.Insert('r', "Ruslan");
  EXPECT_FALSE(my_map.Empty() == orig_map.empty());
  EXPECT_EQ(my_map.Size(), 1);
}

TEST(Map, Clear) {
  s21::Map<int, int> my_map;
  std::map<int, int> orig_map;
  my_map.Clear();
  orig_map.clear();
  EXPECT_EQ(my_map.Empty(), orig_map.empty());
  my_map.Insert(std::make_pair<int, int>(14, 2));
  orig_map.insert(std::make_pair(14, 2));
  EXPECT_EQ(my_map.Empty(), orig_map.empty());
  my_map.Clear();
  orig_map.clear();
  EXPECT_EQ(my_map.Empty(), orig_map.empty());
}

TEST(Map, Insert_With_Pair) {
  s21::Map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.Insert(std::make_pair(14, 'r'));
  my_map.Insert(std::make_pair(2, 'r'));
  my_map.Insert(std::make_pair(1992, 'r'));
  orig_map.insert(std::make_pair(14, 'r'));
  orig_map.insert(std::make_pair(2, 'r'));
  orig_map.insert(std::make_pair(1992, 'r'));

  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.Insert(std::make_pair(14, 'r'));
  auto pr2 = orig_map.insert(std::make_pair(14, 'r'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(Map, Insert_Without_Pair) {
  s21::Map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.Insert(14, 'r');
  my_map.Insert(2, 'r');
  my_map.Insert(1992, 'r');
  orig_map.insert(std::make_pair(14, 'r'));
  orig_map.insert(std::make_pair(2, 'r'));
  orig_map.insert(std::make_pair(1992, 'r'));

  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.Insert(14, 'r');
  auto pr2 = orig_map.insert(std::make_pair(14, 'r'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(Map, InsertOrAssign) {
  s21::Map<int, char> my_map;
  std::map<int, char> orig_map;
  my_map.Insert(1, 'a');
  my_map.Insert(2, 'a');
  my_map.Insert(1992, 'a');
  orig_map.insert(std::make_pair(1, 'a'));
  orig_map.insert(std::make_pair(2, 'a'));
  orig_map.insert(std::make_pair(1992, 'a'));

  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }

  auto pr1 = my_map.InsertOrAssign(1, 'b');
  auto i = orig_map.begin();
  EXPECT_TRUE((*pr1.first).first == (*i).first);
  EXPECT_FALSE((*pr1.first).second == (*i).second);
}

TEST(Map, Erase) {
  s21::Map<int, char> my_map = {{14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}};
  std::map<int, char> orig_map = {{14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}};
  EXPECT_EQ(my_map.Size(), orig_map.size());
  my_map.Erase(my_map.Begin());
  orig_map.erase(orig_map.begin());
  EXPECT_EQ(my_map.Size(), orig_map.size());
  auto my_it = my_map.Begin();
  auto orig_it = orig_map.begin();
  for (; my_it != my_map.End(); ++my_it, ++orig_it) {
    EXPECT_TRUE((*my_it).first == (*orig_it).first);
    EXPECT_TRUE((*my_it).second == (*orig_it).second);
  }
}

TEST(Map, Swap) {
  s21::Map<int, int> my_map = {{1, 1}};
  s21::Map<int, int> my_swap_map = {{3, 3}, {4, 4}};

  my_map.Swap(my_swap_map);
  EXPECT_EQ(my_map.Size(), 2);
  EXPECT_EQ(my_swap_map.Size(), 1);
  auto x = (*(my_map.Begin())).first;
  auto y = (*(my_swap_map.Begin())).first;
  EXPECT_EQ(x, 3);
  EXPECT_EQ(y, 1);
}

TEST(Map, Merge) {
  s21::Map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};
  s21::Map<int, std::string> other_map = {{4, "four"}, {5, "five"}, {6, "six"}};

  my_map.Merge(other_map);

  EXPECT_TRUE(my_map.Size() == 6);
  EXPECT_TRUE(my_map.Contains(1) == 1);
  EXPECT_TRUE(my_map.Contains(2) == 1);
  EXPECT_TRUE(my_map.Contains(3) == 1);
  EXPECT_TRUE(my_map.Contains(4) == 1);
  EXPECT_TRUE(my_map.Contains(5) == 1);
  EXPECT_TRUE(my_map.Contains(6) == 1);
}

TEST(Map, Insert_Many) {
  s21::Map<int, int> my_map{{3, 1}, {2, 2}, {1, 3}};
  my_map.InsertMany(std::make_pair<int, int>(4, -1),
                    std::make_pair<int, int>(-1, 4));
  EXPECT_EQ(my_map.Contains(-1), true);
  EXPECT_EQ(my_map.Contains(4), true);
}
