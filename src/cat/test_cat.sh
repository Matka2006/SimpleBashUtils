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

run_diff "diff <(./s21_cat ex.txt) <(cat ex.txt)"
run_diff "diff <(./s21_cat -b ex.txt) <(cat -b ex.txt)"
run_diff "diff <(./s21_cat -e ex.txt) <(cat -e ex.txt)"
run_diff "diff <(./s21_cat -n ex.txt) <(cat -n ex.txt)"
run_diff "diff <(./s21_cat -s ex.txt) <(cat -s ex.txt)"
run_diff "diff <(./s21_cat -t ex.txt) <(cat -t ex.txt)"
run_diff "diff <(./s21_cat -v ex.txt) <(cat -v ex.txt)"
run_diff "diff <(./s21_cat --number-nonblank ex.txt) <(cat -b ex.txt)"
run_diff "diff <(./s21_cat --number ex.txt) <(cat -n ex.txt)"
run_diff "diff <(./s21_cat --squeeze-blank ex.txt) <(cat -s ex.txt)"
run_diff "diff <(./s21_cat -v bytes.txt) <(cat -v bytes.txt)"
run_diff "diff <(./s21_cat -e bytes.txt) <(cat -e bytes.txt)"
run_diff "diff <(./s21_cat -t bytes.txt) <(cat -t bytes.txt)"
run_diff "diff <(./s21_cat -e cr.txt) <(cat -e cr.txt)"
run_diff "diff <(./s21_cat -t cr.txt) <(cat -t cr.txt)"
run_diff "diff <(./s21_cat -v cr.txt) <(cat -v cr.txt)"
run_diff "diff <(./s21_cat cr.txt ex.txt) <(cat cr.txt ex.txt)"
run_diff "diff <(./s21_cat -b cr.txt ex.txt) <(cat -b cr.txt ex.txt)"
run_diff "diff <(./s21_cat -e cr.txt ex.txt) <(cat -e cr.txt ex.txt)"
run_diff "diff <(./s21_cat -n cr.txt ex.txt) <(cat -n cr.txt ex.txt)"
run_diff "diff <(./s21_cat -s cr.txt ex.txt) <(cat -s cr.txt ex.txt)"
run_diff "diff <(./s21_cat -t cr.txt ex.txt) <(cat -t cr.txt ex.txt)"
run_diff "diff <(./s21_cat -v cr.txt ex.txt) <(cat -v cr.txt ex.txt)"
run_diff "diff <(./s21_cat --number-nonblank cr.txt ex.txt) <(cat -b cr.txt ex.txt)"
run_diff "diff <(./s21_cat --number cr.txt ex.txt) <(cat -n cr.txt ex.txt)"
run_diff "diff <(./s21_cat --squeeze-blank cr.txt ex.txt) <(cat -s cr.txt ex.txt)"
run_diff "diff <(./s21_cat -d ex.txt) <(cat -d ex.txt)"