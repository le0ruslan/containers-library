CC = g++
COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 $(COVFLAGS)
LDLIBS = -lgtest -L. -pthread
PREF_TEST = ./tests/
TESTS = $(wildcard $(PREF_TEST)*.cc)
REPORT_DIR = report


OS= $(shell uname -s)

ifeq ($(OS), Darwin)
	OPEN_CMD = open
else
	OPEN_CMD = xdg-open
endif


all: clean test

test:
	$(CC) $(TESTS) $(CFLAGS) $(LDLIBS) -L. -o s21_tests $^
	./s21_tests


gcov_report: clean test
	lcov -o s21_test.info -c -d . --ignore-errors inconsistent
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html


valgrind: test
	valgrind -s --leak-check=full --show-leak-kinds=all ./s21_tests

clang:
	cppcheck *.h *.cc --language=c++
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.h
	clang-format -i $(PREF_TEST)*.h
	clang-format -i $(PREF_TEST)*.cc
	clang-format -n *.h
	clang-format -n $(PREF_TEST)*.h
	clang-format -n $(PREF_TEST)*.cc
	rm -rf .clang-format

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info *.out s21_tests $(REPORT_DIR)
