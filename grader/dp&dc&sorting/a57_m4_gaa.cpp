#include<iostream>

#define ll long long int

using namespace std;

ll len(ll n) {
    if (!n) return 3;
    return 2 * len(n - 1) + (n + 3); 
}

char sol(ll N, ll k) {
    if (N <= 3) return N % 3 == 1 ? 'g' : 'a';
    if (N > len(k)) return sol(N, k + 1);
    if (N == len(k - 1)) return sol(N, k - 1);
    N = N - len(k - 1); // delete front
    if (N <= k + 3) return (N == 1) ? 'g' : 'a'; // check mid
    N = N - (k + 3); 
    return sol(N, k-1); // check last
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    cout << sol(N, 0) << "\n";
}