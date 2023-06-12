// Created by zwyyy456 at 2023/06/06 10:17
// https://leetcode.com/problems/equal-row-and-column-pairs/

/*
2352. Equal Row and Column Pairs (Medium)
Given a **0-indexed** `n x n` integer matrix `grid`, return the number of pairs  `(rᵢ, cⱼ)` such that
row  `rᵢ` and column  `cⱼ` are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e.,
an equal array).

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg)

```
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg)

```
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]

```

**Constraints:**

- `n == grid.length == grid[i].length`
- `1 <= n <= 200`
- `1 <= grid[i][j] <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool flag = true;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        flag = false;
                        break;
                    }
                }
                res += flag ? 1 : 0;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->equalPairs(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
