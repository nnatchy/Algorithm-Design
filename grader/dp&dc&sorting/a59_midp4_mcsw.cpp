#include<iostream>
#include<vector>
#include<deque>
#include<limits.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, w; 
    cin >> n >> w;
    vector<ll> store(n), dp(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
        dp[i + 1] = dp[i] + store[i];
    }
    deque<ll> dq; dq.push_back(0);
    ll mx = INT_MIN;
    for (int i = 1; i < n; i++) {
        while (!dq.empty() && i - dq.front() > w) { // ระยะ
            printf("i check range: %d\n", i);
            dq.pop_front(); 
        }
        mx = max(mx, dp[i] - dp[dq.front()]); // find maximum of each window
        while (!dq.empty() && dp[dq.back()] > dp[i]) {
            printf("i: %d\n", i);
            printf("---------\n");
            printf("store[dq.back()]: %d\t store[i]: %d\n", store[dq.back()], store[i]);
            printf("dp[dq.back()]: %d\t dp[i]: %d\n", dp[dq.back()], dp[i]);
            printf("---------\n");
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << mx << "\n";
}
