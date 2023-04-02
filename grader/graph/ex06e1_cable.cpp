#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<numeric>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

// PRIM

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    vector<vector<ll> > vl(N, vector<ll>(N, -1)); 
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ll inp;
            cin >> inp;
            vl[i][j] = vl[j][i] = inp;
        }
    }
    priority_queue<pll, vector<pll>, greater<pll> > minHeap;
    vector<ll> nodes(N, INT_MAX);
    vector<bool> inMST(N, false);
    nodes[0] = 0;
    minHeap.push(make_pair(0, 0)); // val, ind
    while (!minHeap.empty()) {
        pll current = minHeap.top();
        ll pos = current.second;
        minHeap.pop();
        inMST[pos] = 1;
        for (int i = 0; i < N; i++) {
            if (vl[pos][i] == -1) continue;
            if (!(inMST[i]) && (vl[pos][i] < nodes[i])) {
                nodes[i] = vl[pos][i];
                minHeap.push(make_pair(nodes[i], i));
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (nodes[i] != INT_MAX) sum += nodes[i];
    }
    cout << sum << "\n";
}