#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>

#define ll long long
#define mod 100000007
#define SIZE 10010

using namespace std;

ll dp[SIZE];

/*
lazy do bonus
*/

int main() {
    ll N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= N; i++) {
        if (i == 3) dp[i] = (dp[i - 1] + dp[i - 2]) + dp[i - 3];
        else {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 4]) % mod;
        }
    }
    cout << dp[N] << "\n";
}