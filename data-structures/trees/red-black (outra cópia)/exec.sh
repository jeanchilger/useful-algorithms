#!/bin/bash

gcc -c redBlack.c
gcc -c main.c
gcc -o run main.o redBlack.o
./run
rm -rf *.o
