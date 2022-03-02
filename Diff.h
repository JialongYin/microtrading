#include <string.h>
using namespace std;

class Diff {
  public:
    Diff() = default;
    Diff(string type);
    string operator()(string a, string b);

  private:
    template <typename T> string compare(T a, T b);
    string compare(string a, string b);
    enum type_code {
        Int,
        Float,
        Double,
        String
    };
    type_code hashit (string const & inString);
    string type_;
};
