// Created by zwyyy456 at 2023/10/14 19:37
// leetgo: 1.3.8
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> rowsum(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j - 1];
            }
        }
        int res = INT_MIN;
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r <= n; ++r) {
                // 左闭右开
                set<int> sums;
                sums.insert(0);
                int total = 0;
                for (int i = 0; i < m; ++i) {
                    total += rowsum[i][r] - rowsum[i][l];
                    auto iter = sums.lower_bound(total - k);
                    if (iter != sums.end()) {
                        res = max(res, total - *iter);
                    }
                    sums.insert(total);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> matrix;
    LeetCodeIO::scan(cin, matrix);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->maxSumSubmatrix(matrix, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
