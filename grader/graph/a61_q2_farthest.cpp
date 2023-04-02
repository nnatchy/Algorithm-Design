#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vector<ll> > adjMatrix(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    vector<ll> nodes(n, 1e9);
    nodes[0] = 0;
    pq.push(make_pair(0, 0)); // val, ind
    while (!pq.empty()) {
        pll current = pq.top();
        pq.pop();
        for (int i = 0; i < n; i++) {
            int node = adjMatrix[current.second][i];
            if (node > 0 && current.first + node < nodes[i]) {
                nodes[i] = current.first + node;
                pq.push(make_pair(nodes[i], i));
            }
        }
    }
    for (auto &x : nodes) {
        if (x == 1e9) {
            cout << "-1\n"; return 0;
        }
    }
    cout << *(max_element(nodes.begin(), nodes.end())) << "\n";
}