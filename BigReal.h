#include <string>
using namespace std;

class BigReal {
private:
    char sign = '+';
    string integer, fraction;

public:
    BigReal();
    BigReal(string& num);

    void print();
};

