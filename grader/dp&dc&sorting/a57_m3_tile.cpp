#include<iostream>
#include<vector>
#include<limits.h>

#define ll long long

using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> store(N), dp(N, INT_MAX);
    for (int i = 0; i < N; i++) {
        cin >> store[i];
    }
    
}