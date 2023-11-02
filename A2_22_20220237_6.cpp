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
void numbers(string prefix, int k);

int main()
{
  binaryPrint(0);
  cout << endl;
  binaryPrint(4);
  cout << endl;
  binaryPrint(27);
  cout << endl;

  numbers("00101",2);
  return 0;
}

void binaryPrint(int n)
{
  if (n > 0) {
    binaryPrint(n/2);
    cout << n%2;
  }
  else{
    cout<< 0;
  }
}

void numbers(string prefix, int k) {
  if (k == 0) {
    cout << prefix << endl;
    return;
  }

  numbers(prefix + "0", k - 1);
  numbers(prefix + "1", k - 1);
}