// File: A2_22_20220237_12.cpp
// Purpose: Files.
// Author: Amr Tamer Samy.
// Section: 22.
// ID: 20220237.
// TA: Eng / Rana Abd Elkader.
// Date: 12 Oct 2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define phishing keywords and their associated point values
map<string, int> phishingKeywords = {
    {"bank", 3},
    {"credit card", 2},
    {"password", 3},
    {"social security number", 3},
    {"user name", 2},
    {"online payment", 2},
    {"account", 2},
    {"verification", 2},
    {"update", 2},
    {"security", 3},
    {"urgent", 2},
    {"verify", 2},
    {"suspicious", 3},
    {"phishing", 3},
    {"scam", 3},
    {"fraud", 3},
    {"click here", 2},
    {"login", 2},
    {"fraudulent", 3},
    {"official", 1},
    {"personal information", 3},
    {"alert", 2},
    {"confirm", 2},
    {"unauthorized", 3},
    {"identity theft", 3},
    {"IRS", 3},
    {"IRS refund", 3},
    {"PayPal", 3},
    {"Amazon", 3},
    {"Facebook", 3}
};

int main() {
    string fileName = "E:\\Amr\\EDUCATION\\FCAI\\Second-Year\\First-semester\\OOP\\Assignments\\Assignment-2\\words.txt";

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;
    int totalPoints = 0;

    while (getline(file, line)) {
        for (const auto& keyword : phishingKeywords) {
            int pos = 0;
            int keywordPoints = 0;

            while ((pos = line.find(keyword.first, pos)) != string::npos) {
                keywordPoints += keyword.second;
                pos += keyword.first.length();
            }

            if (keywordPoints > 0) {
                cout << keyword.first << " - Occurrences: " << keywordPoints / keyword.second << ", Points: " << keywordPoints << endl;
                totalPoints += keywordPoints;
            }
        }
    }

    cout << "Total points for the entire message: " << totalPoints << endl;

    file.close();
    return 0;
}