#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

#define ll long long
#define pll pair<ll, ll>
#define ppl pair<ll, pll>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define lll tuple<ll, ll, ll>

using namespace std;

ll n, k;
vector<vector<ll> > vl;
vector<ll> bestFit;
vector<ll> P; // cost set
ll ans = 1e9;

void solve(ll step, vector<bool> &visited, vector<ll> &gotSet, ll currSum, ll ub) {
    if (currSum >= ans) return;
    if (step >= k) {
        for (auto &x : gotSet) {
            if (!x) return;
        }
        ans = min(ans, currSum);
        return;
    }
    solve(step + 1, visited, gotSet, currSum, ub);
    for (auto &x : vl[step]) {
        gotSet[x] = true;
    }
    solve(step + 1, visited, gotSet, currSum + P[step], ub);
    for (auto &x : vl[step]) {
        gotSet[x] = false;
    }
    
}

int main()
{
    IO;
    cin >> n >> k;
    bestFit.resize(k);
    vl.resize(n);
    P.resize(k);
    for (int j = 0; j < k; j++) {
        ll cnt;
        cin >> P[j] >> cnt;
        while (cnt--) {
            ll a;
            cin >> a;
            a--;
            vl[j].push_back(a);
        }
        bestFit[j] = max(bestFit[j], P[j]);
    }
    ll ub = 0;
    for (auto &x : bestFit) ub += x;
    vector<bool> visited(n);
    vector<ll> gotSet(n, 0);
    solve(0, visited, gotSet, 0, ub);
    cout << ans << "\n";
}

/*
4 3
10 3 1 2 3
30 2 1 4
20 2 3 4

7 8
54 3 2 7 1
52 1 6
2 3 1 4 6
100 3 2 4 7
62 2 6 1
88 2 6 3
38 1 7
26 3 3 5 7

20 11
91 4 17 19 8 14
85 4 7 9 15 2
74 9 13 16 18 3 9 10 2 4 1
40 3 2 5 6
62 9 1 16 5 8 2 20 14 10 3
14 10 10 12 14 3 19 2 9 6 11 4
83 6 6 1 10 16 2 15
99 7 4 8 15 7 17 19 10
41 5 3 8 11 12 18
18 9 18 14 13 12 19 2 5 1 6
94 9 4 14 20 5 3 2 15 10 19
*/