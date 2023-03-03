#include<iostream>
#include<limits.h>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll> > store(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> store[i][j];
        }
    }
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        ll curMax = store[0][i];
        for (int j = 1; j < n - i; j++) {
            curMax = max(curMax + store[j][i + j], store[j][i + j]);
            mx = max(curMax, mx);
        }
        curMax = store[i][0];
        for (int j = 1; j < n - i; j++) {
            curMax = max(curMax + store[i + j][j], store[i + j][j]);
            mx = max(curMax, mx);
        }
    }
    cout << mx << '\n';
}