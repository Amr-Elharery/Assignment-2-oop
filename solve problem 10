// File: solve problem 10.cpp
// Purpose: Files.
// Author: Ashraf Abdallah Elmamouni.
// Section: 22.
// ID: 20220062.
// TA: Eng / Rana Abd Elkader.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;

vector<string> c(const string& str) {
    vector<string> tokens;
    string word;
    for (char32_t c : str) {
        if (iswalnum(c)) {
            word.push_back(c);
        } else {
            if (!word.empty()) {
                tokens.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tokens.push_back(word);
    }
    return tokens;
}

string replaceWords(const string& input, const unordered_map<string, vector<string>>& lookupTable) {
    string output;
    vector<string> tokens = c(input);
    random_device rd;
    mt19937 gen(rd());

    for (const string& token : tokens) {
        auto it = lookupTable.find(token);
        if (it != lookupTable.end()) {
            const vector<string>& alternatives = it->second;
            uniform_int_distribution<> dis(0, static_cast<int>(alternatives.size()) - 1);
            output += alternatives[dis(gen)];
        } else {
            output += token;
        }
        output += " ";
    }

    return output;
}

int main() {
    string inputFile = "input.txt";
    string lookupFile = "lookup.txt";
    string outputFile = "output.txt";

    unordered_map<string, vector<string>> lookupTable;
    ifstream file(lookupFile);

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            size_t separatorIndex = line.find(':');
            if (separatorIndex != string::npos) {
                string word = line.substr(0, separatorIndex);
                string alternativesString = line.substr(separatorIndex + 1);
                vector<string> alternatives = c(alternativesString);
                lookupTable[word] = alternatives;
            }
        }

        file.close();
    }

    else {
        cout << "Failed to open lookup file." << endl;
        return 1;
    }

    ifstream inputFileStream(inputFile);
    if (inputFileStream.is_open()) {
        string inputMessage((istreambuf_iterator<char>(inputFileStream)),
                            istreambuf_iterator<char>());
        inputFileStream.close();

        string outputMessage = replaceWords(inputMessage, lookupTable);

        ofstream outputFileStream(outputFile);
        if (outputFileStream.is_open()) {
            outputFileStream << outputMessage;
            outputFileStream.close();
            cout << "Modified message saved to " << outputFile << endl;
        } else {
            cout << "Failed to open output file." << endl;
            return 1;
        }
    } else {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    return 0;
}
