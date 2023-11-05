#include "BigReal.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

BigReal::BigReal() : integer("0"), fraction("0") {}

BigReal::BigReal(string &num)
{
    if (!num.empty())
    {
        if (regex_match(num, regex("(\\+|-)\\d*\\.\\d+")))
        {
            if (num[0] == '+'&&!isdigit(num[0]))
            {
                num[0] = '0';
            }
            else if (num[0] == '-'&&isdigit(num[1]))
            {
                sign = '-';
            }
            else if(num[0] == '-'&&!isdigit(num[1])){
                sign = '-';
                num[0] ='0';
            }
            integer = num.substr(1, num.find('.')-1);
            fraction = num.substr(num.find('.')+1);
        }
        else if  (regex_match(num, regex("\\d*\\.\\d+")))
        {
            integer = num.substr(0, num.find('.'));
            fraction = num.substr(num.find('.')+1);
        }
        else
        {
            integer = "0";
            fraction = "0";
        }
    }
    else
    {
        integer = "0";
        fraction = "0";
    }
}

void BigReal::print()
{
    cout << sign << integer << '.' << fraction;
}