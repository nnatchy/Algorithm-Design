#include<bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll n, m, target;
vector<ll> store;
ll ans = -1e9;

void recur(ll step, ll haveChosen, ll currentSum) {
    if (currentSum > target && abs(currentSum - target) >= abs(ans - target)) return;
    if (haveChosen == m) {
        if (abs(currentSum - target) < abs(ans - target)) {
            ans = currentSum;
        }
        return;
    }
    if (n - step < m - haveChosen) return;
    recur(step + 1, haveChosen + 1, currentSum + store[step]); // choose
    recur(step + 1, haveChosen, currentSum); // not choose
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> target;
    store.resize(n);
    for (int i = 0; i < n; i++) cin >> store[i];
    sort(store.rbegin(), store.rend());
    recur(0, 0, 0);
    cout << abs(target - ans) << "\n";
}