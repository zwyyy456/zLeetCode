// Created by zwyyy456 at 2023/08/04 09:55
// leetgo: 1.3.1
// https://leetcode.com/problems/unique-paths-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    int dfs(vector<vector<int>> &grid, int x, int y, int left) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] < 0) {
            return 0; // 不合法
        }
        if (grid[x][y] == 2) {        // 到达终点
            return left == 0 ? 1 : 0; // 必须访问所有的无障碍方格
        }
        grid[x][y] = -1; // 标记成访问过，因为题目要求「不能重复通过同一个方格」
        int ans = dfs(grid, x - 1, y, left - 1) + dfs(grid, x, y - 1, left - 1) + dfs(grid, x + 1, y, left - 1) + dfs(grid, x, y + 1, left - 1);
        grid[x][y] = 0; // 恢复现场
        return ans;
    }

  public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), cnt0 = 0, sx, sy;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt0++;
                } else if (grid[i][j] == 1) {
                    sx = i, sy = j; // 起点
                }
            }
        }

        return dfs(grid, sx, sy, cnt0 + 1); // +1 把起点也算上
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->uniquePathsIII(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
