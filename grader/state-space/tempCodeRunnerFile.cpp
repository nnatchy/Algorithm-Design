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
    if (step > n) return;
    if (haveChosen < wantedLen) {
        solve(step + 1, n, wantedLen, target, haveChosen + 1, i + 1, currentSum + store[i]);
        solve(step + 1, n, wantedLen, target, haveChosen, i + 1, currentSum);
    } else {
        if (abs(currentSum - target) <= abs(currentAns - target)) {
            // printf("res: %llu\n", currentSum);
            currentAns = currentSum;
        }
        return;
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
    solve(0, n, m, k, 0, 0, 0);
    cout << abs(k - currentAns) << "\n";
}