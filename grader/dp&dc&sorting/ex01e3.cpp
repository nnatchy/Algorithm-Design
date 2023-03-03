#include<iostream>
#include<vector>

using namespace std;

int binary_search2(vector<int> &nums, int l, int r, int target) {
    int gap = r - l;
    int lGap = gap / 2;
    if (gap % 2 != 0) lGap++;
    if (target == nums[l + lGap]) {
        for (int i = l + lGap; i < nums.size(); i++) {
            if (nums[i] != target) return i - 1;
        }
    }
    if (r - l == 1) {
        if (nums[l] <= target) return l;
        return ++l;
    }
    if (nums[l + lGap] > target) return binary_search2(nums, l, l + lGap, target);
    else return binary_search2(nums, l + lGap, r, target);
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
