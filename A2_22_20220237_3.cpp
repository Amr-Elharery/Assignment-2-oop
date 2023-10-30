// File: A2_22_20220237_3.cpp
// Purpose: Strings, Arrays, Pointers, Vectors and Structures.
// Author: Amr Tamer Samy.
// Section: 22.
// ID: 20220237.
// TA: Eng / Rana Abd Elkader.
// Date: 12 Oct 2023

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> split( string target, char delimiter);

int main()
{
  vector<string> v1 ;
  vector<string> v2 ;
  v1 = split("10,20,30", ',');
  v2 = split("do re mi fa so la ti do", ' ');

  for( string &c : v1 )
  {
    cout << c << " " ;
  }
  cout << "\n";

  for( string &c : v2 )
  {
    cout << c << " " ;
  }

  return 0;
}

vector<string> split(string target, char delimiter)
{
  string str;
  vector<string> result;

  for (char i : target) {
    if(i == delimiter )
    {
      result.push_back(str);
      str = "";
    }
    else
    {
      str += i;
    }
  }

  result.push_back(str);

  return result;
}