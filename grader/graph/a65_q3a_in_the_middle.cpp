#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<int, int, int>
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    IO;
    ll n, t1, t2, t3;
    cin >> n >> t1 >> t2 >> t3; // 0, 1, 2
    t1--;
    t2--;
    t3--;
    vector<ll> peep; peep.push_back(t1); peep.push_back(t2); peep.push_back(t3);
    vector<vector<ll> > vl(n);
    for (int i = 0; i < n; i++) {
        ll cntK;
        cin >> cntK;
        while (cntK--) {
            ll inp;
            cin >> inp;
            vl[i].push_back(inp - 1);
        }
    }
    // BFS
    vector<vector<ll> > visited(3, vector<ll>(n, 0));
    for (int i = 0; i < 3; i++) {
        queue<pll> q;
        q.push(make_pair(0, peep[i])); // val, idx
        for (int j = 0; j < n; j++) {
            visited[i][j] = 1e9;
        }
        visited[i][peep[i]] = 0;
        while (!q.empty()) {
            pll current = q.front();
            q.pop();
            ll val = current.first;
            ll pos = current.second;
            for (auto &x : vl[pos]) {
                if (visited[i][x] > visited[i][pos] + 1){
                    q.push(make_pair(val + 1, x));
                    visited[i][x] = visited[i][pos] + 1;
                }
                
            }
        }
    }
    ll mn = 1e9;
    for (int i = 0; i < n; i++) {
        ll mx = max(visited[0][i], max(visited[1][i], visited[2][i]));
        mn = min(mn, mx);
    }
    cout << mn << "\n";
}