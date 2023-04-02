#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<numeric>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>
#define lll tuple<ll, ll, ll>
#define minHeap priority_queue<pll, vector<ll>, greater<pll> >;
#define minHeapTuple priority_queue<lll, vector<lll>, greater<lll> >;
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<ll> depth, visited;
vector<vector<ll> > adjMatrix;

// void dfs(ll node, ll parent, ll distance) {
//     if (visited[node]) {
//         cout << distance - depth[node] << "\n";
//         exit(0);
//     }
//     visited[node] = 1;
//     depth[node] = distance;
//     for (auto &x : adjMatrix[node]) {
//         if (x != parent) {
//             dfs(x, node, distance + 1);
//         }
//     }
// }

int main() {
    IO;
    ll n;
    cin >> n;
    adjMatrix.resize(n); depth.resize(n); visited.resize(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n);
        stack<pll> st;
        vector<ll> distance(n, 1);
        st.push(make_pair(i, -1)); // current, parent
        while (!st.empty()) {
            pll current = st.top();
            st.pop();
            ll parent = current.second;
            ll node = current.first;
            if (visited[node]) {
                cout << distance[parent] + distance[node] - 1 << "\n";
                exit(0);
            }
            visited[node] = true;
            distance[node] = distance[parent] + 1;
            for (auto &x : adjMatrix[node]) {
                if (x != parent) {
                    st.push(make_pair(x, node));
                }
            }
        }
    }
}