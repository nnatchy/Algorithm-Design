#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define ll long long
#define pll pair<ll, ll>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll k;
    cin >> k;
    for (int _ = 0; _ < k; _++) {
        ll n;
        cin >> n;
        double arr[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    arr[i][j] = max(arr[i][j], arr[i][l] * arr[l][j]);
                }
            }
        }
        bool check = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            if (arr[i][j] * arr[j][i] > 1) {
                check = true;
                break;
                }
            }
            if (check) break;
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}