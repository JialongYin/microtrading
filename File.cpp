#include "File.h"


File::File(std::string filename): filept_(filename), compare_(Diff()) {
    getline(filept_, type_);
    int pos = type_.find('_');
    compare_ = Diff(type_.substr(0, pos));
    // std::cout << type_ << std::endl;
}

void File::diff(File &file, const std::string &fileOutput) {
    std::ofstream out(fileOutput);
    std::string line, line_;
    while (!filept_.eof()) {
        std::getline(filept_, line_);
        std::getline(file.filept_, line);
        // std::cout << line << " " << typeid(line).name() << std::endl;
        out << compare_(std::to_string(line_), std::to_string(line)) << std::endl;
    }
    this->setTobegin();
    file.setTobegin();
}

void File::setTobegin() {
    filept_.seekg (0, filept_.beg);
    std::getline(filept_, type_);
}
