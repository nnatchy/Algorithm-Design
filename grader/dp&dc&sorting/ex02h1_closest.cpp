#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define pll pair<ll,ll>
#define inf 100000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<pll> store(N);
    for (auto &p : store) {
        cin >> p.first >> p.second;
    }
    sort(store.begin(), store.end());
    int mn = inf;
    int sz = 5;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < min(N, i + sz); j++) {
            int x = store[i].first - store[j].first;
            int y = store[i].second - store[j].second;
            mn = min(mn, x * x + y * y);
        }
    }
    cout << mn << "\n";
}