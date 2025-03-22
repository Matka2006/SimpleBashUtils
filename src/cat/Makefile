C_FLags=-Wall -Werror -Wextra -std=c11

all: build 

build: s21_cat 

s21_cat: s21_cat.c
	gcc $(C_FLags) s21_cat.c -o s21_cat

clean:
	rm -rf s21_cat

rebuild: clean all