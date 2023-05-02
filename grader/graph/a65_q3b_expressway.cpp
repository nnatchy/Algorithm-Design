#include<bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define ppl pair<ll, pll>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define lll tuple<ll, ll, ll>

using namespace std;

int main()
{
    IO;
    ll n, c12;
    cin >> n >> c12;
    vector<vector<pll>> vl(n);
    vl[0].push_back({1, c12});
    vl[1].push_back({0, c12});
    for (int i = 2; i < n; i++) {
        ll cntRoad;
        cin >> cntRoad;
        while (cntRoad--) {
            ll nextNode, w;
            cin >> nextNode >> w;
            nextNode--;
            vl[nextNode].push_back({i, w});
            vl[i].push_back({nextNode, w});
        }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<ll> nodes(n, 1e9);
        pq.push({0, 0}); // val, idx;
        nodes[0] = 0;
        while (!pq.empty()) {
            pll curr = pq.top();
            pq.pop();
            ll val = curr.first;
            ll node = curr.second;
            for (auto &x : vl[node]) {
                ll nextNode = x.first;
                ll weight = x.second;
                if (nodes[node] + weight < nodes[nextNode]) {
                    nodes[nextNode] = nodes[node] + weight;
                    pq.push({nodes[nextNode], nextNode});
                }
            }
        }
        cout << nodes[1] << "\n";
    }
}