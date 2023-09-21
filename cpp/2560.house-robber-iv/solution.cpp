// Created by zwyyy456 at 2023/09/19 09:21
// leetgo: 1.3.8
// https://leetcode.com/problems/house-robber-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int mid, vector<int> &nums, int k) {
        // 只能选小于等于 mid 的
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0] <= mid ? 1 : 0;
        for (int i = 2; i <= n; ++i) {
            if (nums[i - 1] <= mid) {
                dp[i] = max(dp[i - 1], dp[i - 2] + 1);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n] >= k;
    }
    int minCapability(vector<int> &nums, int k) {
        // 二分答案
        int l = 0, r = 1e9 + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!check(mid, nums, k)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->minCapability(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
