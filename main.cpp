#include <iostream>
#include "BigReal.h"
using namespace std;

int main()
{
    string s= "123.345";
    BigReal b(s);

    b.print();
    return 0;
}