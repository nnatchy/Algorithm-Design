#include<iostream>
#include<vector>

using namespace std;

int binary_search2(vector<int> nums, int l, int r, int target) {
    int mid = (l + r) / 2;
    if (target == nums[mid]) {
        for (int i = mid; i < nums.size(); i++) {
            if (nums[i] != target) return i-1;
        }
    }
    else {
        if (r - l == 1) {
            if (target < nums[r]) return l;
            return r;
        }
        if (target > nums[mid]) {
            return binary_search2(nums, mid, r, target);
        } else {
            return binary_search2(nums, l, mid, target);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, inp;
    cin >> N >> M;
    vector<int> vi, nums;
    while (N--) {
        cin >> inp;
        nums.push_back(inp);
    }
    while (M--) {
        cin >> inp;
        int ans = inp < nums[0] ? -1 : binary_search2(nums, 0, nums.size(), inp);
        cout << ans << "\n";
    }

}