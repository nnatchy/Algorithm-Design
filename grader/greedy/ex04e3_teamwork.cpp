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

using namespace std;

int main() {
    IO;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > vl(n);
    vector<ll> store(m);
    for (int i = 0; i < m; i++) cin >> store[i];
    sort(store.begin(), store.end());
    ll i = 0;
    for (int j = 0; j < store.size(); j++) {
        vl[i++].push_back(store[j]);
        i %= n;
    }

    long double sum = 0;
    ll cnt = 0;
    for (auto &v : vl) {
        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        cnt += v.size();
        sum += accumulate(v.begin(), v.end(), 0.0);
    }
    cout << fixed << setprecision(3) << sum / cnt << "\n";
}