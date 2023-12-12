#include <string>
#include<bits/stdc++.h>
using namespace std;

class BigReal {
private:
    char sign = '+';
    string integer, fraction;

public:
    BigReal();
    BigReal(string& num);

    bool operator > (BigReal& anotherReal);
    bool operator < (BigReal& anotherReal);
    bool operator == (BigReal& anotherReal);

    friend BigReal operator+( BigReal& real1,  BigReal& real2);
    friend BigReal operator-( BigReal& real1,  BigReal& real2);



    friend ostream& operator<<(ostream& out,BigReal& real);
};

