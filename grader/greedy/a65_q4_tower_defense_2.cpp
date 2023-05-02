#include<iostream>
#include<vector>
#include<algorithm>

// NOT 100

#define ll long long
#define pll pair<ll, ll>
#define ppl pair<ll, pll>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define lll tuple<ll, ll, ll>

using namespace std;

ll n, m, k, w;

int main()
{
    IO;
    cin >> n >> m >> k >> w;
    vector<ll> p(m);
    vector<ll> h(m);
    vector<pll> a(m);
    for (int i = 0; i < m; i++) {
       cin >> p[i];
       p[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }
    // greedy
    for (int i = 0; i < m; i++) {
      a[i] = make_pair(p[i], h[i]);
    }
    sort(a.begin(), a.end());
    vector<ll> hasUsed(n);
    bool checkK = false;
    for (int i = 0; i < m && k > 0; i++) {
        bool checkH = false;
        ll monsterPos = a[i].first;
        ll monsterHealth = a[i].second;
        if (i != 0 && a[i].first == a[i - 1].first && a[i - 1].second > 0) continue;
        for (int j = 0; j <= w && k > 0 && a[i].second > 0; j++) {
            if (hasUsed[monsterPos - j]) continue; 
            if (monsterPos - j < 0) break;
            if (!hasUsed[monsterPos - j] && a[i].second > 0) {
                a[i].second--;
                k--;
                hasUsed[monsterPos - j] = true;
            }
        }
        for (int j = 0; j <= w && k > 0 && a[i].second > 0; j++) {
            if (hasUsed[monsterPos + j]) continue;
            if (monsterPos + j >= n) break;
            if (!hasUsed[monsterPos + j] && a[i].second > 0) {
                a[i].second--;
                k--;
                hasUsed[monsterPos + j] = true;
            }
        }
    }
    ll sum = 0;
    for (auto &x : a) {
        sum += x.second;
    }
    cout << sum << "\n";
}