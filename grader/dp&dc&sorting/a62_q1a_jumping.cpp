#include<iostream>
#include<vector>
#include<limits.h>

#define ll long long

using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> nums(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    vector<ll> dp(1000100, INT_MIN);
    dp[N - 1] = nums[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 1; j <= 3 && i + j < N; j++) {
            dp[i] = max(dp[i], dp[i+j] + nums[i]);
        }
    }
    cout << dp[0] << "\n";
}