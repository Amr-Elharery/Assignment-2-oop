#include <iostream>
#include "BigReal.h"
using namespace std;

int main()
{
    string s,s2;
    cin >> s>>s2;
    BigReal b(s),c(s2);

    if(b > c)
    {
        cout << "B Is > C" << endl;
    }
    if(b < c)
    {
        cout << "B Is < C" << endl;
    }

    return 0;
}