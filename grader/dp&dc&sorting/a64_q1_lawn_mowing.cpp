#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> store(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> store[i];
        store[i] += k;
        dp[i] = dp[i - 1] + store[i];
    }
    while (m--) {
        ll start, target;
        cin >> start >> target;
        start++; // start at idx 1;
        if (target < dp[start] - dp[start - 1]) {
            cout << 0 << "\n";
            continue;
        }
        ll wanted = dp[start - 1] + target;
        auto it = lower_bound(dp.begin() + start, dp.end(), wanted) == dp.end() ? --lower_bound(dp.begin() + start, dp.end(), wanted) : lower_bound(dp.begin() + start, dp.end(), wanted);
        ll idx = it - dp.begin();
        if (wanted < dp[idx]) idx--;
        cout << (dp[idx] - k * idx) - (dp[start - 1] - k * (start - 1)) << "\n";
    }
}