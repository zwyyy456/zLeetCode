/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = 1;
        // int index = 0;
        for (int i = 2; i <= nums.size(); i++) {
            // index = i;
            // for (int j = i + 1; j <= nums.size(); j++) {
            //     if (nums[j] > nums[index]) {
            //         dp[j] = dp[index] + 1;
            //         index = j;
            //     }
            // }
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] > nums[j - 1])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
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
