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
    vector<ll> nodes(n, INT_MAX);
    for (int i = 2; i < n; i++) {
        ll cntRoad;
        cin >> cntRoad;
        vector<bool> flag(n);
        for (int j = 0; j < cntRoad; j++) {
            ll connectRoad, cost;
            cin >> connectRoad >> cost;
            c[i].push_back(make_pair(connectRoad, cost));
        }
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        pq.push(make_pair(0, 0)); // val, ind
        nodes[0] = 0;
        while (!pq.empty()) {
            pll current = pq.top();
            pq.pop();
            ll val = current.first;
            ll pos = current.second;
            for (auto &x : c[pos]) {
                if (val + x.second < nodes[x.first]) {
                    nodes[x.first] = val + x.second;
                    pq.push(make_pair(nodes[x.first], x.first));
                }
            }
        }
        cout << nodes[1] << " ";
    }
    cout << "\n";
}