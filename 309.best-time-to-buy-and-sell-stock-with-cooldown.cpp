/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int max3(int a, int b, int c) {
        if (a > b)
            return a > c ? a : c;
        else
            return b > c ? b : c;
    }
    int max4(int a, int b, int c, int d) {
        int l = a > b ? a : b;
        int r = c > d ? c : d;
        return l > r ? l : r;
    }

  public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = 0;
        dp[0][4] = 0;
        for (int i = 1; i <= prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max4(dp[i - 1][1], dp[i - 1][0] - prices[i - 1], dp[i - 1][4] - prices[i - 1], dp[i - 1][3] - prices[i - 1]);
            dp[i][2] = dp[i - 1][1] + prices[i - 1];
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = max(dp[i - 1][3], dp[i - 1][4]);
        }
        return max3(dp[prices.size()][2], dp[prices.size()][3], dp[prices.size()][4]);
    }
};
// @lc code=end
