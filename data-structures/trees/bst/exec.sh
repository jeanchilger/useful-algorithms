#!/bin/bash

gcc -c BinarySearchTree.c
gcc -c main.c
gcc -o run BinarySearchTree.o main.c
./run

rm -rf *.o

