// File: A2_22_20220237_6.cpp
// Purpose: Recursion.
// Author: Amr Tamer Samy.
// Section: 22.
// ID: 20220237.
// TA: Eng / Rana Abd Elkader.
// Date: 12 Oct 2023
#include <iostream>

using namespace std;
void binaryPrint(int n);


int main()
{
  binaryPrint(0);
//  binaryPrint(4);
//  binaryPrint(27);
  return 0;
}

void binaryPrint(int n)
{
  string binary;
  if (n == 0) binary = '0';

  cout<< binary;

}