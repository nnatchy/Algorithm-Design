#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> store(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> store[i];
    }
    ll start = 0, stop = 0, curSum = store[0], maxSum1 = store[0];
    bool check = true;
    for (int i = 1; i < N; i++) {
        if (store[i] > curSum + store[i]) {
            curSum = store[i];
            start = i;
            check = false;
        } else {
            curSum = curSum + store[i];
        }
        if (curSum >= maxSum1) {
            stop = i;
            maxSum1 = curSum;
        }
    }
    if (check) {
        cout << maxSum1 << "\n";
        return 0;
    }
    ll maxSum2 = store[0];
    curSum = store[0];
    for (int i = 1; i < start; i++) {
        curSum = max(curSum, curSum + store[i]);
        maxSum2 = max(maxSum2, curSum);
    }
    ll maxSum3 = -1;
    if (stop + 1 < N) {
        maxSum3 = store[stop + 1];
        curSum = store[stop + 1];
        for (int i = stop + 1; i < N; i++) {
            curSum = max(curSum, curSum + store[i]);
            maxSum3 = max(curSum, maxSum3);
        }
        maxSum2 = max(maxSum2, maxSum3);
    }
    cout << max(maxSum1, maxSum1 + maxSum2) << "\n";
}
