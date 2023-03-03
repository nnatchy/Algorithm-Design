#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<vector<ll> > dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> dp[i][j];
        }
    }
    vector<ll> chosenItem;
    while (n > 0 && m > 0) {
        if (m >= w[n - 1] && dp[n][m] == v[n - 1] + dp[n - 1][m - w[n - 1]]) {
            chosenItem.push_back(n);
            m -= w[n - 1];
        }
        n--;
    }
    cout << chosenItem.size() << "\n";
    for (int i = 0; i < chosenItem.size(); i++) {
        cout << chosenItem[i] << " ";
    }
    cout << "\n";
}