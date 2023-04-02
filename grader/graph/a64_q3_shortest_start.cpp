#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k, finish;
    cin >> n >> m >> k >> finish;
    vector<ll> start_node(k);
    vector<vector<pll> > vl(n);
    for (int i = 0; i < k; i++) cin >> start_node[i];
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        vl[a].push_back(make_pair(w, b));
    }
    vector<ll> nodes(n, INT_MAX);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(0, start_node[i])); // val, ind
        nodes[start_node[i]] = 0;
    }
    while (!pq.empty()) {
        pll current = pq.top();
        pq.pop();
        for (auto &x : vl[current.second]) {
            ll weight = x.first;
            ll node = x.second;
            if (weight + current.first < nodes[node]) {
                nodes[node] = weight + current.first;
                pq.push(make_pair(nodes[node], node));
            }
        }
    }
    cout << nodes[finish] << "\n";
}