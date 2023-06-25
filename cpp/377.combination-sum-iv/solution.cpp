/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int combine(int i, int k) {
        if (i == k)
            return 1;
        if (i < k) {
            int tmp = i;
            i = k;
            k = tmp;
        }
        vector<vector<int>> dp(i + 1, vector<int>(k + 1, 0));
        for ()
    }

  public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> my_nums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            my_nums[i + 1] = nums[i];
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++)
                dp[i][j] = dp[i - 1][j];
            if (j >= nums[i]) {
                for (int k = 1; k * nums[i] <= j; k++)
                    dp[i][j] += dp[i - 1][j - k * nums[i]] * combine(i, k);
            }
        }
    }
};
// @lc code=end
