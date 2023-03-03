#include<iostream>
#include<vector>

#define ll long long

using namespace std;


ll solve(vector<ll> &coins, ll &amount) {
    vector<ll> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++) {
        for (ll &coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount];
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    cout << solve(coins, M) << "\n";
}