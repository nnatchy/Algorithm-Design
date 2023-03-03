#include<iostream>
#include<vector>
#include<cmath>

#define ll long long
#define mod 100000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << (ll) pow(2, n) % mod;
    } else {
        vector<ll> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i <= k) dp[i] = i + 1;
            else dp[i] = (dp[i - 1] + dp[i - k]) % mod;
        }
        cout << dp[n] << "\n";
    }
}