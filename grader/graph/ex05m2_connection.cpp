#include<iostream>
#include<vector>
#include<queue>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, E, K;
    cin >> N >> E >> K;
    vector<vector<ll> > adjMat(N);
    while (E--) {
        ll x, y;
        cin >> x >> y;
        adjMat[x].push_back(y);
        adjMat[y].push_back(x);
    }
    ll mx = -1;
    for (int i = 0; i < N; i++) {
        vector<ll> visited(N, 0);
        ll cnt = 0;
        queue<pll> q;   
        q.push(make_pair(i, 0));
        while (!q.empty()) {
            pll current = q.front();
            q.pop();
            if (visited[current.first] ||  current.second > K) continue;
            else {
                cnt++;
                visited[current.first] = 1;
                for (auto &x : adjMat[current.first]) {
                    if (!visited[x]) {
                        q.push(make_pair(x, current.second + 1));
                    }
                }
            }
        }
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
}