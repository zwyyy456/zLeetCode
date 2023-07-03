/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        k = k % (grid.size() * grid[0].size());
        auto tmp = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // int dm = k / grid[0].size();
                int dn = k % grid[0].size();
                int j_new = (j + dn) % grid[0].size();
                int i_new = (i + (j + k) / grid[0].size()) % grid.size();
                grid[i_new][j_new] = tmp[i][j];
            }
        }
        return grid;
    }
};
// @lc code=end
