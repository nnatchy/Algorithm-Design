#include<iostream>
#include<vector>
#include<queue>
#include<stack>

#define ll long long
#define pll pair<ll,ll>

using namespace std;

// DFS

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll v, e;
    cin >> v >> e;
    vector<vector<ll> > vl(v);
    for (int i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;
        vl[a - 1].push_back(b - 1);
        vl[b - 1].push_back(a - 1);
    }
    ll cnt = 0;
    vector<ll> visited(v);
    for (int i = 0; i < v; i++) {
        if (visited[i]) continue;
        cnt++;
        stack<ll> st;
        st.push(i);
        while (!st.empty()) {
            ll current = st.top();
            st.pop();
            for (auto &x : vl[current]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    st.push(x);
                }
            }
        }
    }
    cout << cnt << "\n";
}