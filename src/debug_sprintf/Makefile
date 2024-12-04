EXEC = s21_sprintf
SRCS = $(wildcard *.c)
LDFLAGS_TEST = -lcheck -lm

all: debug

debug:
	gcc -g $(SRCS) -o $(EXEC) $(LDFLAGS_TEST)
	./$(EXEC)

clean:
	rm $(EXEC) *.gcno
