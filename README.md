# Project

This project is a software to compare two input files and produce an output file. Multiple data types are supported, including int, float, double, string. Date and other user-defined class can be supported by adding `string compare(typename a, typename b)` and editing related functions to preprocess the string input in `class Diff`. Multiple file sources can be supported, including txt, csv. The software can be extended to deal with Database if accessing API is given.

# Compilation

The code can be compiled with the provided makefile using the standard `make` command.
```
$ make
```

## Sample Execution

After compilation, run the program following the format as below. The program should take three parameters that represent the names of the two input files and the output file.
```
$ ./main data/InputA1.txt data/InputA2.txt data/OutputA.txt
$ ./main data/InputB1.csv data/InputB2.csv data/OutputB.csv
```
Check the output in related files.
