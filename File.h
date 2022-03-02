#include <fstream>
#include <string.h>

class File {
  public:
    File(string filename);
    void diff(File &file, const string &fileOutput);

  private:
    void setTobegin();
    fstream filept_;
    string type_;
    Diff compare_;
};