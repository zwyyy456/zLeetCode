/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  private:
    int max(int a, int b) {
        return a >= b ? a : b;
    }

  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> str_num(strs.size() + 1, vector<int>(2, 0));
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    str_num[i + 1][0]++;
                else
                    str_num[i + 1][1]++;
            }
        }
        // vector<vector<vector<int>>> dp(101, vector<vector<int>>(strs.size() + 1, vector<int>(101, 0)));
        vector<vector<int>> dp(101, vector<int>(101, 0));
        for (int i = 1; i <= strs.size(); i++) {
            for (int j = m; j >= str_num[i][0]; j--) {
                for (int k = n; k >= str_num[i][1]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - str_num[i][0]][k - str_num[i][1]] + 1);
                }
            }
        }
        // for (int i = 1; i <= strs.size(); i++) {
        //     for (int j = 0; j <=)
        // }
        return dp[m][n];
    }
};
// @lc code=end
