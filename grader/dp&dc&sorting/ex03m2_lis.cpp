#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int solve(vector<ll> &store) {
    int n = store.size();
    vector<ll> dp;
    dp.push_back(store[0]);
    if (n == 1) return 1;
    for (int i = 1; i < n; i++) {
        if (dp.back() < store[i]) {
            dp.push_back(store[i]);
        } else {
            int ind = lower_bound(dp.begin(), dp.end(), store[i]) - dp.begin();
            dp[ind] = store[i];
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll n, inp;
    cin >> n;
    vector<ll> store(n);
    for (int i = 0; i < n; i++) cin >> store[i];
    cout << solve(store) << "\n";
}