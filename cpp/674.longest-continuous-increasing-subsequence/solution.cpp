/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int findLengthOfLCIS(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 2; i <= nums.size(); i++) {
            if (nums[i - 1] > nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        int m = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (dp[i] >= m)
                m = dp[i];
        }
        return m;
    }
};
// @lc code=end
