#include<iostream>
#include<vector>
#include<stack>
#include<queue>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, e, k;
    cin >> n >> e >> k;
    vector<vector<ll> > adjMatrix(n + 1);
    for (int i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    ll cnt = 0;
    queue<pll> q;
    q.push(make_pair(0, 0));
    vector<ll> visited(n + 1);
    while (!q.empty()) {
        pll current = q.front();
        q.pop();
        if (visited[current.first]) continue;
        visited[current.first] = 1;
        if (current.second == k) cnt++;
        else if (current.second > k) break;
        for (auto &x : adjMatrix[current.first]) {
            if (!visited[x]) q.push(make_pair(x, current.second + 1));
        }
    }
    cout << cnt << "\n";
}