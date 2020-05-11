#!/bin/bash
set -x
gcc -o $1 $1.c -Wall -ansi -pedantic
