CC = gcc -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -ftest-coverage -fprofile-arcs
AR = ar rcs
TARGET = s21_string.a
SRC = s21_string.c
OBJ = $(SRC:.c=.o)
TEST_SRC = test.c
TEST_OBJ = $(TEST_SRC:.c=.o)
SRC_DIR = components
BUILD_DIR = build

.PHONY: all clean test gcov_report rebuild valgrind

# SRCS = $(wildcard $(SRC_DIR)/*.c)
# TESTS = $(wildcard $(TEST_DIR)/*.c)
# OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# TEST_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_TEST_DIR)/%.o)
# TEST_FILES_OBJS = $(TESTS:$(TEST_DIR)/%.c=$(COMPILED_TESTS)/%.o)

# all: $(LIBRARY)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#     @mkdir -p $(OBJ_DIR)
#     $(CC) $(CFLAGS_LIB) -c $< -o $@
# $(OBJ_TEST_DIR)/%.o: $(SRC_DIR)/%.c
#     @mkdir -p $(OBJ_TEST_DIR)
#     $(CC) $(CFLAGS_TEST) -c $< -o $@
# $(COMPILED_TESTS)/%.o: $(TEST_DIR)/%.c
#     @mkdir -p $(COMPILED_TESTS)
#     $(CC) $(CFLAGS_TEST) -c $< -o $@
# $(TEST_EXEC): $(TEST_OBJS) $(TEST_FILES_OBJS)
#     $(CC) $(CFLAGS_TEST) -o $@ $^ $(LDFLAGS_TEST)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)    $(CC) $(CFLAGS_LIB) -c $< -o $@

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
