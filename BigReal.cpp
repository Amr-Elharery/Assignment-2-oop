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
        if (regex_match(num, regex("(\\+|-)\\d*\\.?\\d+")))
        {
            if (num[0] == '+')
            {
                num[0] = '0';
            }
            else if (num[0] == '-')
            {
                sign = '-';
                num[0] = '0';
            }
        }
        else
        {
            integer = "0";
            fraction = "0";
        }
        if (regex_match(num, regex("\\d*\\.?\\d+")))
        {
            integer = num.substr(0, num.find('.'));
            fraction = num.substr(num.find('.'));
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