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
    for (int i = n - 2; i >= 0; i--) {
        if (i == n - 2) dp[i] = store[i];
        else {
            for (int j = 2; j <= 3 && j + i < n; j++) {
                dp[i] = max(dp[i], dp[i + j] + store[i]);
            }
        }
    }
    ll mx = max(dp[0], dp[1]);
    cout << mx << "\n";
}