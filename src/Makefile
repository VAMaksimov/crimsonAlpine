# main vars
AR = ar rcs
LIBRARY = s21_string.a

# flags
CC = gcc -Wall -Wextra -Werror -std=c11 -g
CFLAGS_TEST = -fprofile-arcs -ftest-coverage
LDFLAGS_TEST = -lcheck -lm  -lsubunit

# dirs
SRC_DIR = components
TEST_DIR = tests
BUILD_DIR = build
OBJ_TEST_DIR = obj_test
COMPILED_TESTS = compiled_tests

# compiled sources
SRCS = $(wildcard $(SRC_DIR)/*.c)
TESTS = $(wildcard $(TEST_DIR)/*.c)
# For each object file specified in OBJS, Make checks if there is a corresponding rule defined for building it.
# The pattern rule ($(BUILD_DIR)/%.o: $(SRC_DIR)/%.c) matches
# because both the target and prerequisite follow the same naming convention.
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TEST_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_TEST_DIR)/%.o)
TEST_FILES_OBJS = $(TESTS:$(TEST_DIR)/%.c=$(COMPILED_TESTS)/%.o)
TEST_EXEC = my_tests


# ---
# targets

.PHONY: all clean test gcov_report rebuild valgrind
all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) $@ $^

# The target $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c defines a pattern rule.
# The % character acts as a wildcard.
# This rule tells Make how to create an object file from its corresponding source file:
# When Make needs to build an object file (e.g., $(BUILD_DIR)/file1.o),
# it recognizes that it can use the source file $(SRC_DIR)/file1.c.

# With -c flag, the compiler will generate a .o file (object file) from a .c file (source file)
# but will not produce an executable.
# This is essential in multi-file projects
# where each source file compiles separately before linking them together later.

# Using $< is appropriate here because you only need to specify one source file for each compilation command
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) -c $< -o $@

$(OBJ_TEST_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_TEST_DIR)
	@$(CC) $(CFLAGS_TEST) -c $< -o $@

$(COMPILED_TESTS)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(COMPILED_TESTS)
	@$(CC) $(CFLAGS_TEST) -c $< -o $@

# test with library!!
$(TEST_EXEC): $(TEST_OBJS) $(TEST_FILES_OBJS)
	@$(CC) $(CFLAGS_TEST) $^ -o $@ $(LDFLAGS_TEST)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: test
	rm -rf $(OBJ_TEST_DIR)/test* $(OBJ_TEST_DIR)/sscanf_test*
	lcov --capture --directory $(OBJ_TEST_DIR) --output-file coverage.info
	genhtml coverage.info --output-directory html_report

clean:
	rm -rf $(BUILD_DIR) $(OBJ_TEST_DIR) $(LIBRARY) $(TEST_EXEC) $(COMPILED_TESTS) debug coverage.info  *.gcda *.gcno

rebuild: clean all

# write valgrind!!!
valgrind:
	valgrind --leak-check=full ./$(TEST_EXEC)

debug: $(TEST_OBJS) $(TEST_FILES_OBJS) 
	@$(CC) $(CFLAGS_TEST) $^ -o $@ $(LDFLAGS_TEST)

# ---
# old

# test: $(LIBRARY) $(TEST_OBJ)
# 	$(CC) -o test $(TEST_OBJ) -L. -ls21_string
# 	./test

# gcov_report: CC += --gcov
# gcov_report: test
# 	./test
# 	gcov -o . $(SRC) $(TEST_SRC)
# 	mkdir -p gcov_report
# 	mv *.gcov gcov_report/
# 	gcovr -r . --html --html-details -o gcov_report/report.html

# valgrind: $(LIBRARY) $(TEST_OBJ)
# 	$(CC) -o test $(TEST_OBJ) -L. -ls21_string
# 	valgrind --leak-check=full ./test
