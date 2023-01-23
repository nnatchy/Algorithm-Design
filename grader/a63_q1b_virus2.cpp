#include<iostream>
#include<cmath>

using namespace std;

bool checkVirus(string &virusA, string &virusB){
    if (virusA.length() < 2 || virusB.length() < 2) return true; 
    int cntA = 0, cntB = 0;
    string compareA = "", compareB = "";
    string splitAa = "", splitAb = "", splitBa = "", splitBb = "";
    for (int i = 0; i < virusA.length(); i++) {
        compareA += virusA[i];
        if (i < virusA.length() / 2) splitAa += virusA[i];
        else splitAb += virusA[i];
        if (virusA[i] == '1') {
            cntA++;
        }
    }
    for (int i = 0; i < virusB.length(); i++) {
        compareB += virusB[i];
        if (i < virusB.length() / 2) splitBa += virusB[i];
        else splitBb += virusB[i];
        if (virusB[i] == '1') {
            cntB++;
        }
    }
    if (abs(cntB - cntA) > 1) return false;
    else return checkVirus(splitAa, splitAb) && checkVirus(splitBa, splitBb);
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    while (n--) {
        int rnd = pow(2, k) / 2;
        string virusA = "", virusB = "";
        char bit;
        for (int i = 0 ; i < rnd; i++) {
            cin >> bit;
            virusA += bit;
        }
        for (int i = 0; i < rnd; i++) {
            cin >> bit;
            virusB += bit;
        }
        int cntA = 0, cntB = 0;
        bool check = checkVirus(virusA, virusB);
        if (check) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}