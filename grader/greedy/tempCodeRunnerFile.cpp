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
    ll n, l;
    cin >> n >> l;
    vector<ll> store(n);
    for (int i = 0; i < n; i++) cin >> store[i];
    sort(store.begin(), store.end());
    ll cnt = 0;
    ll pos = 0;
    for (auto &hole : store) {
        if (hole > pos) {
            cnt++;
            pos = hole + l;
        }
    }
    cout << cnt << "\n";
}
