// Created by zwyyy456 at 2023/05/31 08:47
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

/*
1130. Minimum Cost Tree From Leaf Values (Medium)
Given an array `arr` of positive integers, consider all binary trees such that:

- Each node has either `0` or `2` children;
- The values of `arr` correspond to the values of each **leaf** in an in-order traversal of the tree.
- The value of each non-leaf node is equal to the product of the largest leaf value in its left and
right subtree, respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each
non-leaf node. It is guaranteed this sum fits into a **32-bit** integer.

A node is a **leaf** if and only if it has zero children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/10/tree1.jpg)

```
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/10/tree2.jpg)

```
Input: arr = [4,11]
Output: 44

```

**Constraints:**

- `2 <= arr.length <= 40`
- `1 <= arr[i] <= 15`
- It is guaranteed that the answer fits into a **32-bit** signed integer (i.e., it is less than 2).

*/

#include <bits/stdc++.h>
#include <climits>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(vector<int> &arr, int l, int r, vector<vector<int>> &mem, vector<vector<int>> &max_num) {
        if (l == r) {
            return 0;
        }
        if (mem[l][r] != -1) {
            return mem[l][r];
        }
        int res = INT_MAX;
        for (int i = l; i < r; ++i) {
            int val1 = dfs(arr, l, i, mem, max_num);
            int val2 = dfs(arr, i + 1, r, mem, max_num);
            int max_left = max_num[l][i], max_right = max_num[i + 1][r];
            res = min(res, val1 + val2 + max_left * max_right);
        }
        mem[l][r] = res;
        return mem[l][r];
    }
    int mctFromLeafValues(vector<int> &arr) {
        // 要么单独作为叶子结点，要么和相邻的作为左叶子和右叶子
        // 记忆化搜索，枚举分割点
        // dfs(0, n - 1) = dfs(0, i) + dfs(i + 1, n - 1) + max(0, i) * max(i + 1, n - 1);
        int n = arr.size();
        vector<vector<int>> max_num(n, vector<int>(n, 0));
        max_num[0][0] = arr[0];
        for (int i = 0; i < n; ++i) {
            max_num[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                max_num[i][j] = max(max_num[i][j - 1], arr[j]);
            }
        }
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return dfs(arr, 0, n - 1, mem, max_num);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr;
    LeetCodeIO::scan(cin, arr);

    Solution *obj = new Solution();

    auto res = obj->mctFromLeafValues(arr);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
