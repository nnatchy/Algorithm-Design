#include<bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll n, m;
vector<ll> Ki(8);
vector<vector<pll>> vl;
vector<bool> visited;
vector<ll> bestFit;
ll ub = 0;

bool dfs(ll node, ll currentSum, ll target, ll ub) {
    if (currentSum > target) return false;
    if (currentSum == target) return true;
    if (currentSum + ub < target) return false;
    if (visited[node]) return false;
    visited[node] = true;
    for (auto &x : vl[node]) {
        ll nextNode = x.first;
        ll weight = x.second;
        if (!visited[nextNode]) {
            if (dfs(nextNode, currentSum + weight, target, ub - bestFit[nextNode])) {
                return true;
            }
        }
    }
    visited[node] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vl.resize(n);
    bestFit.resize(n, 0);
    for (int i = 0; i < 8; i++) cin >> Ki[i];
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        vl[a].push_back(make_pair(b, w));
        vl[b].push_back(make_pair(a, w));
        bestFit[a] = max(bestFit[a], w);
        bestFit[b] = max(bestFit[b], w);
    }
    for (auto &x : bestFit) ub += x;

    for (int i = 0; i < 8; i++) {
        bool res = false;
        for (int node = 0; node < n; node++) {
            visited = vector(n, false);
            if (dfs(node, 0, Ki[i], ub - bestFit[node])) {
                res = true;
                break;
            }
        }
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}