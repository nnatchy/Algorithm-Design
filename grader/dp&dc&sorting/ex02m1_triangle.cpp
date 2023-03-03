#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll> > triangle(n);
    int x = 1;
    while (x <= n) {
        vector<ll> store(x);
        for (int i = 0; i < x; i++) {
            cin >> store[i];
        }
        triangle[x - 1] = store;
        x++;
    }

    ll dp[n + 1];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0 ; j < triangle[i].size(); j++) {
            if (i == n - 1) dp[j] = triangle[i][j];
            else {
                dp[j] = triangle[i][j] + max(dp[j + 1], dp[j]);
            }
        }
    }
    cout << dp[0] << "\n";
}

