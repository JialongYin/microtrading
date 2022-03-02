#include "Diff.h"


Diff::Diff(std::string type): type_(type) {
}

template <typename T>
std::string Diff::compare(T a, T b) {
    return to_string(a - b);
}

std::string Diff::compare(std::string a, std::string b) {
    return (a == b) ? "T" : "N";
}

Diff::type_code Diff::hashit (std::string const & inString) {
    if (inString == "Int") return Int;
    if (inString == "Float") return Float;
    if (inString == "Double") return Int;
    if (inString == "Str") return String;
}

std::string Diff::operator()(std::string a, std::string b) {
    switch (this->hashit(type_)) {
        case Int:
            return compare(stoi(a), stoi(b));
            break;
        case Float:
            return compare(stof(a), stof(b));
            break;
        case Double:
            return compare(stod(a), stod(b));
            break;
        case String:
            return compare(a, b);
            break;
    }
}
