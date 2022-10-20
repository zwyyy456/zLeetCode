/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int m = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    // dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > m)
                    m = dp[i][j]; // 记录最大的dp[i][j]
            }
        }
        return m;
    }
};
// @lc code=end
