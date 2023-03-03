#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int

using namespace std;

int main() {
    ll N, inp;
    cin >> N;
    vector<ll> dp;
    dp.push_back(1); dp.push_back(3);
    while (N--) {
        cin >> inp;
        while (inp > dp.back()) {
            ll endPoint = lower_bound(dp.begin(), dp.end(), dp.size() + 1) - dp.begin() + 1;
            dp.push_back(dp.back() + endPoint);
        }
        int ans = lower_bound(dp.begin(), dp.end(), inp) - dp.begin() + 1;
        cout << ans << "\n";
    }
}