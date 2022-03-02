#include <fstream>
#include <string>
#include <iostream>
#include "Diff.h"

class File {
  public:
    File(std::string filename);
    void diff(File &file, const std::string &fileOutput);

  private:
    void setTobegin();
    std::fstream filept_;
    std::string type_;
    Diff compare_;
};
