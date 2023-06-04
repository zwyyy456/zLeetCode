// Created by zwyyy456 at 2023/05/23 09:35
// https://leetcode.com/problems/maximal-rectangle/

/*
85. Maximal Rectangle (Hard)
Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle
containing only `1`'s and return its area.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)

```
Input: matrix =
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

```

**Example 2:**

```
Input: matrix = [["0"]]
Output: 0

```

**Example 3:**

```
Input: matrix = [["1"]]
Output: 1

```

**Constraints:**

- `rows == matrix.length`
- `cols == matrix[i].length`
- `1 <= row, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Count(int row, int n, vector<int> &vec, vector<vector<char>> &matrix) {
        for (int i = 0; i < n; ++i) {
            vec[i] = matrix[row][i] == '0' ? 0 : vec[i] + 1;
        }
        // 单调递增栈
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && vec[i] < vec[stk.top()]) {
                int idx = stk.top(), h = vec[idx];
                stk.pop();
                int rec = stk.empty() ? h * i : h * (i - stk.top() - 1);
                res = max(rec, res);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            int h = vec[idx];
            stk.pop();
            int rec = stk.empty() ? h * n : h * (n - stk.top() - 1);
            res = max(res, rec);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>> &matrix) {
        // 二维前缀和？
        // 转化为 84 题，即可用单调栈解决
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<int> vec(n);
        for (int i = 0; i < m; ++i) {
            res = max(res, Count(i, n, vec, matrix));
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> matrix;
    LeetCodeIO::scan(cin, matrix);

    Solution *obj = new Solution();

    auto res = obj->maximalRectangle(matrix);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
