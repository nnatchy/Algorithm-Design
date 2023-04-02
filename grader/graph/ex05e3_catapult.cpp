#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

vector<vector<ll> > vl;
vector<ll> visited, order;

// SCC

void test() {
    for (int i = 0 ; i < vl.size(); i++) {
        for (int j = 0; j < vl[i].size(); j++) {
            cout << vl[i][j] << " ";
        }
        cout << "\n";
    }
}

void topoSort(ll node, ll cnt) {
    visited[node] = 1;
    bool check = false;
    for (auto &x : vl[node]) {
        if (!visited[x]) {
            check = true;
            topoSort(x, cnt + 1);
        }
    }
    if (!check) order.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    visited.resize(N); vl.resize(N);
    for (int i = 0; i < N; i++) {
        ll M, inp;
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> inp;
            vl[i].push_back(inp);
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topoSort(i, 1);
        }
    }
    sort(order.begin(), order.end());
    for (auto &ord : order) cout << ord << " ";
    cout << "\n";
}