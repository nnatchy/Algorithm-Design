#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

vector<vector<ll> > vl;
vector<ll> visited;

// DFS (topological-sort)

void topoSort(ll node, vector<ll> &order) {
    visited[node] = 1;
    for (auto &x : vl[node]) {
        if (!visited[x]) {
            topoSort(x, order);
        }
    }
    order.push_back(node);
}

int main() {
    ll N;
    cin >> N;
    visited.resize(N);
    vl.resize(N);
    vector<ll> order;
    for (int i = 0; i < N; i++) {
        ll M, inp;
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> inp;
            vl[i].push_back(inp);
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topoSort(i, order);
        }
    }
    for (auto &ord : order) {
        cout << ord << " ";
    }
    cout << "\n";
}