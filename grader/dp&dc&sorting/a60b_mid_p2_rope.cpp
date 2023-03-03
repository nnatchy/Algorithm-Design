#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    set<ll> store; store.insert(a); store.insert(b); store.insert(c);
    vector<ll> dp(n + 1, 0);
    dp[*store.begin()] = 1;
    for (int i = *store.begin(); i < n + 1; i++) {
        for (auto it : store) {
            if (i - it >= 0 && dp[i - it] != 0) {
                dp[i] = max(dp[i], 1 + dp[i - it]);
            }
        }
    } 
    cout << dp[n] << "\n";
}