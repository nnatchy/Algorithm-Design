#include<iostream>
#include<queue>
#include<stack>
#include<vector>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

// DFS

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll v, e;
    cin >> v >> e;
    vector<vector<ll> > adjMatrix(v);
    for (int i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    ll cnt = 0;
    vector<ll> visited(v);
    for (int i = 0; i < v; i++) {
        if (visited[i] == 2) continue;  
        stack<pll> st;
        st.push(make_pair(i, -1));
        visited[i] = 1;
        bool check = true;
        while (!st.empty()) {
            pll current = st.top();
            st.pop();
            if (adjMatrix[current.first].size() > 1 + (current.second != -1)) {
                check = false;
                break;
            } else {
                visited[current.first] = 2;
            }
            for (ll &x : adjMatrix[current.first]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    st.push(make_pair(x, current.first));
                }
            }
        }
        for (auto &x : visited) {
            if (x != 2) x = 0;
        }
        cnt += check;
    }
    cout << cnt << "\n";
}