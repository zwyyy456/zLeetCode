// Created by zwyyy456 at 2023/11/09 19:16
// leetgo: 1.3.8
// https://leetcode.com/problems/escape-the-spreading-fire/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int l = 0, r = 1e9 + 2;
        // 对每个格子，确定火焰蔓延所需要的时间
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    time[i][j] = bfs(grid);
                }
            }
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();
    auto res = obj->maximumMinutes(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
