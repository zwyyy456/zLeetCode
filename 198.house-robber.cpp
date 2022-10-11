/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

  public:
    int rob(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 0);
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};
// @lc code=end
