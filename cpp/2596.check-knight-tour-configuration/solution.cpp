// Created by zwyyy456 at 2023/09/13 09:46
// leetgo: 1.3.8
// https://leetcode.com/problems/check-knight-tour-configuration/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> trace(m * n, {-1, -1});
        unordered_set<int> move{12, 21, 8, 19, -12, -21, -8, -19};
        if (grid[0][0] != 0) {
            return false;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (trace[grid[i][j]].first == -1 && trace[grid[i][j]].second == -1) {
                    trace[grid[i][j]] = {i, j};
                } else {
                    return false;
                }
            }
        }
        for (int i = 1; i < m * n; ++i) {
            auto [curx, cury] = trace[i];
            auto [prex, prey] = trace[i - 1];
            int num = 10 * (curx - prex) + (cury - prey);
            if (move.find(num) == move.end()) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();
    auto res = obj->checkValidGrid(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
