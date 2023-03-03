#include<iostream>
#include<vector>
#include<limits.h>

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
    ll tmpStart = 0, tmpStop = start - 1;
    for (int i = 1; i < start; i++) {
        if (store[i] >= curSum + store[i]) {
            tmpStart = i;
        }
        max(store[i], curSum + store[i]);
        if (curSum >= maxSum2) {
            tmpStop = i;
        }
        maxSum2 = max(maxSum2, curSum);
    }
    if (start - tmpStop > 2) {
        ll tmpVar = start - tmpStop;
        while (tmpVar > 2) {
            ll plusVal;
            if () {

            }
            maxSum2 += store[++tmpStop];
        }
    }
    ll maxSum3 = INT_MIN;
    if (stop + 1 < N) {
        maxSum3 = store[stop + 1];
        curSum = store[stop + 1];
        int tmp = 1;
        int till = 0;
        bool check = false;
        for (int i = stop + 2; i < N; i++) {
            if (store[i] >= curSum + store[i]) {
                tmp--;
            }
            if (tmp == 0 && i > stop + 2) {
                check = true;
                till = i;
            }
            curSum = max(store[i], curSum + store[i]);
            maxSum3 = max(curSum, maxSum3);
        }
        if (check) {
            int tmpIdx = stop + 2;
            while (tmpIdx < till && tmpIdx < N) {
                maxSum3 += store[tmpIdx++];
            }
        }
        maxSum2 = max(maxSum2, maxSum3);
    }
    // printf("maxSum2: %d\t maxSum3: %d\n", maxSum2, maxSum3);
    cout << max(maxSum1, maxSum1 + maxSum2) << "\n";
}
