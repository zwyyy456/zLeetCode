// Created by zwyyy456 at 2023/08/24 09:05
// leetgo: 1.3.5
// https://leetcode.com/problems/count-servers-that-communicate/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countServers(vector<vector<int>> &grid) {
        int total = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> row_cnt(m);
        vector<int> col_cnt(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++row_cnt[i];
                    ++col_cnt[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (row_cnt[i] > 1 || col_cnt[j] > 1) {
                        ++total;
                    }
                }
            }
        }
        return total;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();
    auto res = obj->countServers(grid);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
