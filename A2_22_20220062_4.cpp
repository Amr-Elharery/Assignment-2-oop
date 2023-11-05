// File: A2_22_20220062_4.cpp
// Purpose: Files.
// Author: Ashraf Abdallah Elmamouni.
// Section: 22.
// ID: 20220062.
// TA: Eng / Rana Abd Elkader.

#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int n;
    cin >> n;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {

        if (!prime[p]) continue; {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p])
            cout << p << " ";
    }

    return 0;
}
