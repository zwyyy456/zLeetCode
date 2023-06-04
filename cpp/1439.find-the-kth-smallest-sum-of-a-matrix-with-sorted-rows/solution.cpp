// Created by zwyyy456 at 2023/05/28 15:13
// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

/*
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows (Hard)
You are given an `m x n` matrix `mat` that has its rows sorted in non-decreasing order and an integer
`k`.

You are allowed to choose **exactly one element** from each row to form an array.

Return the  `kth` smallest array sum among all possible arrays.

**Example 1:**

```
Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.

```

**Example 2:**

```
Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17

```

**Example 3:**

```
Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.

```

**Constraints:**

- `m == mat.length`
- `n == mat.length[i]`
- `1 <= m, n <= 40`
- `1 <= mat[i][j] <= 5000`
- `1 <= k <= min(200, nm)`
- `mat[i]` is a non-decreasing array.

*/

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(priority_queue<int, vector<int>, greater<int>> &pq, int m, vector<vector<int>> &mat, int n, int idx, vector<int> &choose) {
        if (idx == m) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            ++choose[idx];
        }
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int m = mat.size(), n = mat[0].size();
        vector<int> choose(m);
        dfs(pq, m, mat, n, 0, choose);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> mat;
    LeetCodeIO::scan(cin, mat);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->kthSmallest(mat, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
