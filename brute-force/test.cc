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

int bs(vector<int> &dp, int target) {
    int start = 0;
    int stop = dp.size();
    while (start < stop) {
        int mid = start + (stop - start) / 2;
        if (target <= dp[mid]) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }
    return dp[start] == target ? start : -1;
}

int missing(vector<int> &dp) {
    int start = 0;
    int stop = dp.size();
    while (start < stop) {
        int mid = start + (stop - start) / 2;
        if (mid < dp[mid]) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int peakDetect(vector<int> &dp, int left, int right) {
    int n = dp.size();
    if (right - left == 2) return dp[left + 1];
    int mid = left + (right - left) / 2;
    if (mid - 1 >= 0 && mid + 1 < n && dp[mid] > dp[mid - 1] && dp[mid] > dp[mid + 1]) return dp[mid];
    if (dp[mid] > dp[mid - 1]) return peakDetect(dp, mid, right);
    else return peakDetect(dp, left, mid);
}

int peak(vector<int> &dp) {
    int start = 0;
    int n = dp.size();
    int stop = dp.size();
    int ans = 0;
    while (start < stop) {
        int mid = start + (stop - start) / 2;
        if (mid - 1 >= 0 && mid + 1 <= n - 1) {
            if (dp[mid] >= dp[mid + 1] && dp[mid] >= dp[mid - 1]) {
                start = mid;
                break;
            }
        }
        if (mid + 1 <= n - 1 && dp[mid] <= dp[mid + 1]) {
            start = mid;
        } else {
            stop = mid - 1;
        }
    }
    return dp[start];
}

int max_3(vector<int> &dp) {

}

int main() {
    vector<int> dp;
    int n = 10;
    int start = 0;
    for (int i = 0; i < n; i++) {
        ll inp;
        cin >> inp;
        dp.push_back(inp);
    }
    // int target;
    // cin >> target;
    cout << peakDetect(dp, 0, n) << '\n';
}

