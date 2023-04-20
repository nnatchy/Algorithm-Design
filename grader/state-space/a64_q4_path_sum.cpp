#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<set>

#define ll long long
#define pll pair<ll, ll>
#define vv vector<vector<ll> >

using namespace std;

vector<vector<pll> > vl;
vector<ll> bestCost;
ll n;
ll m;

bool solve(ll startNode, ll currentSum, ll target, ll ub, vector<bool> &visited) {
    if (currentSum > target) return false;
    if (currentSum == target) return true;
    if (ub + currentSum < target) return false;
    if (visited[startNode]) return false;
    visited[startNode] = true;
    for (auto &x : vl[startNode]) {
        ll nextNode = x.first;
        ll weight = x.second;
        if (!visited[nextNode]) {
            if (solve(nextNode, currentSum + weight, target, ub - bestCost[nextNode], visited)) {
                return true;
            } else {
                visited[nextNode] = false;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vector<ll> Ki(8);
    for (int i = 0; i < 8; i++) {
        cin >> Ki[i];
    }
    vl.resize(n); bestCost.resize(n, -1);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        vl[a].push_back(make_pair(b, w));
        vl[b].push_back(make_pair(a, w));
        bestCost[a] = max(bestCost[a], w);
        bestCost[b] = max(bestCost[b], w);
    }
    ll ub = 0;
    for (int i = 0; i < n; i++) {
        ub += bestCost[i];
    }
    for (int i = 0; i < 8; i++) {
        bool res = false;
        for (int startNode = 0; startNode < n; startNode++) {
            vector<bool> visited(n);
            res = solve(startNode, 0, Ki[i], ub - bestCost[startNode], visited);
            if (res) break;
        }
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}