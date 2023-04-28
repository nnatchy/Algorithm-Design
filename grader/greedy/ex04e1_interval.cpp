#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

#define ll long long
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define rep(a, b) for(int i = a; i < b; i++)
#define pll pair<ll, ll>

using namespace std;

int main() {
    IO;
    ll n;
    cin >> n;
    vector<pll> vpl(n);
    rep(0, n) cin >> vpl[i].second;
    rep(0, n) cin >> vpl[i].first;
    sort(vpl.begin(), vpl.end());
    ll finish = vpl[0].first;
    ll cnt = 1;
    rep(1, n) {
        if (vpl[i].second >= finish) {
            finish = vpl[i].first;
            cnt++;
        }
    }
    cout << cnt << "\n";
}