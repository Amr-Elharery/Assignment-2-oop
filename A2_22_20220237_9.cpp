// File: A2_22_20220237_9.cpp
// Purpose: Recursion.
// Author: Amr Tamer Samy.
// Section: 22.
// ID: 20220237.
// TA: Eng / Rana Abd Elkader.
// Date: 12 Oct 2023
#include <iostream>

using namespace std;

bool bear(int n);

int main()
{
  cout << bear(250)<< endl;
  cout << bear(42)<< endl;
  cout << bear(84) << endl;
  cout << bear(53) << endl;
  cout << bear(41) << endl;
  return 0;
}

bool bear(int n)
{
  while(n!=42)
  {
    if(!(n % 5))
    {
      n = 42;
    }
    else if(!(n % 2))
    {
      n /= 2;
    }
    else if(!(n%3) || !(n%4))
    {
      n = (n % 10) *  ((n % 100) / 10);
    }
    else
    {
      return false;
    }
  }
    return true;

}