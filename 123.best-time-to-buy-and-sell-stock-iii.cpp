/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i <= prices.size(); i++) {
            dp[i][1] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] + prices[i - 1], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][2] - prices[i - 1], dp[i - 1][3]);
            dp[i][4] = max(dp[i - 1][3] + prices[i - 1], dp[i - 1][4]);
        }
        return dp[prices.size()][4];
    }
};
// @lc code=end
