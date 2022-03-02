#include <string.h>

class Diff {
  public:
    Diff() = default;
    Diff(std::string type);
    std::string operator()(std::string a, std::string b);

  private:
    template <typename T> std::string compare(T a, T b);
    std::string compare(std::string a, std::string b);
    enum type_code {
        Int,
        Float,
        Double,
        String
    };
    type_code hashit (std::string const & inString);
    std::string type_;
};
