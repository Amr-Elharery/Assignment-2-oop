#ifndef ASSIGNMENT_2_OPERATION_H
#define ASSIGNMENT_2_OPERATION_H

#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
using namespace std;

class Operation {
public:


    int hex_to_int(string hex_string);
    string hex_to_bin(string hex_string);
    //Return a memory by receiving its address
    int get_memory_by_address(vector<Memory>& M,string address);
    //Return a register by receiving its access
    int get_register_by_address(vector<Register> &R, string address);

    //Load the register R with the bit pattern found in memory whose address is XY (1RXY)
    void One(vector<Memory>& M, vector<Register> &R, string reg_add, string mem_address);
    //Load the register R with the bit pattern XY (2RXY)
    void Two(vector<Register>&R,string add, string value);
    //Print the value in R to the scree
    void Three(vector<Memory>& M, vector<Register> &R, string reg_add, string mem_address);
    //Copy the bit pattern found in R to S
    void Four(vector<Register>&R, string add1, string add2);
    //Adding two binary numbers, if set to 1 we ignore the carry
    string add_binary(string one, string two, bool flag);
    //Convert 2's comp neg to pos
    string negative_to_positive(string neg);

    //Add the bits in S and in T and leave the result in R
    void Five(vector<Register> &R,string place_add,string add_1, string add_2 );
};

//Converting hex to integer
int Operation::hex_to_int(string hex_string) {
    int value = 0;
    int base = 1;
    for (int i = hex_string.length() - 1; i >= 0; i--) {
        char hex_digit = hex_string[i];
        int digit_value = 0;
        if (hex_digit >= '0' && hex_digit <= '9') {
            //Convert to int
            digit_value = hex_digit - '0';
        } else if (hex_digit >= 'A' && hex_digit <= 'F') {
            //Convert to int
            digit_value = hex_digit - 'A' + 10;
        } else {
            return -1; // Not a hexa digit
        }
        value += digit_value * base;
        base *= 16;
    }
    return value;
}
//**************************************
string Operation::hex_to_bin(string hex_string) {
    string binary_string = "";
    for (char hex_digit : hex_string) {
        switch (hex_digit) {
            case

                '0':
                binary_string += "0000";
                break;
            case

                '1':
                binary_string += "0001";
                break;
            case

                '2':
                binary_string += "0010";
                break;
            case

                '3':
                binary_string += "0011";
                break;
            case

                '4':
                binary_string += "0100";
                break;
            case

                '5':
                binary_string += "0101";
                break;
            case

                '6':
                binary_string += "0110";
                break;
            case

                '7':
                binary_string += "0111";
                break;
            case

                '8':
                binary_string += "1000";
                break;
            case

                '9':
                binary_string += "1001";
                break;
            case

                'A':
                binary_string += "1010";
                break;
            case 'B':
                binary_string += "1011";
                break;
            case 'C':
                binary_string += "1100";
                break;
            case 'D':
                binary_string += "1101";
                break;
            case 'E':
                binary_string += "1110";
                break;
            case 'F':
                binary_string += "1111";
                break;
            default:
                // Invalid hex digit
                return "";
        }
    }
    return binary_string;
}
//**************************************
int Operation::get_memory_by_address(vector<Memory> &M, string address) {

    int add = Operation::hex_to_int(address);

    for (int i = 0; i < 256; i++) {
        if (M[i].address == add)
            return i;
    }
}

int Operation::get_register_by_address(vector<Register> &R, string address) {
    int add = Operation::hex_to_int(address);

    for (int  i = 0; i < 16; i++) {
        if (R[i].address == add)
            return i;
    }
}



//*******************************************
void Operation::One(vector<Memory>& M, vector<Register> &R, string reg_add, string mem_address) {
    int target = get_register_by_address(R, reg_add);
    int Target = get_memory_by_address(M, mem_address);
    R[target].value = M[Target].value;
}
//****************************************
void Operation::Two(vector<Register> &R, string add, string value) {
    int target = get_register_by_address(R,add);
    R[target].value = value;
}
//*************************************
void Operation::Three(vector<Memory>& M, vector<Register> &R, string reg_add, string mem_address) {
    int target1 = get_register_by_address(R,reg_add);
    int target2 = get_memory_by_address(M, mem_address);

    if(mem_address == "00")
        cout << R[target1] << endl;
    else
        M[target2].value = R[target1].value;

}
//**************************************
void Operation::Four(vector<Register> &R, string add1, string add2) {
    int target1 = get_register_by_address(R, add1);
    int target2 = get_register_by_address(R, add2);

    R[target2].value = R[target1].value;
}
//****************************
string Operation::add_binary(string one, string two, bool flag) {
    string answer = "";
    int carry = 0;

    for (int  i = one.size() - 1; i >= 0; i--) {
        answer = ((char) (((one[i] - '0' + two[i] - '0' + carry) % 2) + '0')) + answer;

        carry = (one[i] - '0' + two[i] - '0' + carry) / 2;
    }
    if ( flag == false) {
        answer = (char)(carry + '0') + answer;
    }
    return answer;
}
//***************************
string Operation::negative_to_positive(string neg) {
    for (int i = 0; i <= neg.size() - 1;i++) {
        if (neg[i] == '0')
            neg[i] = '1';
        else if (neg[i] == '1')
            neg[i] = '0';
    }
    neg = add_binary(neg, "0001", false);
    return neg;
}
//*************************
void Operation::Five(vector<Register> &R,string place_add,string add_1, string add_2) {
    int target_1 = get_register_by_address(R, add_1);
    int target_2 = get_register_by_address(R, add_2);

    string one  = R[target_1].value;
    string two = R[target_2].value;
    string answer="";

    one = hex_to_bin(one);
    two = hex_to_bin(two);



    if (one[0] == '1')  one = negative_to_positive(one);
    if (two[0] == '1')  two = negative_to_positive(two);

    if ((one[0] == '1' and two[0] == '0') or (two[0] == '1' and one[0] == '0')) {
        answer += add_binary(one, two, true); //Ignore the carry
    }
    else {
        answer += add_binary(one, two, false);
    }

    int place = get_register_by_address(R,place_add);
    R[place].value = answer;
//It adds only four


}

#endif
