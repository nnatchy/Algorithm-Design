#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define mod 100000007

using namespace std;

ll dp[10000003];

int main() {
    ll n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        if (i <= 3) {
            dp[i] = (dp[i - 1] * 2 + 3) % mod;
        } else {
            dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % mod;
        }
    }
    cout << dp[n] << "\n";
}