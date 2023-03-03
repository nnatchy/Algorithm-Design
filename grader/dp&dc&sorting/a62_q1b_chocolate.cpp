#include<iostream>
#include<vector>

#define ll long long
#define mod 1000003

using namespace std;

ll dp[10010];

// ll solve(ll amount, vector<ll> &store) {
//     if (dp[amount] != 0) return dp[amount];
//     ll x = 0;
//     for (ll &choc : store) {
//         if (amount - choc < 0) break;
//         if (amount - choc == 0) {
//             x++;
//             continue;
//         }
//         ll leftChoc = amount - choc;
//         x = (x + solve(leftChoc, store) % 1000003) % 1000003;
//     }
//     dp[amount] = x;
//     return dp[amount];
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> store(k);
    for (int i = 0; i < k; i++) {
        cin >> store[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (ll &choc : store) {
            if (i - choc >= 0) {
                dp[i] = (dp[i] + dp[i - choc] % mod) % mod;
            }
        }
    }
    cout << dp[n] << "\n";
}