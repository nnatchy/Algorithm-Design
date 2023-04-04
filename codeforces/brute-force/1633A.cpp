#include<iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    while (n--) {
        int inp;
        cin >> inp;
        int store = inp;
        if (inp % 7 == 0) {
            cout << inp << "\n";
            continue;
        }
        int rem = inp % 10;
        int up = 9 - rem;
        bool pass = false;
        while (rem--) {
            inp--;
            if (inp % 7 == 0) {
                pass = true;
                break;
            }
        }
        if (pass) {
            cout << inp << "\n";
            continue;
        }
        while (up--) {
            store++;
            if (store % 7 == 0) break;
        }
        cout << store << "\n";
    }
}