#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, w, k;
    cin >> n >> w >> k;
    vector<ll> l(n, 0), r(n, 0);
    vector<vector<ll> > dp(2, vector<ll>(n, -1));
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    dp[0].back() = l.back();
    dp[1].back() = r.back();
    ll mx = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (i >= n - 1 - w) {
            dp[0][i] = max(l[i],dp[0][i + 1]);
            dp[1][i] = max(r[i], dp[1][i + 1]);
        }
        else {
            dp[0][i] = max(dp[0][i + 1], dp[1][i + w + 1] + l[i]); // l = 0, r = 1;
            dp[1][i] = max(dp[1][i + 1], dp[0][i + w + 1] + r[i]);
        }
    }
    cout << max(dp[0][0], dp[1][0]) << "\n";
}