#include<iostream>
#include<vector>

#define ll long long

using namespace std;

ll dp[10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }
    dp[n - 1] = store[n - 1];
    ll width = 2;
    for (int i = n - 2; i >= 0; i--) {
        if (i >= n - 2 - width + 1) dp[i] = max(dp[i + 1], store[i]);
        else {
            dp[i] = max(dp[i + 1], dp[i + width + 1] + store[i]);
        }
    }
    cout << dp[0] << "\n";
}