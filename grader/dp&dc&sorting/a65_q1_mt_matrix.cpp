#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

#define ll long long int
#define pii pair<ll,ll>

using namespace std;

ll solve(vector<vector<ll> > &store, ll r, ll c, bool neg, ll step, ll &n) {
    ll len = 1LL << (n - step);
    if (n - len == 1) {
        if (neg) return -store[r][c];
        return store[r][c];
    }
    if (r < len / 2 && c < len / 2) return solve(store, r, c, neg, step + 1, n);
    if (r >= len / 2 && c < len / 2) return solve(store, r - len / 2, c, !neg, step + 1, n);
    if (r < len / 2 && c >= len / 2) return solve(store, c - len / 2, r, neg, step + 1, n);
    if (r >= len / 2 && c >= len / 2) return solve(store, c - len / 2, r - len / 2, !neg, step + 1, n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > store(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> store[i][j];
        }
    }
    while (m--) {
        ll row, col;
        cin >> row >> col;
        row--; col--;
        cout << solve(store, row, col, false, 0, n) << "\n";
    }
}