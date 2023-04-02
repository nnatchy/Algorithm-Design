#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<numeric>
#include<limits.h>
#include<tuple>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main() {
    IO;
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<pll> > vl(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        vl[a].push_back(make_pair(b, c)); // pos, val
    }
    vector<ll> nodes(N, INT_MAX);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(make_pair(0, 0)); // val, ind
    nodes[0] = 0;
    while (!pq.empty()) {
        pll current = pq.top();
        pq.pop();
        ll val = current.first;
        ll pos = current.second;
        for (auto &x: vl[pos]) {
            ll cost = x.second;
            ll newPos = x.first;
            if (cost + nodes[pos] < nodes[newPos]) {
                nodes[newPos] = cost + nodes[pos];
                pq.push(make_pair(nodes[newPos], newPos));
            }
        }
    }
    while (Q--) {
        ll q;
        cin >> q;
    }
    for (auto &x : nodes) cout << x << " ";
    cout << "\n";
}