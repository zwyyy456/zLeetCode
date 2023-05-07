// Created by zwyyy456 at 2023/05/07 14:28
// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
// https://leetcode.com/contest/weekly-contest-344/problems/make-costs-of-paths-equal-in-a-binary-tree/

/*
2673. Make Costs of Paths Equal in a Binary Tree (Medium)
You are given an integer `n` representing the number of nodes in a **perfect binary tree**
consisting of nodes numbered from `1` to `n`. The root of the tree is node `1` and each node `i` in
the tree has two children where the left child is the node `2 * i` and the right child is `2 * i +
1`.

Each node in the tree also has a **cost** represented by a given **0-indexed** integer array `cost`
of size `n` where `cost[i]` is the cost of node `i + 1`. You are allowed to **increment** the cost
of **any** node by `1` **any** number of times.

Return the **minimum** number of increments you need to make the cost of paths from the root to each
**leaf** node equal.

**Note**:

- A **perfect binary tree** is a tree where each node, except the leaf nodes, has exactly 2 children.
- The **cost of a path** is the sum of costs of nodes in the path.

**Example 1:**

![](https://assets.leetcode.com/uploads/2023/04/04/binaryytreeedrawio-4.png)

```
Input: n = 7, cost = [1,5,2,2,3,3,1]
Output: 6
Explanation: We can do the following increments:
- Increase the cost of node 4 one time.
- Increase the cost of node 3 three times.
- Increase the cost of node 7 two times.
Each path from the root to a leaf will have a total cost of 9.
The total increments we did is 1 + 3 + 2 = 6.
It can be shown that this is the minimum answer we can achieve.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2023/04/04/binaryytreee2drawio.png)

```
Input: n = 3, cost = [5,3,3]
Output: 0
Explanation: The two paths already have equal total costs, so no increments are needed.

```

**Constraints:**

- `3 <= n <= 10⁵`
- `n + 1` is a power of `2`
- `cost.length == n`
- `1 <= cost[i] <= 10⁴`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minIncrements(int n, vector<int> &cost) {
        vector<int> sum_val(n + 1);
        int res = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += cost[i - 1];
        }
        return dfs(cost, n, 1) - sum;
    }
    pair<int, int> dfs(vector<int> &cost, int n, int idx) {
        if (idx > n) {
            return {0, 0};
        }
        auto [res_left, sum_left] = dfs(cost, n, 2 * idx);
        auto [res_right, sum_right] = dfs(cost, n, 2 * idx + 1);
        int sum = max(sum_left, sum_right) + cost[idx - 1];
        int res = res_left + res_right + abs(sum_right - sum_left);
        return {res, sum};
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<int> cost;
    LeetCodeIO::scan(cin, cost);

    Solution *obj = new Solution();

    auto res = obj->minIncrements(n, cost);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
