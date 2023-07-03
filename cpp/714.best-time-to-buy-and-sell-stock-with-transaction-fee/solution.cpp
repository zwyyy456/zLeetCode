/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = -fee;
        for (int i = 1; i <= prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = max(0, max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1] - fee));
        }
        return dp[prices.size()][1];
    }
};
// @lc code=end
