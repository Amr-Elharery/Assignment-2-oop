#include <iostream>
#include <vector>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChainHelper (vector<dominoT> & dominos, vector<bool> & used, vector<dominoT> & chain) {
    if (chain.size() == dominos.size()) {
        return true;
    }

    int prevRightDots = (chain.empty() ? 0 : chain.back().rightDots);

    for (int i = 0; i < dominos.size(); i++) {
        if (!used[i] && (dominos[i].leftDots == prevRightDots || dominos[i].rightDots == prevRightDots)) {
            used[i] = true;
            chain.push_back(dominos[i]);
            if (FormsDominoChainHelper(dominos, used, chain)) {
                return true;
            }
            used[i] = false;
            chain.pop_back();
        }
    }

    return false;
}

bool FormsDominoChain(vector<dominoT> & dominos, vector<dominoT> & chain) {
    if (dominos.empty()) {
        return true;
    }

    vector<bool> used(dominos.size(), false);

    for (int i = 0; i < dominos.size(); i++) {
        used[i] = true;
        chain.push_back(dominos[i]);
        if (FormsDominoChainHelper(dominos, used, chain)) {
            return true;
        }
        used[i] = false;
        chain.pop_back();
    }

    return false;
}

int main() {
    int x1 ,y1 ,x2 ,y2 ,x3 ,y3 ,x4 ,y4 ,x5 ,y5 ;
    cout << "Enter the domino's dots values :" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 ;
    vector<dominoT> dominoSet = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}, {x5, y5}};

    vector<dominoT> chain;

    if (FormsDominoChain(dominoSet, chain)) {
        cout << "True and the chain will be : " << endl;

        for (const dominoT &domino : chain) {
            cout << domino.leftDots << "|" << domino.rightDots << " - ";
        }
        cout << endl;
    } else {
        cout << "False domino chain can't be formed." << endl;
    }

    return 0;
}
