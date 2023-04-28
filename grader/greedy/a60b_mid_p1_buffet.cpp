#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<numeric>

#define ll long long
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define pll pair<ll, ll>
#define ppl pair<ll, pll>

using namespace std;

int main() {
    IO;
    ll f, w, n;
    cin >> f >> w >> n;
    vector<ll> food(f);
    for (int i = 0; i < f; i++) cin >> food[i];
    sort(food.begin(), food.end());
    ll pos = 0;
    ll cnt = 0;
    for (auto &idx : food) {
        if (pos < idx) {
            cnt++;
            pos = idx + w + w;
        }
    }
    cout << cnt << '\n';
}