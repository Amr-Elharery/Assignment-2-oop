#include "BigReal.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

string sum_two_string(const string& str1, const string& str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int arr1[100] = {0}, arr2[100] = {0}, arr[101] = {0};
    int maxLength = max(len1, len2);

    for (int i = 0; i < len1; i++) {
        arr1[i] = str1[len1 - 1 - i] - '0';
    }

    for (int i = 0; i < len2; i++) {
        arr2[i] = str2[len2 - 1 - i] - '0';
    }

    int carry = 0;
    for (int i = 0; i < maxLength; i++) {
        arr[i] = arr1[i] + arr2[i] + carry;
        carry = arr[i] / 10;
        arr[i] %= 10;
    }

    if (carry == 1) {
        arr[maxLength] = 1;
        maxLength++;
    }
    string sum = "";
    for (int i = maxLength - 1; i >= 0; i--) {
        sum += (arr[i] + '0');
    }

    return sum;
}

string subtract_two_string(const string& str1, const string& str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int arr1[100] = {0}, arr2[100] = {0}, arr[100] = {0};

    for (int i = 0; i < len1; i++) {
        arr1[i] = str1[len1 - 1 - i] - '0';
    }

    for (int i = 0; i < len2; i++) {
        arr2[i] = str2[len2 - 1 - i] - '0';
    }

    for (int i = 0; i < len1; i++) {
        if (arr1[i] < arr2[i]) {
            arr1[i] += 10;
            arr1[i + 1]--;
        }
        arr[i] = arr1[i] - arr2[i];
    }

    int maxLength = len1;
    while (maxLength > 1 && arr[maxLength - 1] == 0) {
        maxLength--;
    }

    string result = "";
    for (int i = maxLength - 1; i >= 0; i--) {
        result += (arr[i] + '0');
    }

    return result;
}


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

ostream& operator<<(ostream& out,BigReal& real){
    out<<real.sign<<real.integer<<'.'<<real.fraction;
    return out;
}

bool BigReal::operator > (BigReal& anotherReal) {
    if(integer>anotherReal.integer && sign == '+'){
        return true;
    }
    if(integer < anotherReal.integer && sign == '-' && anotherReal.sign == '-'){
        return true;
    }
    if(integer > anotherReal.integer && sign == '-' && anotherReal.sign == '+'){
        return false;
    }

    if(fraction>anotherReal.fraction && sign == '+'){
        return true;
    }
    if(fraction < anotherReal.fraction && sign == '-' && anotherReal.sign == '-'){
        return true;
    }
    if(fraction > anotherReal.fraction && sign == '-' && anotherReal.sign == '+'){
        return false;
    }
    return false;
}


bool BigReal::operator < (BigReal& anotherReal) {
    if(integer>anotherReal.integer && anotherReal.sign == '+'){
        return false;
    }
    if(integer < anotherReal.integer && sign == '-' && anotherReal.sign == '-'){
        return false;
    }
    if(integer > anotherReal.integer && sign == '+' && anotherReal.sign == '-'){
        return true;
    }

    if(fraction>anotherReal.fraction && anotherReal.sign == '+'){
        return false;
    }
    if(fraction < anotherReal.fraction && anotherReal.sign == '-' && sign == '-'){
        return false;
    }
    if(fraction > anotherReal.fraction && sign == '+' && anotherReal.sign == '-'){
        return true;
    }
    return false;
}

bool BigReal::operator==(BigReal &anotherReal) {
    if(sign == anotherReal.sign && integer == anotherReal.integer && fraction == anotherReal.fraction){
        return true;
    }
    return false;
}

BigReal operator+( BigReal& real1,  BigReal& real2) {
    BigReal result;

    if (real1.sign == real2.sign) {
        result.sign = real1.sign;
    }

    result.fraction = sum_two_string(real1.fraction, real2.fraction);
    result.integer = sum_two_string(real1.integer, real2.integer);

    int mini;
    if (real1 > real2) {
        mini = min(real1.fraction.size(), real2.fraction.size());
    } else {
        mini = max(real1.fraction.size(), real2.fraction.size());
    }
    if (real2.fraction.size() == mini) {
        return result;
    } else {
        result.integer = sum_two_string(result.integer, "1");
        result.fraction = result.fraction.substr(1, result.fraction.size() - 1);
        return result;
    }
}

BigReal operator-( BigReal& real1,  BigReal& real2) {
    BigReal result;

    if (real1.sign == real2.sign) {
        result.sign = real1.sign;

        result.integer = subtract_two_string(real1.integer, real2.integer);
        result.fraction = subtract_two_string(real1.fraction, real2.fraction);

        if (result.fraction[0] == '-') {
            result.integer = subtract_two_string(result.integer, "1");
            result.fraction.erase(0, 1);
        }
    } else {
        result.sign = real1.sign;  //  sign of  result is  sign of the first

        result.integer = subtract_two_string(real1.integer, real2.integer);
        result.fraction = subtract_two_string(real1.fraction, real2.fraction);
    }

    return result;
}
