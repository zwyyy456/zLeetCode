/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
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
    int numSquares(int n) {
        int num = 1;
        for (int i = 1; i * i <= n; i++)
            num = i;
        vector<int> nums(num, 0);
        for (int i = 0; i < num; i++)
            nums[i] = (i + 1) * (i + 1);
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < num; i++) {
            for (int j = nums[i]; j <= n; j++) {
                if (dp[j - nums[i]] < INT_MAX)
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
