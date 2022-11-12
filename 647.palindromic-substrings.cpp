/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) {
            dp[i][i] = 1;
        }
        int sum = 0;
        for (int i = s.size(); i >= 1; i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (j > i) {
                    if (s[i - 1] == s[j - 1])
                        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + dp[i + 1][j - 1] + 1;
                    else
                        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + dp[i + 1][j - 1];
                }
            }
        }
        return sum + s.size();
    }
};
// @lc code=end
