#include <iostream>
//Task 2
#include "BigReal.h"
//Task 3
#include "Register.h"
#include "Memory.h"
#include "Operation.h"
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

    BigReal res_add = num1 + num2;
    cout << "N1 + N2 = " << res_add  << endl;

    BigReal res_sub = num1 - num2;
    cout << "N1 - N2 = " << res_sub  << endl;

//      Task 3
//
//        vector<Register> R(16);
//        vector<Memory> M(256);
//        Operation O;
//
//        //Initializing the addresses
//        for (int i = 0; i < 16; i++) {
//            R[i].address = i;
//        }
//        for (int i = 0; i < 256; i++) {
//            M[i].address = i;
//        }
////***************************************
//
//        M[163].value = "AA";
//
//        O.One(M, R, "4", "A3");
//        cout << R[4] << endl;
////********************************
//        O.Two(R, "0", "A3");
//        cout << R[0] << endl;
////*******************************
//        R[O.get_register_by_address(R, "B5")].value = "AB";
//        R[O.get_register_by_address(R, "B6")].value = "BB";
//        O.Three(M, R, "B5", "00");
//        O.Three(M, R, "B6", "A0");
//        cout << M[O.get_memory_by_address(M, "A0")] << endl;
////********************************************************
//        R[O.get_register_by_address(R, "A")].value = "55";
//        O.Four(R, "A", "4");
//        cout << R[4] << endl;
////****************************************************
//        string z = O.add_binary("1100", "1100", true);
//        cout << z << endl;
//
////********************
//        R[2].value = "4A";
//        R[6].value = "BB";
//        O.Five(R,"7","2","6");
//        cout << R[7] <<endl;

    return 0;
}