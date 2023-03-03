#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

#define ll long long int
#define pii pair<ll,ll>

using namespace std;

int lb(vector<int> &dp, int target, int n) {
    int start = 0;
    int stop = n;
    while (start < stop) {
        int mid = start + (stop - start) / 2;
        if (target <= dp[mid]) stop = mid;
        else start = mid + 1;
    }
    return start;
}

int main() {
    vector<int> dp;
    int n = 6;
    int start = 0;
    for (int i = 0; i < n; i++) {
        ll inp;
        cin >> inp;
        dp.push_back(inp);
    }
    int firstIdx = lb(dp, 1, n);
    int secondIdx = lb(dp, 2, n);
    cout << secondIdx - firstIdx << '\n';
}

