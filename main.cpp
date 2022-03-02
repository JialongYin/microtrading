#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
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
