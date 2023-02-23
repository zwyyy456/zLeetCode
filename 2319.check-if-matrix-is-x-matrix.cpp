/*
 * @lc app=leetcode id=2319 lang=cpp
 *
 * [2319] Check if Matrix Is X-Matrix
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    bool checkXMatrix(vector<vector<int>> &grid) {
        bool res = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == j || i + j == grid.size() - 1) {
                    if (grid[i][j] == 0)
                        return false;
                } else {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
