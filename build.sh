#!/bin/bash

mkdir -p build/obj

gcc -c src/program.c -o build/obj/program.o
gcc -c src/board.c -o build/obj/board.o
gcc -c src/io/read.c -o build/obj/read.o

gcc \
    build/obj/program.o \
    build/obj/board.o \
    build/obj/read.o \
    -o build/tictactoe
