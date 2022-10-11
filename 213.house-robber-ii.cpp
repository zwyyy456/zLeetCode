/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int func_dp(vector<int> nums, vector<int> &dp) {
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }

  public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> dp0(nums.size() + 1, 0);
        vector<int> dp1(nums.size(), 0);
        vector<int> nums1(nums.size() - 1, 0);
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = nums[i + 1];
        }
        int a = func_dp(nums, dp0);
        int b = func_dp(nums1, dp1);
        if (a == b)
            return a;
        return max(dp0[nums.size() - 1], b);
    }
};
// @lc code=end
