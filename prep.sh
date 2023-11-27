#!/bin/bash

clear

flex -o scanner.c scanner.l
bison -d parser.y

gcc -o compiler scanner.c parser.tab.c -lfl

./compiler.exe < testFile.txt