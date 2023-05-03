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
vector<vector<ll> > vl, bookOwner;
vector<ll> gotSet;
vector<ll> P; // cost set
ll ans = 1e9;

void solve(ll step, ll currSum) {
    if (currSum >= ans) return;
    if (step == n) { // got all books
        ans = min(ans, currSum);
        return;
    }
    if (gotSet[step]) { // alr have book
        solve(step + 1, currSum);
        return;
    } 
    for (auto &w : bookOwner[step]) {
        if (P[w] + currSum >= ans) continue;
        for (auto &x : vl[w]) {
            gotSet[x]++;
        }
        solve(step + 1, currSum + P[w]);
        for (auto &x : vl[w]) {
            gotSet[x]--;
        }
    }
}

int main()
{
    IO;
    cin >> n >> k;
    bookOwner.resize(n);
    vl.resize(n);
    gotSet.resize(n, 0);
    P.resize(n, 0);
    for (int j = 0; j < k; j++) {
        ll cnt;
        cin >> P[j] >> cnt;
        while (cnt--) {
            ll a;
            cin >> a;
            a--;
            vl[j].push_back(a);
            bookOwner[a].push_back(j);
        }
    }
    solve(0, 0);
    cout << ans << "\n";
}