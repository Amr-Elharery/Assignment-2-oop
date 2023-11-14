#ifndef ASSIGNMENT_2_REGISTER_H
#define ASSIGNMENT_2_REGISTER_H
#include <bits/stdc++.h>

using namespace std;


class Register {
public:
    int address;
    string value = "00";
    friend ostream &operator << (ostream & out, Register & R);
};

ostream &operator << (ostream & out, Register & R) {
    out << R.value;
    return out;
}

#endif //ASSIGNMENT_2_REGISTER_H
