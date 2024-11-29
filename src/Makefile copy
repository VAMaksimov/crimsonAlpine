CC = gcc -Wall -Wextra -Werror -g -fprofile-arcs -ftest-coverage
AR = ar
ARFLAGS = rcs
TARGET = s21_string.a
SRC = s21_string.c
OBJ = $(SRC:.c=.o)
TEST_SRC = test.c
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all clean test gcov_report rebuild valgrind

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) *.gcda *.gcno

rebuild: clean all

test: $(TARGET) $(TEST_OBJ)
	$(CC) -o test $(TEST_OBJ) -L. -ls21_string
	./test

gcov_report: CC += --gcov
gcov_report: test
	./test
	gcov -o . $(SRC) $(TEST_SRC)
	mkdir -p gcov_report
	mv *.gcov gcov_report/
	gcovr -r . --html --html-details -o gcov_report/report.html

valgrind: $(TARGET) $(TEST_OBJ)
	$(CC) -o test $(TEST_OBJ) -L. -ls21_string
	valgrind --leak-check=full ./test
