#!/bin/bash

run="false"

while test $# -gt 0; do
  case "$1" in
  -r)
    run="true"
    shift
    ;;
  *)
    file="${1%.*}"
    shift
    ;;
  esac
done

(set -o xtrace; gcc -o $file $file.c -Wall -ansi -pedantic)

if [ "$run" = "true" ]; then
  ./$file
fi




