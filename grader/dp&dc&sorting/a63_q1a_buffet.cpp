#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, K, m;
    cin >> n >> K >> m;
    vector<ll> store(n + 1);
    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> store[i];
        store[i] -= m;
        dp[i] = store[i] + dp[i - 1];
    }
    while (K--) {
        ll start, target;
        cin >> start >> target;
        ll idx = lower_bound(dp.begin() + start - 1, dp.end(), dp[start - 1] + target) - dp.begin();
        cout << idx << '\n';
    }
}