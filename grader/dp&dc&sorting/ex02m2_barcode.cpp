#include<iostream>

#define ll long long

ll dp[31][2][31][31];

using namespace std;

ll solve(ll pos, ll colour, ll sameColour, ll countK, ll &N, ll &M, ll &K) {
    if (sameColour >= M || countK > K) return 0;
    if (dp[pos][colour][sameColour][countK] != 0) return dp[pos][colour][sameColour][countK];
    if (pos == N - 1) {
        if (countK == K) return 1;
        else return 0;
    }
    if (colour) {
        int val = solve(pos + 1, 1, sameColour + 1, countK, N, M, K) + solve(pos + 1, 0, 0, countK + 1, N, M, K);
        dp[pos][colour][sameColour][countK] = val;
        return val;
    } else {
        int val = solve(pos + 1, 1, 0, countK + 1, N, M, K) + solve(pos + 1, 0, sameColour + 1, countK, N, M, K);
        dp[pos][colour][sameColour][countK] = val;
        return val;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, M, K;
    cin >> N >> M >> K;
    cout << solve(0, 1, 0, 0, N, M, K) << "\n";
}