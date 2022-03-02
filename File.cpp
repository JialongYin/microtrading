#include "File.h"


File::File(string filename): filept_(filename), compare_(Diff()) {
    getline(filept_, type_);
    int pos = type_.find('_'));
    compare_ = Diff(type_.substr(0, pos));
}

void File::diff(File &file, const string &fileOutput) {
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

void File::setTobegin() {
    filept_.seekg (0, filept_.beg);
    getline(filept_, type_);
}
