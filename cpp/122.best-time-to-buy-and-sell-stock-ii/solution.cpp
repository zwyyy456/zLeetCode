/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1)
            return 0;
        vector<int> dp(prices.size() + 1, 0);
        for (int i = 2; i <= prices.size(); i++) {
            if (prices[i - 1] >= prices[i - 2])
                dp[i] = dp[i - 1] + prices[i - 1] - prices[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[prices.size()];
    }
};
// @lc code=end
