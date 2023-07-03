/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
    private:
    int max(int a, int b) {
        return a >= b ? a : b;
    }
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int sum_half = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        sum_half = sum / 2;
        vector<int> dp(sum_half + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum_half; j >= nums[i]; j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        return dp[sum_half] == sum_half;
    }
};
// @lc code=end
