// Created by zwyyy456 at 2023/10/18 10:01
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<string> &grid, vector<vector<int>> &move) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < 4; ++i) {
            int newx = x + move[i][0], newy = y + move[i][1];
            if (newx < 0 || newx >= m || newy < 0 || newy >= n || vis[newx][newy] == 1) {
                continue;
            }
            vis[newx][newy] = 1;
            dfs(newx, newy, vis, grid, move);
        }
    }
    int numIslands(vector<string> &grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> move{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] == 1 || grid[i][j] == '0') {
                    continue;
                }
                ++cnt;
                vis[i][j] = 1;
                dfs(i, j, vis, grid, move);
            }
        }
        return cnt;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();
    auto res = obj->numIslands(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
