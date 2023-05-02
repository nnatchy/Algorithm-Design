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

void solve(ll step, vector<bool> &visited, vector<bool> &gotSet, ll currSum, ll ub) {
    if (step >= k) {
        if (accumulate(gotSet.begin(), gotSet.end(), 0LL) == n) {
            ans = min(ans, currSum);
        }
        return;
    }
    if (currSum >= ans) return;
    for (int i = step; i < k; i++) {
        for (auto &x : vl[step]) {
            gotSet[x] = true;
        }
        solve(i + 1, visited, gotSet, currSum + P[step], ub);
        for (auto &x : vl[step]) {
            gotSet[x] = false;
        }
        solve(i + 1, visited, gotSet, currSum, ub);
    }
}

int main()
{
    IO;
    cin >> n >> k;
    bestFit.resize(n);
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
    vector<bool> gotSet(n);
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
*/