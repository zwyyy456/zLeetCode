// Created by zwyyy456 at 2023/10/13 10:12
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        // 二维前缀和
        // 枚举左右边界，转换为一维前缀和
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> rowsum(m, vector<int>(n + 1));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                // 左闭右开
                unordered_map<int, int> record;
                record[0] = 1;
                int sum = 0;
                for (int k = 1; k <= m; ++k) {
                    sum += rowsum[k - 1][j] - rowsum[k - 1][i];
                    if (record.find(sum - target) != record.end()) {
                        res += record[sum - target];
                    }
                    ++record[sum];
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
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();
    auto res = obj->numSubmatrixSumTarget(matrix, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
