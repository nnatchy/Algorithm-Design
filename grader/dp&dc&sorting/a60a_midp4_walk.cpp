#include<iostream>
#include<vector>

#define ll long long

using namespace std;

ll dp[510][510];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > store(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> store[i-1][j-1];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp[i][j] = max(max(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1] + store[i][j]) + store[i-1][j-1];
        }
    }
    cout << dp[1][1] << "\n";
}
