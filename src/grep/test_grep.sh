#!/bin/bash

run_diff() {
    echo "Сравнение с помощью: $1"
    result=$(eval "$1")

    if [ -z "$result" ]; then
        echo "Все хорошо."
    else
        echo "Есть проблемы:"
        echo "$result"
    fi
    echo "-------------------------------"
}

run_diff "diff <(./s21_grep asd grep.txt) <(grep asd grep.txt)"
run_diff "diff <(./s21_grep -e asd grep.txt) <(grep -e asd grep.txt)"
run_diff "diff <(./s21_grep -i asd grep.txt) <(grep -i asd grep.txt)"
run_diff "diff <(./s21_grep -v asd grep.txt) <(grep -v asd grep.txt)"
run_diff "diff <(./s21_grep -c asd grep.txt) <(grep -c asd grep.txt)"
run_diff "diff <(./s21_grep -l asd grep.txt) <(grep -l asd grep.txt)"
run_diff "diff <(./s21_grep -n asd grep.txt) <(grep -n asd grep.txt)"
run_diff "diff <(./s21_grep -h asd grep.txt) <(grep -h asd grep.txt)"
run_diff "diff <(./s21_grep -s asd grep.xt) <(grep -s asd grep.xt)"
run_diff "diff <(./s21_grep -n "[1-5]" grep.txt) <(grep -n "[1-5]" grep.txt)"
run_diff "diff <(./s21_grep asd grep.txt grep_2.txt) <(grep asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -e asd grep.txt grep_2.txt) <(grep -e asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -i asd grep.txt grep_2.txt) <(grep -i asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -v asd grep.txt grep_2.txt) <(grep -v asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -c asd grep.txt grep_2.txt) <(grep -c asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -l asd grep.txt grep_2.txt) <(grep -l asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -n asd grep.txt grep_2.txt) <(grep -n asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -h asd grep.txt grep_2.txt) <(grep -h asd grep.txt grep_2.txt)"
run_diff "diff <(./s21_grep -s asd grep.txt rep_2.txt) <(grep -s asd grep.txt rep_2.txt)"
run_diff "diff <(./s21_grep -d asd grep.txt rep_2.txt) <(grep -d asd grep.txt rep_2.txt)"