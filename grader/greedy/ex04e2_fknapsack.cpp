#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<iomanip>

#define ll long double
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define rep(a, b) for(int i = a; i < b; i++)
#define pll pair<ll, ll>
#define ppl pair<ll, pll>

using namespace std;

int main() {
    IO;
    ll w, n;
    cin >> w >> n;
    vector<ppl> vpl(n);
    for (int i = 0; i < n; i++) cin >> vpl[i].second.first; // v
    for (int i = 0; i < n; i++) {
        cin >> vpl[i].second.second; // w
    }
    for (int i = 0; i < n; i++) {
        vpl[i].first = vpl[i].second.first / vpl[i].second.second;
    }
    sort(vpl.begin(), vpl.end(), greater<ppl>());
    ll sumW = 0;
    ll sumV = 0;
    ll pos = 0;
    while (pos < n && sumW <= w) {
        if (vpl[pos].second.second <= w - sumW) {
            sumV += vpl[pos].second.first;
            sumW += vpl[pos].second.second;
            pos++;
        } else {
            sumV += vpl[pos].second.first * ((double) (w - sumW) / vpl[pos].second.second);
            break;
        }
    }
    cout << fixed << setprecision(4) << sumV << "\n";
}