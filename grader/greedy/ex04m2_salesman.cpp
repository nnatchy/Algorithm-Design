#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<numeric>

#define ll long long
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define pll pair<ll, ll>
#define ppl pair<ll, pll>

ll dp[10005];
ll seq[10005];
ll sumTime = 0;

using namespace std;

ll compute(ll start, ll stop) {
    if (start > stop) swap(start, stop);
    return min(dp[stop] - dp[start], sumTime - (dp[stop] - dp[start]));
}

int main() {
    IO;
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> seq[i];
    seq[m] = seq[0];
    for (int i = 1; i <= m; i++) {
        cin >> dp[i];
        sumTime += dp[i];
        dp[i] += dp[i - 1];
    }
    while (n--) {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ll tmp = compute(seq[i - 1], seq[i]); // w/o portal
            tmp = min(tmp, compute(seq[i], a) + compute(seq[i - 1], b)); // clockwise
            tmp = min(tmp, compute(seq[i], b) + compute(seq[i - 1], a)); // counter clockwise
            ans += tmp;
        }
        cout << ans << "\n";
    }
}