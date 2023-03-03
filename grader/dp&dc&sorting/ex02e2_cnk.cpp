#include<iostream>

#define ll long long int

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    cout << dp[n][k] << "\n";
}