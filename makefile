# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o File.o Diff.o
    $(CC) $(CFLAGS) -o main main.o File.o Diff.o

# The main.o target can be written more simply

main.o: main.cpp File.h
    $(CC) $(CFLAGS) -c main.cpp

File.o: File.h Diff.h

Diff.o: Diff.h
