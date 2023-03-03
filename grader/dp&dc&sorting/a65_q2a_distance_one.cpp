#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<cmath>

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define matrix vector<vector<ll>>
#define mod 100000007;

using namespace std;

long long dp[5010][5010];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    dp[2][1] = 3;
    dp[3][2] = 5;
    for (int j = 1; j <= k; j++) {
        dp[1][j] = 2;
    }
    for (int i = 3; i <= n; i++) {
        dp[i][1] = (long long) pow(2, i) % mod;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i <= j) {
                dp[i][j] = (i + 1) % mod;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i - j][j]) % mod;
            }
        }
    }
    cout << dp[n][k] << "\n";
}