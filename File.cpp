#include "File.h"


File::File(std::string filename): filept_(filename), compare_(Diff()) {
    getline(filept_, type_);
    int pos = type_.find('_');
    compare_ = Diff(type_.substr(0, pos));
}

void File::diff(File &file, const std::string &fileOutput) {
    std::ofstream out(fileOutput);
    out << "Diff" << std::endl;
    std::string line_, line;
    while (true) {
        std::getline(filept_, line_);
        std::getline(file.filept_, line);
        if (filept_.eof() || file.filept_.eof()) break;
        out << compare_(line_, line) << std::endl;
    }
    this->setTobegin();
    file.setTobegin();
}

void File::setTobegin() {
    filept_.seekg (0, filept_.beg);
    std::getline(filept_, type_);
}
