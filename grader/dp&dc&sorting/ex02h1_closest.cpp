#include<iostream>
#include<vector>

#define ll long long
#define pll pair<ll,ll>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pll> store;
    while (N--) {
        ll x, y;
        cin >> x >> y;
        store.push_back(make_pair(x, y));
    }
    
}