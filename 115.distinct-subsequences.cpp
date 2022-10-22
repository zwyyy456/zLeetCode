/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        vector<vector<uint32_t>> dp(s.size() + 1, vector<uint32_t>(t.size() + 1, 0));
        // dp[0][0] = 1;
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= i && j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
        
    }
};
// @lc code=end

