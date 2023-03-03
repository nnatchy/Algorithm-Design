#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define ll long long int

ll gen(ll start, ll stop, ll A, ll B, vector<ll> &v) {
    // B * avengerCnt * length of V or A when there is no avenger in the area
    ll mid = (start + stop) / 2;
    ll avengerCnt = lower_bound(v.begin(), v.end(), stop) - lower_bound(v.begin(), v.end(), start);
    if (!avengerCnt) return A;
    else if (stop - start <= 1) return B * avengerCnt * 1;
    else return min((B * avengerCnt * (stop - start)), gen(start, mid, A, B, v) + gen(mid, stop, A, B, v));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll p, k, A, B;
    cin >> p >> k >> A >> B;
    vector<ll> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
        v[i]--;
    }
    std::sort(v.begin(), v.end());
    cout << gen(0, 1 << p, A, B, v) << '\n';
}