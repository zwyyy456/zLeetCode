// Created by zwyyy456 at 2023/06/05 10:50
// https://leetcode.com/problems/sum-of-matrix-after-queries/

/*
2718. Sum of Matrix After Queries (Medium)
You are given an integer `n` and a **0-indexed** **2D array** `queries` where `queries[i] = [typeᵢ,
indexᵢ, valᵢ]`.

Initially, there is a **0-indexed** `n x n` matrix filled with `0`'s. For each query, you must apply
one of the following changes:

- if `typeᵢ == 0`, set the values in the row with `indexᵢ` to `valᵢ`, overwriting any previous
values.
- if `typeᵢ == 1`, set the values in the column with `indexᵢ` to `valᵢ`, overwriting any previous
values.

Return the sum of integers in the matrix after all queries are applied.

**Example 1:**

![](https://assets.leetcode.com/uploads/2023/05/11/exm1.png)

```
Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
Output: 23
Explanation: The image above describes the matrix after each query. The sum of the matrix after all
queries are applied is 23.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2023/05/11/exm2.png)

```
Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
Output: 17
Explanation: The image above describes the matrix after each query. The sum of the matrix after all
queries are applied is 17.

```

**Constraints:**

- `1 <= n <= 10⁴`
- `1 <= queries.length <= 5 * 10⁴`
- `queries[i].length == 3`
- `0 <= typeᵢ <= 1`
- `0 <= indexᵢ < n`
- `0 <= valᵢ <= 10⁵`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries) {
        // 倒序处理
        unordered_set<int> col_hash, row_hash;
        for (int i = 0; i < n; ++i) {
            col_hash.insert(i);
            row_hash.insert(i);
        }
        int m = queries.size();
        long long total = 0;
        for (int i = m - 1; i >= 0 && !col_hash.empty() && !row_hash.empty(); --i) {
            if (queries[i][0] == 0) {
                // 修改行
                if (row_hash.find(queries[i][1]) == row_hash.end()) {
                    // 说明后面还会被修改，直接不管他
                    continue;
                }
                total += col_hash.size() * queries[i][2];
                row_hash.erase(queries[i][1]);
            } else {
                // 修改列
                if (col_hash.find(queries[i][1]) == col_hash.end()) {
                    continue;
                }
                total += row_hash.size() * queries[i][2];
                col_hash.erase(queries[i][1]);
            }
        }
        return total;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->matrixSumQueries(n, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
