#include<iostream>
#include<string.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    while (n--) {
        string inp;
        cin >> inp;
        bool pass = false;
        if (inp.length() == 2) {
            if (stoi(inp) % 7 == 0) {
                cout << inp << "\n";
            } else {
                for (int i = 1; i < 9; i++) {
                    string tmp1 = to_string(i) + inp[1];
                    if (stoi(tmp1) % 7 == 0) {
                        cout << tmp1 << "\n";
                        pass = true;
                        break;
                    }
                }
                if (pass) continue;
                for (int i = 0; i < 9; i++) {
                    string tmp2 = inp[0] + to_string(i);
                    if (stoi(tmp2) % 7 == 0) {
                        cout << tmp2 << "\n";
                        break;
                    }
                }
            }
 
        } else if (inp.length() == 3) {
            if (stoi(inp) % 7 == 0) {
                cout << inp << "\n";
                continue;
            }
            if (inp[1] == '0') {
                for (int i = 1; i < 9; i++) {
                    string tmp = inp[0] + to_string(i) + inp[2];
                    if (stoi(tmp) % 7 == 0) {
                        cout << tmp << "\n";
                        pass = true;
                        break;
                    }
                }
                if (pass) continue;
                for (int i = 1; i < 9; i++) {
                    for (int j = 1; j < 9; j++) {
                        string tmp1 = to_string(i) + to_string(j) + inp[2];
                        if (stoi(tmp1) % 7 == 0) {
                            cout << tmp1 << "\n";
                            pass = true;
                            break;
                        }
                    }
                    if (pass) break;
                }
            }
            if (pass) continue;
            else {
                int rem = stoi(inp) % 7;
                int res;
                if (stoi(inp) - rem < 100 || to_string(stoi(inp) - rem)[1] == '0' || to_string(stoi(inp) - rem)[1] != inp[1]) res = stoi(inp) + 7 - rem;
                else res = stoi(inp) - rem;
                cout << res << "\n";
            }
        }
 
    }
}