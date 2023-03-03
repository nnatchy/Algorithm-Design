#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

#define ll long long int
#define pii pair<ll,ll>

using namespace std;

void DC(vector<vector<ll>> &vll, ll left, ll right, ll top, ll bottom, ll type, ll u, ll v, ll w, ll p, ll n, bool transpose) {
    if (n == 1) {
        vll[top][left] = u * type;
        vll[top][right] = v * type;
        vll[bottom][left] = w * type;
        vll[bottom][right] = p * type;
    }
    ll col = (left + right) / 2;
    ll row = (top + bottom) / 2;
    if (transpose) {
        for (ll i = col; i < right; i++) {
            for (ll j = row; j < bottom; j++) {
                if (i != j) {
                    swap(vll[i][j], vll[j][i]);
                }
            }
        }
    }
    DC(vll, left, col, top, row, type, u, v, w, p, n-1, false);
    DC(vll, col, right, top, row, type, u, v, w, p, n-1, true);
    DC(vll, left, col, row, bottom, -type, u, v, w, p, n-1, false);
    DC(vll, col, right, row, bottom, -type, u, v, w, p, n-1, true);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, u, v, w, p;
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    vector<vector<ll>> vll;
    vector<ll> store;
    for (ll i = 0; i < pow(2, n); i++) store.push_back(0);
    for (ll i = 0; i < pow(2, n); i++) {
        vll.push_back(store);
    }
    for (int i = 0; i < vll.size(); i++) {
        for (int j = 0; j < vll[i].size(); j++) {
            cout << vll[i][j] << " ";
        }
        cout << "\n";
    }
    DC(vll, 0, 1LL << n, 0, 1LL << n, 1, u, v, w, p, n, false);
    for (int i = 0; i < m; i++) {
        ll r,c;
        cin >> r >> c;
        cout << vll[r][c] << "\n";
    }
}