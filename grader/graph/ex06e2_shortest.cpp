#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<numeric>
#include<tuple>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

// BELLMAN-FORD

int main() {
    ll n, e, s;
    cin >> n >> e >> s;
    vector<lll> vl(n);
    for (int i = 0; i < e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        vl.push_back(tuple(a, b, c));
    }
    vector<ll> d(n, 1e9);
    d[s] = 0; 
    for (int i = 1; i < n; i++) {
        for (auto [a, b, c] : vl) {
            if (d[a] + c < d[b]) {
                d[b] = d[a] + c;
            }
        }
    }
    for (auto [a, b, c] : vl) {
        if (d[a] + c < d[b]) {
            cout << "-1\n";
            return 0;
        }
    }
    for (auto &x : d) cout << x << " ";
    cout << "\n";
}