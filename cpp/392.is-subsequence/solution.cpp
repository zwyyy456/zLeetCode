/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;
        else {
            vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= t.size(); j++) {
                    if (s[i - 1] == t[j - 1])
                        dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + 1);
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            return dp[s.size()][t.size()] == s.size();
        }
    }
};
// @lc code=end
