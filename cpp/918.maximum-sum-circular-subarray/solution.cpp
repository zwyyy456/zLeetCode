// Created by zwyyy456 at 2023/07/20 10:37
// leetgo: 1.3.1
// https://leetcode.com/problems/maximum-sum-circular-subarray/

#include <bits/stdc++.h>
#include <climits>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, INT_MIN);
        // 先求 dp[0];
        // 分情况讨论，先统计正常的情况，再统计被分成两段的情况
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> normal(n, INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        // 寻找以 head 为起点的最小值
        vector<int> min_sum(n, 0);
        min_sum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_sum[i] = min(min_sum[i + 1] + nums[i], nums[i]);
        }
        int res = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            dp[i] = max(dp[i], sum - min_sum[i + 1]);
            res = max(res, dp[i]);
        }
        return max(res, dp[n - 1]);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->maxSubarraySumCircular(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
