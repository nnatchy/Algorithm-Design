#include<iostream>
#include<string>
#include<vector>

using namespace std;

void changeDigit(int year) {

}

int main() {
    int year;
    cin >> year;
    year++;
    bool check = false;
    vector<char> v;
    while (!check) {
        string year_s = to_string(year);
        bool pass = false;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (year_s[i] == year_s[j]) {
                    pass = true;
                    break;
                }
            }
            if (pass) break;
        }
        if (!pass) {cout << year << "\n"; return 0;}
        year++;
    }

}