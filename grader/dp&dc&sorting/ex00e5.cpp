#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string binary = "";
    for (int i = 0; i < n; i++) binary += '0';
    for (int i = 0; i < pow(2, n); i++) {
        int j = binary.length() - 1;
        for (; j >= 0 && binary[j] == '1'; j--) {
            binary[j] = '0';
        }
        if (j >= 0) binary[j] = '1';
        string check = "";
        for (int a = 0; a < k; a++) check += '1';
        for (int a = 0; a < binary.length() - k + 1; a++) {
            string tmp = "";
            int x = a;
            for (int l = 0; l < k; l++) tmp += binary[x++];
            if (tmp == check) {
                cout << binary << "\n";
                break;
            }

        }
    }
}