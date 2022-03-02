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

    type_code hashit (string const & inString) {
        if (inString == "Int") return Int;
        if (inString == "Float") return Float;
        if (inString == "Double") return Int;
        if (inString == "Str") return String;
    }

    string operator()(string a, string b) {
        switch (hashit(type_)) {
            case Int:
                int at = stoi(a), bt = stoi(b);
                return compare(at, bt);
                break;
            case Float:
                float at = stof(a), bt = stof(b);
                return compare(at, bt);
                break;
            case Double:
                double at = stod(a), bt = stod(b);
                return compare(at, bt);
                break;
            case String:
                return compare(a, b);
                break;
        }
    }
    string type_;
    enum type_code {
        Int,
        Float,
        Double,
        String
    };
};


class File {
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
