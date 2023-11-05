#include <iostream>
#include "BigReal.h"
using namespace std;

int main()
{
    string s1,s2;
    cout << "Enter Number one: "<< endl;
    cin >> s1;
    cout << "Enter Number two: "<< endl;
    cin >> s2;

    BigReal num1 = s1,num2 = s2;

    cout << "Number 1 " << num1 << endl;
    cout << "Number 2 " << num2 << endl;

    if(num1 > num2)
    {
        cout << "Number 1 Is > Number 2" << endl;
    }
    if(num1 < num2)
    {
        cout << "Number 1 Is < Number 2" << endl;
    }

    if ( num1 == num2){
        cout << "Number 1 Is = Number 2" << endl;
    }

    return 0;
}