#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> serverHacked(k);
    for (int i = 0; i < k; i++) {
        cin >> serverHacked[i];
    }
    vector<ll> c(n), nodes(n, 1e9);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<ll> > adjMatrix(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        nodes[serverHacked[i]] = c[serverHacked[i]];
        pq.push(make_pair(c[serverHacked[i]], serverHacked[i]));
    }
    while (!pq.empty()) {
        pll current = pq.top();
        pq.pop();
        for (auto &x : adjMatrix[current.second]) {
            if (current.first + c[x] < nodes[x]) {
                nodes[x] = current.first + c[x];
                pq.push(make_pair(nodes[x], x));
            }
        }
    }
    cout << *(max_element(nodes.begin(), nodes.end())) << "\n";
}