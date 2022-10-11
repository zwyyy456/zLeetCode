/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    int max(int a, int b, int c) {
        if (a > b)
            return a > c ? a : c;
        else
            return b > c ? b : c;
    }

  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1)
            return 0;
        vector<int> min_arr(prices.size() + 1, prices[0]);
        min_arr[0] = prices[0];
        for (int i = 1; i <= prices.size(); i++) {
            min_arr[i] = min(min_arr[i - 1], prices[i - 1]);
        }
        vector<int> dp(prices.size() + 1, 0);
        for (int i = 1; i <= prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i - 1] - min_arr[i - 1], 0);
        }
        return dp[prices.size()];
    }
};
// @lc code=end
