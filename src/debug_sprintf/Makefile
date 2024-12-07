EXEC = s21_sprintf
SRCS = $(wildcard *.c)
LDFLAGS_TEST = -g -fdiagnostics-color=always -lcheck -lm -lsubunit

all: debug

debug:
	gcc $(SRCS) -o $(EXEC) $(LDFLAGS_TEST)

clean:
	rm $(EXEC)
