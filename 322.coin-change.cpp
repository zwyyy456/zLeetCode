/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <limits.h>
#include <vector>
using std::vector;
class Solution {
  private:
    int min(int a, int b) {
        return a < b ? a : b;
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                // 因为可能执行+1的操作， 所以判断dp[j - coins[i]]而不是dp[j]
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                // else
                //     dp[j] = dp[j - coins[i]];
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
// @lc code=end
