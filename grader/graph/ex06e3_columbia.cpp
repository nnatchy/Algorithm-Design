#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<numeric>
#include<tuple>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

// DIJKSTRA

int main() {
    ll r, c;
    cin >> r >> c;
    vector<vector<ll> > vl(r, vector<ll>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> vl[i][j];
        }
    }
 
    priority_queue<lll, vector<lll>, greater<lll> > minHeap;
    vector<vector<ll> > nodes(r, vector<ll>(c, 1e9));
    minHeap.push(tuple(0, 0, 0)); // r, c
    ll dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
    vl[0][0] = 0;
    nodes[0][0] = 0;
    while (!minHeap.empty()) {
        auto [val, rTmp, cTmp] = minHeap.top();
        minHeap.pop();
        for (int i = 0; i < 4; i++) {
            ll rr = rTmp + dr[i];
            ll cc = cTmp + dc[i];
            if (rr < 0 || rr >= r || cc < 0 || cc >= c) continue;
            if (vl[rr][cc] + val < nodes[rr][cc]) {
                nodes[rr][cc] = vl[rr][cc] + val;
                minHeap.push(tuple(nodes[rr][cc], rr, cc));
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << nodes[i][j] << " ";
        }
        cout << "\n";
    }

}