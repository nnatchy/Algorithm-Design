#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define matrix vector<vector<ll>>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, Q;
    cin >> N >> Q;
    vector<pll> x;
    vector<ll> dp(N);
    for (int i = 0; i < N; i++) {
        ll X, C;
        cin >> X >> C;
        x.push_back(make_pair(X, C));
    }
    sort(x.begin(), x.end());
    dp[0] = x[0].second;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + x[i].second;
    }
    while (Q--) {
        ll ind;
        cin >> ind;
        auto it = lower_bound(dp.begin(), dp.end(), ind);
        if (it == dp.end()) it--;
        ll indInDp = it - dp.begin();
        cout << x[indInDp].first << "\n";
    }
}