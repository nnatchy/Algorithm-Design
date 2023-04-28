#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<numeric>
#include<queue>
#include<tuple>

#define ll long long
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define pll pair<ll, ll>
#define ppl pair<ll, pll>
#define lll tuple<ll, ll, ll>

using namespace std;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<lll> vl(k);
    for (int i = 0; i < k; i++) {
        ll d, e, l;
        cin >> get<0>(vl[i]) >> get<1>(vl[i]) >> get<2>(vl[i]);
    }
    sort(vl.begin(), vl.end());
    queue<ll> plant, store;
    for (auto &[d, e, l] : vl) {
        if (!e) {
            plant.push(l);
            if (!store.empty()) {
                ll currentStore = store.front();
                store.pop();
                plant.pop();
                cout << currentStore << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            store.push(l);
            if (!plant.empty()) {
                ll currentPlant = plant.front();
                plant.pop();
                store.pop();
                cout << currentPlant << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
}