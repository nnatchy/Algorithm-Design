// #include<iostream>
// #include<vector>
// #include<queue>
// #include<stack>

// #define ll long long
// #define pll pair<ll, ll>

// using namespace std;

// vector<vector<ll> > vl, ord;
// vector<ll> visited;

// void dfs(ll node) {
//     visited[node] = 1;
//     for (auto &x : vl[node]) {
//         if (!visited[x]) {
//             dfs(x);
//         }
//     }

// }

// int main() {
//     ll N, P;
//     cin >> N >> P;
//     vl.resize(N); visited.resize(N); ord.resize(N);
//     for (int i = 0; i < P; i++) {
//         ll A, B;
//         cin >> A >> B;
//         vl[A].push_back(B);
//     }
//     for (int i = 0; i < N; i++) {
//         if (!visited[i]) {
//             dfs(i);
//         }
//     }
//     for (auto &x : ord) {
//         if (x.empty()) exit(0);
//         cout << x.size() << " ";
//     }
//     cout << "\n";
// }