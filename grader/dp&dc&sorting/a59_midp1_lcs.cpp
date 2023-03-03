#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int main() {
    ll n, m;
    string fir, sec;
    cin >> n >> m >> fir >> sec;
    vector<vector<ll> > dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> dp[i][j];
        }
    }
    string fin = "";
    while (n > 0 && m > 0) {
        if (dp[n][m] - 1 == dp[n - 1][m - 1]) {
            fin += sec[m - 1];
            n--; m--;
        } else {
            if (dp[n - 1][m] == dp[n][m - 1]) {
                m--;
            } else {
                if (dp[n - 1][m] > dp[n][m - 1]) {
                    n--;
                } else {
                    m--;
                }
            }
        }
    }
    for (int i = 0; i < fin.length() / 2; i++) {
        swap(fin[i], fin[fin.length() - 1 - i]);
    }
    cout << fin << "\n";
}