#include<iostream>
#include<vector>

#define ll long long int

using namespace std;
bool findTripleSum(vector<ll> &nums, ll &sum) {
    for (int i = 0; i < nums.size(); i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        ll target = sum - nums[i];
        bool res = false;
        while (j < k) {
            ll tmp = nums[j] + nums[k];
            if (tmp < target) j++;
            else if (tmp > target) k--;
            else {
                res = true;
                break;
            }
        }
        if (res) return true;
    }
    return false;
}

int main() {
    ll A, N;
    cin >> A >> N;
    vector<ll> nums(A);
    for (int i = 0; i < A; i++) cin >> nums[i];
    while (N--) {
        ll sum;
        cin >> sum;
        bool res = findTripleSum(nums, sum);
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}