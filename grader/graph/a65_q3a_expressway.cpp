#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    IO;
    ll n;
    cin >> n;
    vector<vector<pll> > c(n);
    ll costStart;
    cin >> costStart;
    c[0].push_back(make_pair(1, costStart));
    c[1].push_back(make_pair(0, costStart));
    for (int i = 2; i < n; i++) {
        ll cntRoad;
        cin >> cntRoad;
        vector<bool> flag(n);
        for (int j = 0; j < cntRoad; j++) {
            ll connectRoad, cost;
            cin >> connectRoad >> cost;
            c[i].push_back(make_pair(connectRoad - 1, cost));
            c[connectRoad - 1].push_back(make_pair(i, cost));
        }
        vector<ll> nodes(n, INT_MAX);
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        pq.push(make_pair(0, 0)); // val, ind
        nodes[0] = 0;
        while (!pq.empty()) {
            pll current = pq.top();
            pq.pop();
            ll val = current.first;
            ll pos = current.second;
            for (auto &x : c[pos]) {
                ll newPos = x.first;
                ll hasCost = x.second;
                if (val + hasCost < nodes[newPos]) {
                    nodes[newPos] = val + hasCost;
                    pq.push(make_pair(nodes[newPos], newPos));
                }
            }
        }
        cout << nodes[1] << " ";
    }
    cout << "\n";
}