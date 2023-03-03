#include<iostream>
#include<vector>

#define ll long long int

using namespace std;

void DC(vector<ll> &ans, vector<ll> &vi, ll left, ll n) {
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> vi(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    vector<ll> ans(n);
    DC(ans, vi, 0, n);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}