#!/bin/bash

clear
gcc -c avl.c
gcc -c main.c
gcc -o run avl.o main.o
./run
rm -rf *.o
