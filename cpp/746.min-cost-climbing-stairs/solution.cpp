/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int sz = cost.size();
        vector<int> dp(2);
        dp[0] = dp[1] = 0;
        // dp[2] = cost[0] < cost[1] ? cost[0] : cost[1];
        for (int i = 2; i <= sz; i++) {
            // 原始版本
            // dp[i] = (dp[i - 2] + cost[i - 2]) < (dp[i - 1] + cost[i - 1]) ? (dp[i - 2] + cost[i - 2]) : (dp[i - 1] + cost[i - 1]);
            // 空间优化版本：
            int res = dp[0] + cost[i - 2] < dp[1] + cost[i - 1] ? dp[0] + cost[i - 2] : dp[1] + cost[i - 1];
            dp[0] = dp[1];
            dp[1] = res;
        }
        return dp[1];
    }
};
// @lc code=end
