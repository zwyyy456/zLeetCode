/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
using std::string;
using std::unordered_set;
using std::vector;
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, 0); // 0 为false
        dp[0] = 1;
        // 先遍历体积，再遍历物品
        for (int j = 0; j <= s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                string word = s.substr(i, j - i);
                if (wordSet.find(word) != wordSet.end() && dp[i])
                    dp[j] = 1;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
