#include<iostream>
#include<vector>

#define ll long long
#define mod 1997;

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll> > dp(n + 1, vector<ll>(k + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        dp[i][1] = 1;
    }
    for (int i = 1; i < k + 1; i++) {
        dp[i][i] = 1;
    }
    for (int i = 2; i < n + 1; i++) {
        for (int j = 2; j < k + 1; j++) {
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % mod;
        }
    }
    cout << dp[n][k] << "\n";
}