#include<iostream>
#include<string>

#define ll long long int

using namespace std;

ll table[550][550];

// int dp(int m, int n, string &first, string &second) {
//     if (m < 0 || n < 0) return 0;
//     if (table[m][n] > 0) return table[m][n];
//     if (first[m] == second[n]) {
//         table[m][n] = dp(m - 1, n - 1, first, second) + 1;
//         return table[m][n];
//     } else {
//         table[m][n] = max(dp(m - 1, n, first, second), dp(m, n - 1, first, second));
//         return table[m][n];
//     }
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string first, second;
    cin >> first >> second;
    ll n = first.length();
    ll m = second.length();
    for (int i = 1; i < n + 1; i++) {
        table[1][i] = 1;
    }
    for (int i = 1; i < m + 1; i++) {
        table[i][1] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (first[i - 1] == second[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    cout << table[n][m] << "\n";
    // cout << dp(first.length() - 1, second.length() - 1, first, second) << "\n";
}