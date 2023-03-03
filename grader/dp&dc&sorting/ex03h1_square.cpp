#include<iostream>

#define ll long long

using namespace std;

ll dp[1100][1100];

int main() {
    ll R, C;
    cin >> R >> C;
    for (int i = 1; i < R + 1; i++) {
        string inp;
        cin >> inp;
        for (int j = 1; j < C + 1; j++) {
            dp[i][j] = inp[j - 1] - '0';
        }
    }
    ll maxSquare = -1;
    for (int i = 1; i < R + 1; i++) {
        for (int j = 1; j < C + 1; j++) {
            if (dp[i][j] != 0) {
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                maxSquare = dp[i][j] > maxSquare ? dp[i][j] : maxSquare;
            }
        }
    }
    cout << maxSquare << "\n";
}