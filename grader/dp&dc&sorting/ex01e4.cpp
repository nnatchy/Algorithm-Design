#include<iostream>
#define ll long long int
using namespace std;

ll mod_expo(ll X, ll N, ll K) {
    if (N == 1) return X % K;
    if (N % 2 == 0) {
        ll tmp = mod_expo(X, N / 2, K);
        return (tmp * tmp) % K;
    } else {
        ll tmp = mod_expo(X, N / 2, K);
        tmp = tmp * tmp;
        return ((tmp % K) * (X % K)) % K;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll X, N, K;
    cin >> X >> N >> K;
    ll result = mod_expo(X, N, K);
    cout << result << "\n";
}