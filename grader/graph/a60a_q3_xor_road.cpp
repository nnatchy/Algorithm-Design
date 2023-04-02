#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<limits.h>
#include<numeric>

#define ll unsigned long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> vl(n);
    for (int i = 0; i < n; i++) {
        cin >> vl[i];
    }
    vector<bool> inMST(n);
    priority_queue<pll> maxHeap;
    vector<ll> nodes(n, 0);
    maxHeap.push(make_pair(0, 0)); // value, ind
    while (!maxHeap.empty()) {
        pair<ll, ll> current = maxHeap.top();
        ll val = current.first;
        ll pos = current.second;
        maxHeap.pop();
        inMST[pos] = true;
        for (int i = 0; i < n; ++i) {
            if (!inMST[i] && (vl[i] ^ vl[pos]) > nodes[i]) {
                nodes[i] = vl[i] ^ vl[pos];
                maxHeap.push(make_pair(nodes[i], i));
            }
        }

    }
    cout << accumulate(nodes.begin(), nodes.end(), 0UL) << "\n";
}