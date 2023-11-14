#ifndef ASSIGNMENT_2_MEMORY_H
#define ASSIGNMENT_2_MEMORY_H

#include <bits/stdc++.h>

using namespace std;

class Memory {

public:
    int address;
    string value = "00";
    friend ostream &operator << (ostream &out, Memory M);
};

ostream &operator << (ostream & out, Memory M) {
    out << M.value;
    return out;
}

#endif //ASSIGNMENT_2_MEMORY_H
