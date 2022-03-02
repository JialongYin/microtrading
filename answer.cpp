#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Diff {

    Diff() = default;
    Diff(string type): type_(type) {
    }
    template <class T>
    string compare(T a, T b) {
        return to_string(a - b);
    }
    string compare(string a, string b) {
        return (a == b) ? "T" : "N";
    }

    enum type_code {
        Int,
        Float,
        Double,
        String
    };
    type_code hashit (string const & inString) {
        if (inString == "Int") return Int;
        if (inString == "Float") return Float;
        if (inString == "Double") return Int;
        if (inString == "Str") return String;
    }

    string operator()(string a, string b) {
        switch (this->hashit(type_)) {
            case Int:
                return compare(stoi(a), stoi(b));
                break;
            case Float:
                return compare(stof(a), stof(b);
                break;
            case Double:
                return compare(stod(a), stod(b));
                break;
            case String:
                return compare(a, b);
                break;
        }
    }
    string type_;
};


class File {
  public:
    File(string filename): filept_(filename) {
        getline(filept_, type_);
        int pos = type_.find('_'));
        compare_ = Diff(type_.substr(0, pos));
    }
    void diff(File &file, const string &fileOutput) {
        ofstream out(fileOutput);
        string line, line_;
        while (!filept_.eof()) {
            getline(filept_, line_);
            getline(file.filept_, line);
            out << compare_(line_, line) << endl;
        }
        this->setTobegin();
        file.setTobegin();
    }

  private:
    void setTobegin() {
        filept_.seekg (0, filept_.beg);
        getline(filept_, type_);
    }

    fstream filept_;
    string type_;
    Diff compare_;
};

int main(int argc, char** argv) {
  string fileInputA = argv[1], fileInputB = argv[2], fileOutput = argv[3];
  File fileA = File(fileInputA);
  File fileB = File(fileInputB);
  fileA.diff(fileB, fileOutput);
  fileB.diff(fileA, fileOutput);
  return 0;
}
