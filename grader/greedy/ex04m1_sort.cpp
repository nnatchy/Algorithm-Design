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

ll ans = 0;

int main() {
    ll n;
    cin >> n;
    vector<ll> store(n);
    vector<ll> track(4, 0);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
        track[store[i]]++;
    }
    int cnt = 0;
    int j = track[1];
    for (int i = 0; i < track[1]; i++) {
        if (store[i] == 2) {
            while (j < n && store[j] != 1) j++;
            cnt++;
            swap(store[i], store[j]);
        }
    }
    for (int i = 0; i < track[1]; i++) {
        if (store[i] == 3) {
            while (j < n && store[j] != 1) j++;
            cnt++;
            swap(store[i], store[j]);
        }
    }
    for (int i = track[1]; i < track[1] + track[2]; i++) {
        if (store[i] == 3) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}