#include<iostream>
#include<vector>
#define ll long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> fiboStore(n + 1);
    fiboStore[0] = 0; fiboStore[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        fiboStore[i] = fiboStore[i - 1] + fiboStore[i - 2];
    }
    cout << fiboStore[n] << "\n";
}