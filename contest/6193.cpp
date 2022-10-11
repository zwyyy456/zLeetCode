#include <vector>
using std::vector;
class Solution {
  public:
    int maxSum(vector<vector<int>> &grid) {
        int sum = 0;
        int tmp_sum = 0;
        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[0].size() - 2; j++) {
                tmp_sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                if (tmp_sum > sum)
                    sum = tmp_sum;
            }
        }
        return sum;
    }
};