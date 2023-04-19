#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll currentAns = 1e9;
vector<bool> used;
vector<ll> store;

void solve(ll step, ll n, ll wantedLen, ll target, ll haveChosen, ll i, ll currentSum) {
    if (haveChosen == wantedLen) {
        if (abs(currentSum - target) <= abs(currentAns - target)) {
            currentAns = currentSum;
        }
        return;
    }
    if (n - step < wantedLen - haveChosen) return;
    if (currentSum > target && abs(currentSum - target) >= abs(currentAns - target)) return;
    if (haveChosen < wantedLen) {
        solve(step + 1, n, wantedLen, target, haveChosen + 1, i + 1, currentSum + store[i]);
        if (wantedLen - haveChosen < n - step) {
          solve(step + 1, n, wantedLen, target, haveChosen, i + 1, currentSum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    store.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }
    sort(store.begin(), store.end(), greater<ll>());
    solve(0, n, m, k, 0, 0, 0);
    cout << abs(k - currentAns) << "\n";
}