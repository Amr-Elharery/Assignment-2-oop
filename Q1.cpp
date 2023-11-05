#include <iostream>
using namespace std;

int main() {

    string input ;
    string sentence ;
    getline (cin, input);
    bool isspace = false;

    for (char word : input){
        if (word == ' ' || word == '\n' || word == '\t' ){
            if (!isspace) {
                sentence += ' ';
            }
            isspace = true;
        }
        else {
            sentence += word;
            isspace = false;
        }
    }

    sentence[0] = toupper (sentence[0]);

    for (int i = 1; i < sentence.length() ; i++){
        sentence [i] = tolower (sentence[i]);
    }

    cout << sentence ;
}