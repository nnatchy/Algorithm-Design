#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<cmath>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int n;
int cnt = 0;

bool check(int row, int colTmp, vector<int> &col) {
    for (int i = 0; i < row; i++) {
        int considerRow = i;
        int checkCol = col[i];
        if (checkCol == colTmp || abs(checkCol - colTmp) == row - considerRow) return false;
    }
    return true;
}

void e_queen(int step, vector<int> &col, vector<bool> &used) {
    if (step < n) {
        for (int i = 0; i < n; i++) {
            if (!used[i] && check(step, i, col)) {
                used[i] = true;
                col[step] = i;
                e_queen(step + 1, col, used);
                used[i] = false;
            }
        }
    } else {
        cnt++;
    }
}

using namespace std;

int main() {
    cin >> n;
    vector<int> col(n); vector<bool> used(n);
    e_queen(0, col, used);
    cout << cnt << "\n";
}