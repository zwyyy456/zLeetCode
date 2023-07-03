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
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int cnt[400000]; // 统计不同范围的 1 的个数
    int sum = 0;
    bool todo[400000];
    int build(vector<int> &vec1, int idx, int l, int r) {
        if (l == r) {
            cnt[idx] = vec1[l];
            return cnt[idx];
        }
        int mid = l + (r - l) / 2;
        cnt[idx] = build(vec1, 2 * idx, l, mid) + build(vec1, 2 * idx + 1, mid + 1, r);
        return cnt[idx];
    }
    void Modify(int idx, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            // lazy 修改
            do_modify(idx, l, r);
            return;
        }
        // 更新 lazy 到子结点
        int mid = l + (r - l) / 2;
        if (todo[idx]) {
            do_modify(2 * idx, l, mid);
            do_modify(2 * idx + 1, mid + 1, r);
            todo[idx] = false;
        }
        if (L <= mid) {
            Modify(2 * idx, l, mid, L, R);
        }
        if (R > mid) {
            Modify(2 * idx + 1, mid + 1, r, L, R);
        }
        cnt[idx] = cnt[2 * idx] + cnt[2 * idx + 1];
    }
    void do_modify(int idx, int l, int r) {
        cnt[idx] = r - l + 1 - cnt[idx]; // 即原先的 0 的数量
        todo[idx] = !todo[idx];
    }

    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        long sum1 = accumulate(nums2.begin(), nums2.end(), (long)0);
        build(nums1, 1, 0, nums1.size() - 1);
        vector<long long> ans;
        for (auto &vec : queries) {
            if (vec[0] == 1) {
                Modify(1, 0, nums1.size() - 1, vec[1], vec[2]);
            } else if (vec[0] == 2) {
                sum1 = sum1 + (long)cnt[1] * vec[1];
            } else {
                ans.push_back(sum1);
            }
        }
        return ans;
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
