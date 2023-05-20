// Created by zwyyy456 at 2023/05/15 09:30
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

/*
1072. Flip Columns For Maximum Number of Equal Rows (Medium)
You are given an `m x n` binary matrix `matrix`.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change
the value of the cell from `0` to `1` or vice versa).

Return the maximum number of rows that have all values equal after some number of flips.

**Example 1:**

```
Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

```

**Example 2:**

```
Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

```

**Example 3:**

```
Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` is either `0` or `1`.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        unordered_map<string, int> rows;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        for (int i = 0; i < m; ++i) {
            string str0, str1;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    str0.push_back('0' + j);
                } else {
                    str1.push_back('0' + j);
                }
            }
            ++rows[str0];
            ++rows[str1];
            ans = max(max(ans, rows[str0]), rows[str1]);
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> matrix;
    LeetCodeIO::scan(cin, matrix);

    Solution *obj = new Solution();

    auto res = obj->maxEqualRowsAfterFlips(matrix);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
