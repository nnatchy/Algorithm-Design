#include<iostream>
#include<limits.h>

#define ll long long

using namespace std;

ll dp[110][110];
ll mc[110];

int mmc(ll i, ll j) {
    if (i == j) return 0;
    if (dp[i][j] > 0) return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], mmc(i, k) + mmc(k + 1, j) + mc[i] * mc[k + 1] * mc[j + 1]);
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N, inp;
    cin >> N;
    for (int i = 0; i < N + 1; i++) {
        cin >> mc[i];
    }
    cout << mmc(0, N - 1) << "\n";
}