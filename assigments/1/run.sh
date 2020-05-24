#!/bin/bash

gcc -o reverse_words reverse_words.c -Wall -ansi -pedantic
chmod +x reverse_words

echo "Running tests..."
echo

check() {
  output=$(echo "$1" | ./reverse_words)
  if [ "$output" = "$2" ]; then
    echo "Pass: Expected '$2' and got: $output"
    return 0
  else
    echo "Expected '$2' but got: $output"
    return 1
  fi
}

TEST_INPUT_1="perfect makes practice"
TEST_OUTPUT_1="practice makes perfect"

if [ "$1" = "1" ]; then
  check "$TEST_INPUT_1" "$TEST_OUTPUT_1"
fi

TEST_INPUT_1="perfect makes practice"
TEST_OUTPUT_1="practice makes perfect"

if [ "$1" = "1" ]; then
  check "$TEST_INPUT_1" "$TEST_OUTPUT_1"
fi

rm reverse_words

if [ $? != 0 ]; then
  exit 1
fi

exit 0