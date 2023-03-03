#include<iostream>
#include<vector>

#define ll long long

using namespace std;

ll dp[1100][1100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, M, K;
    cin >> N >> M >> K;
    ll store[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> store[i][j];
        }
    }
    dp[1][1] = store[0][0];
    for (int j = 2; j < M + 1; j++) {
        dp[1][j] = dp[1][j - 1] + store[0][j - 1];
    }
    for (int i = 2; i < N + 1; i++) {
        dp[i][1] = dp[i - 1][1] + store[i - 1][0];
        for (int j = 2; j < M + 1; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + store[i - 1][j - 1];
        }
    }
    while (K--) {
        ll r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1++; c1++; r2++; c2++;
        cout << dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1] << "\n";
    }
}