#include<iostream>
#include<vector>
#include<limits.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> store(N);
    for (int i = 0; i < N; i++) {
        cin >> store[i];
    }
    vector<ll> dp(10010, INT_MAX);
    dp[N - 1] = store.back();
    for (int i = N - 2; i >= 0; i--) {
        if (i >= N - K - 1) dp[i] = store[i];
        else {
            for (int j = 1; j <= 2 * K + 1 && i + j < N; j++) {
                dp[i] = min(dp[i], dp[i + j] + store[i]);
            }
        }
    }
    ll mn = dp[0];
    for (int i = 1; i <= K; i++) {
        mn = min(mn, dp[i]);
    }
    cout << mn << "\n";
}