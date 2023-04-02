#include<iostream>
#include<queue>
#include<stack>
#include<vector>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

vector<ll> visited, depth;
vector<vector<ll> > adjMatrix;

// DFS

void dfs(ll node, ll parent, ll distance) {
    if (visited[node]) {
        cout << distance - depth[node] << "\n";
        exit(0);
    }
    visited[node] = 1;
    depth[node] = distance;
    for (auto &x : adjMatrix[node]) {
        if (x != parent) {
            dfs(x, node, distance + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    visited.resize(N);
    adjMatrix.resize(N);
    depth.resize(N);
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        dfs(i, -1, 0);
    }
}