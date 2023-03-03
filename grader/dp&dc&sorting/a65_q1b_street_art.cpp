#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

ll compute(ll b, ll c, vector<ll> &Y) {
    auto it1 = lower_bound(Y.begin(), Y.end(), b);
    auto it2 = upper_bound(Y.begin(), Y.end(), c);
    return it2 - it1;
}

ll DC(vector<ll> &Y, ll a, ll b, ll c) {
    if (c - b + 1 < 3) {
        return compute(b, c, Y);
    } else {
        if (compute(b, c, Y) == 0) return 0;
        ll u = (c - b + 1) / 3;
        ll v = (c - b + 2) / 3;
        ll r1 = DC(Y, 0, b, b + u - 1);
        ll r2 = DC(Y, 0, b + u, b + u + v - 1);
        ll r3 = DC(Y, 0, b + u + v, c);
        ll notChosen = min(min(r1, r2), r3);
        return compute(b, c, Y) + r1 + r2 + r3 - notChosen;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll W, N;
    cin >> W >> N;
    vector<ll> Y(N);
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    sort(Y.begin(), Y.end());
    ll ans = DC(Y, 0, 1, W);
    cout << ans << "\n";
}