#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<numeric>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>
#define minHeap priority_queue<pll, vector<ll>, greater<pll> >;
#define minHeapTuple priority_queue<lll, vector<lll>, greater<lll> >;
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main() {
    IO;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> serverHacked(k);
    vector<ll> nodes(n, INT_MAX);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for (int i = 0; i < k; i++) {
        cin >> serverHacked[i];
    }
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<ll> > vl(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        vl[a].push_back(b);
        vl[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(c[serverHacked[i]], serverHacked[i]));
        nodes[serverHacked[i]] = c[serverHacked[i]];
    }
    while (!pq.empty()) {
        pll current = pq.top();
        pq.pop();
        ll val = current.first;
        ll pos = current.second;
        for (auto &x : vl[pos]) {
            if (val + c[x] < nodes[x]) {
                nodes[x] = val + c[x];
                pq.push(make_pair(nodes[x], x));
            }
        }
    }
    // for (auto &x : nodes) cout << x << " ";
    // cout << "\n";
    cout << *max_element(nodes.begin(), nodes.end()) << "\n";
}