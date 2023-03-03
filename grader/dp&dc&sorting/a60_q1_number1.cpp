#include<iostream>
#include<cmath>
#include<vector>

#define ll long long int

using namespace std;

void DC(ll &ans, ll n, ll &l, ll &r, ll curL, ll curR) {
    if (!n || curL > r || curR < l) return;
    if (n == 1) {
        ans++;
        return;
    }
    ll mid = (curL + curR) / 2;
    DC(ans, n / 2, l, r, curL, mid - 1);
    DC(ans, n % 2, l, r, mid, mid);
    DC(ans, n / 2, l, r, mid + 1, curR);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, l, r, vsize, ans = 0;
    cin >> n >> l >> r;
    vsize = n;
    ll tmp = 1;
    while (vsize > 1) {
        vsize /= 2;
        tmp = tmp * 2 + 1;
    }
    DC(ans, n, l, r, 1, tmp);
    cout << ans << "\n";
}