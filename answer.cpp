#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "File.h"
using namespace std;


int main(int argc, char** argv) {
  string fileInputA = argv[1], fileInputB = argv[2], fileOutput = argv[3];
  File fileA = File(fileInputA);
  File fileB = File(fileInputB);
  fileA.diff(fileB, fileOutput);
  fileB.diff(fileA, fileOutput);
  return 0;
}
