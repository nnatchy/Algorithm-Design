#include<iostream>
#include<queue>
#include<stack>
#include<vector>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, m, k;
    ll sum = 0;
    cin >> n >> m >> k;
    vector<ll> b(n), fireStart(k);
    for (int i = 0; i < n; i++) {
        cin >> b[i]; 
        sum += b[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> fireStart[i];
    }
    vector<vector<ll> > vl(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        vl[a].push_back(b);
    }
    vector<bool> visited(n);
    for (int i = 0; i < k; i++) {
        ll node = fireStart[i];
        stack<ll> st;
        st.push(node);
        while (!st.empty()) {
            ll current = st.top();
            st.pop();
            if (visited[current]) continue;
            visited[current] = true;
            sum -= b[current];
            for (auto &x : vl[current]) {
                if (!visited[x]) {
                    st.push(x);
                }
            }
        }
        cout << sum << " ";
    }
    cout << "\n";
}

/*
4 3 3
10 20 30 40
2 1 0
0 1
1 2
2 3
*/