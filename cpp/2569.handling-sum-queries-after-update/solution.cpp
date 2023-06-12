// Created by zwyyy456 at 2023/06/12 18:55
// https://leetcode.com/problems/handling-sum-queries-after-update/

/*
2569. Handling Sum Queries After Update (Hard)
You are given two **0-indexed** arrays `nums1` and `nums2` and a 2D array `queries` of queries. There
are three types of queries:

1. For a query of type 1, `queries[i] = [1, l, r]`. Flip the values from `0` to `1` and from `1` to
`0` in `nums1 ` from index `l` to index `r`. Both `l` and `r` are **0-indexed**.
2. For a query of type 2, `queries[i] = [2, p, 0]`. For every index `0 <= i < n`, set `nums2[i] =
nums2[i] + nums1[i] * p`.
3. For a query of type 3, `queries[i] = [3, 0, 0]`. Find the sum of the elements in `nums2`.

Return an array containing all the answers to the third type queries.

**Example 1:**

```
Input: nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
Output: [3]
Explanation: After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes
[1,1,1], so the answer to the third query is 3. Thus, [3] is returned.

```

**Example 2:**

```
Input: nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
Output: [5]
Explanation: After the first query, nums2 remains [5], so the answer to the second query is 5. Thus,
[5] is returned.

```

**Constraints:**

- `1 <= nums1.length,nums2.length <= 10⁵`
- `nums1.length = nums2.length`
- `1 <= queries.length <= 10⁵`
- `queries[i].length = 3`
- `0 <= l <= r <= nums1.length - 1`
- `0 <= p <= 10⁶`
- `0 <= nums1[i] <= 1`
- `0 <= nums2[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int arr1[400000];
    int arr2[400000];
    int toadd[400000];
    bool toreverse[400000];
    void Add(int idx, int l, int r, int L, int R, int add) {
        if (L <= l && R >= r) {
            // lazy 修改
            toadd[idx] += add;
            return;
        }
        // 更新 lazy 到子结点
        int mid = l + (r - l) / 2;
        doadd(2 * idx, l, mid);
        doadd(2 * idx + 1, mid + 1, r);
        toadd[idx] = 0;
        if (L <= mid) {
            Add(2 * idx, l, mid, L, R, add);
        }
        if (R >= mid) {
            Add(2 * idx + 1, mid + 1, r, L, R, add);
        }
    }
    void Reverse(int idx, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            // lazy 修改
            toreverse[idx] = !toreverse[idx];
            return;
        }
        // 更新 lazy 到子结点
        int mid = l + (r - l) / 2;
        doreverse(2 * idx, l, mid);
        doreverse(2 * idx, mid + 1, r);
        toreverse[idx] = !toreverse[idx];
        if (L <= mid) {
            Reverse(2 * idx, l, mid, L, R);
        }
        if (R >= mid) {
            Reverse(2 * idx + 1, mid + 1, r, L, R);
        }
    }

    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->handleQuery(nums1, nums2, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
