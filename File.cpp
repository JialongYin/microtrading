#include "File.h"


File::File(std::string filename): filept_(filename), compare_(Diff()) {
    getline(filept_, type_);
    int pos = type_.find('_');
    compare_ = Diff(type_.substr(0, pos));
    // std::cout << type_ << std::endl;
}

void File::diff(File &file, const std::string &fileOutput) {
    std::ofstream out(fileOutput);
    std::string line_, line;
    // char line_[256], line[256];
    while (!filept_.eof()) {
        std::getline(filept_, line_);
        std::getline(file.filept_, line);
        // filept_.getline(line_, 256);
        // file.filept_.getline(line, 256);
        // std::cout << line << " " << typeid(line).name() << std::endl;
        out << compare_(line_, line) << std::endl;
        // out << compare_(std::string(line_), std::string(line)) << std::endl;

    }
    this->setTobegin();
    file.setTobegin();
}

void File::setTobegin() {
    filept_.seekg (0, filept_.beg);
    std::getline(filept_, type_);
}
