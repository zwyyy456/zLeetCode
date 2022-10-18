/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int m = 0;
        int res = 0;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // for (int a = 1; a < i; a++)
                    //     for (int b = 1; b < j; b++)
                    //         if (dp[a][b] > m)
                    //             m = dp[a][b];
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1])); // 这里必须保证，假设m = dp[a][b], 必须a, b分别小于i, j才行
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // for (int j = 1; j <= text2.size(); j++)
            //     if (dp[i][j] > res)
            //         res = dp[i][j];
        }
        return dp[text1.size()][text2.size()];
        // return res;
    }
};
// @lc code=end
