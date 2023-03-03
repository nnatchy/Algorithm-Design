#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    string binary = "";
    for (int i = 0; i < B; i++) binary += '0';
    for (int i = 0; i < pow(2, B); i++) {
        int j = binary.length() - 1;
        for (; j >= 0 && binary[j] == '1'; j--) {
            binary[j] = '0';
        }
        if (j >= 0) binary[j] = '1';
        int cnt = 0;
        for (int k = 0; k < binary.length(); k++) {
            if (binary[k] == '1') cnt++;
        }
        if (cnt == A) {
            cout << binary << "\n";
        }
    }

}