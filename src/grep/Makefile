C_FLags = -Werror -Wall -Wextra -std=c11

all: build

build: s21_grep

s21_grep: s21_grep.c
	gcc $(C_FLags) s21_grep.c -o s21_grep

clean:
	rm -rf s21_grep

rebuild: clean all