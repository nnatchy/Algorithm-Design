#include<iostream>
#include<vector>

#define ll long long

using namespace std;

// DFS

bool dfs(vector<vector<ll> > &v, vector<ll> &visited, ll current, ll parent) {
    if (visited[current]) return true; // alr visited
    visited[current] = 1; // change value to 1 to show that this vertex is already visied
    for (ll &x : v[current]) {
        if (x != parent && dfs(v, visited, x, current)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll T, N, E;
    cin >> T;
    while (T--) {
        cin >> N >> E;
        vector<vector<ll> > v(N);
        for (int i = 0; i < E; i++) {
            ll ver1, ver2;
            cin >> ver1 >> ver2;
            v[ver1].push_back(ver2);
            v[ver2].push_back(ver1);
        }
        vector<ll> visited(N);
        bool res = false;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dfs(v , visited, i, -1)) {
                res = true;
                break;
            }
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}