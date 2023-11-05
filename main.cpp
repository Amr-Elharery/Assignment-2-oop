#include <iostream>
#include "BigReal.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    BigReal b(s);

    b.print();
    return 0;
}