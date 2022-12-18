/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    double knightProbability(int n, int k, int row, int column) {
        // dp[i][j][k]表示从[row, column]运动k步，到达[i, j]的概率
        vector<vector<int>> kmove{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2}};
        if (n == 1 || n == 2)
            return k = 0;
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        dp[row][column][0] = 1;
        for (int num = 1; num <= k; num++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double tmp = 0;
                    for (int m = 0; m < 8; m++) {
                        int loc_x = i + kmove[m][0];
                        int loc_y = j + kmove[m][1];
                        if (loc_x < n && loc_x > 0 && loc_y < n && loc_y > 0)
                            tmp += dp[loc_x][loc_y][num - 1];
                    }
                    dp[i][j][num] = tmp / 8;
                }
            }
        }
        double res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j][k];
            }
        }
        return res;
    }
};
// @lc code=end
