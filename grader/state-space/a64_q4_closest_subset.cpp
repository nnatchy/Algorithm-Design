#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }
    vector<ll> dp(n + 1, 0);
    
}