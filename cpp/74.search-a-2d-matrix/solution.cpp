// Created by zwyyy456 at 2023/09/18 10:43
// leetgo: 1.3.8
// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return matrix[l / n][l % n] == target;
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
    auto res = obj->searchMatrix(matrix, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
