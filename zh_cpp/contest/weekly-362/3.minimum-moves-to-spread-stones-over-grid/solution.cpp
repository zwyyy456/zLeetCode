// Created by zwyyy456 at 2023/09/10 11:13
// leetgo: 1.3.8
// https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/
// https://leetcode.cn/contest/weekly-contest-362/problems/minimum-moves-to-spread-stones-over-grid/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using ust = unordered_set<int>;
    using ump = unordered_map<int, int>;
    int dfs(vector<vector<int>> &grid, int cnt0) {
        if (cnt0 == 0) {
            return 0;
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < 9; ++i) {
            int x = i / 3, y = i % 3;
            if (grid[x][y] == 0) {
                for (int j = 0; j < 9; ++j) {
                    int tx = j / 3, ty = j % 3;
                    if (grid[tx][ty] > 1) {
                        grid[x][y] = 1;
                        --grid[tx][ty];
                        res = min(res, abs(tx - x) + abs(ty - y) + dfs(grid, cnt0 - 1));
                        grid[x][y] = 0;
                        ++grid[tx][ty];
                    }
                }
            }
        }
        return res;
    }
    int minimumMoves(vector<vector<int>> &grid) {
        ust num0;
        ump more1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    num0.insert(i * 10 + j);
                } else if (grid[i][j] > 1) {
                    more1[i * 10 + j] = grid[i][j];
                }
            }
        }
        int res = 0;
        // 写个递归吧
        return dfs(grid, num0.size());
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();
    auto res = obj->minimumMoves(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
