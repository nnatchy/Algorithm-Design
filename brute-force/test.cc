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

// void gen(int n, int k, vector<bool> &used, int len, int chosen) {
//     if (len < n) {
//         if (len - chosen < n - k) {
//             used[len] = false;
//             gen(v, n, k, used, len + 1, chosen);
//         }
//         if (chosen < n) {
//             used[len] = true;
//             gen(v, n, k, used, len + 1, chosen + 1);
//         }
//     } else {
//         vector<int> store; int sum = 0;
//         for (int i = 0; i < used.size(); i++) {
//             if (used[i]) {
//                 sum += i + 1;
//                 store.push_back(i + 1);
//             }
//         }
//         if (sum == n) {
//             for (int i = 0; i < store.size(); i++) {
//                 cout << store[i] << " ";
//             }
//             cout << "\n";
//         }
//         return;
//     }
// }
void gen(vector<vector<int> > &sol, vector<int>& tmp, int n, int k, int len, int chosen) {
        if (len < n) {
            if (len - chosen < n - k) {
                tmp[len] = 0;
                gen(sol, tmp, n, k, len + 1, chosen);
            }
            if (chosen < k) {
                tmp[len] = 1;
                gen(sol, tmp, n, k, len + 1, chosen + 1);
            }
        } else {
            vector<int> store; int sum = 0;
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] == 1) {
                    store.push_back(i + 1);
                    sum += i + 1;
                }
            }
            sol.push_back(store);
        }
    }

int main() {
    // n = m, k = n;
    int n, k;
    cin >> k >> n;
    vector<vector<int> > sol;
    vector<int> used(n);
    gen(sol, used, n, k, 0, 0);
    for (auto &v : sol) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}

