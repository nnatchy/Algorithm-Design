#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, e;
    cin >> n >> e;
    vector<vector<ll> > vl(n);
    for (int i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;
        vl[a - 1].push_back(b - 1);
    }
    for (int _ = 0; _ < 5; _++) {
        vector<ll> visited(n, 0);
        vector<ll> ord;
        for (int i = 0; i < n; i++) {
            ll inp;
            cin >> inp;
            ord.push_back(inp - 1);
        }
        bool check = true;
        for (int i = 0; i < n; i++) {
            visited[ord[i]] = 1;
            for (auto &x : vl[ord[i]]) {
                if (visited[x]) {
                    check = false;
                }
            }
        }
        if (check) cout << "SUCCESS\n";
        else cout << "FAIL\n";
    }
}