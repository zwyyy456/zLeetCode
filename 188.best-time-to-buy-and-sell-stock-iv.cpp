/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));
        for (int j = 1; j <= 2 * k; j++) {
            if (j % 2 == 1)
                dp[0][j] = -prices[0];
        }

        for (int i = 1; i <= prices.size(); i++) {
            for (int j = 1; j <= 2 * k; j++) {
                if (j % 2 == 1)
                    dp[i][j] = max(dp[i - 1][j - 1] - prices[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = max(dp[i - 1][j - 1] + prices[i - 1], dp[i - 1][j]);
            }
        }
        return dp[prices.size()][2 * k];
    }
};
// @lc code=end
