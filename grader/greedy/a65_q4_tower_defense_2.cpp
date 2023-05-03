#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define ll long long
#define pll pair<ll, ll>
#define ppl pair<ll, pll>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define lll tuple<ll, ll, ll>

using namespace std;

int main()
{
    IO;
    ll n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<pll> a(m);
    ll sum = 0;
    for (int i = 0; i < m; i++) cin >> a[i].first;
    for (int i = 0; i < m; i++) cin >> a[i].second, sum += a[i].second;
    sort(a.begin(), a.end());
    ll ans = 0;
    ll last = 1;
    for (int i = 0; i < m; i++) {
        ll l = a[i].first - w;
        l = max(l, last);
        ll r = a[i].first + w;
        r = min(r, n);
        
        ll cnt = r - l + 1;
        cnt = min(cnt, k);
        cnt = min(a[i].second, cnt);

        ans += cnt;
        k -= cnt;
        last = l + cnt;
    }
    cout << sum - ans << "\n";
}