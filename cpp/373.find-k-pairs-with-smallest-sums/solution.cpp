// Created by zwyyy456 at 2023/05/06 09:33
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

/*
373. Find K Pairs with Smallest Sums (Medium)
You are given two integer arrays `nums1` and `nums2` sorted in **ascending order** and an integer
`k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the
second array.

Return the `k`pairs `(u₁, v₁), (u₂, v₂), ..., (uₖ, vₖ)`with the smallest sums.

**Example 1:**

```
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

```

**Example 2:**

```
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

```

**Example 3:**

```
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 10⁵`
- `-10⁹ <= nums1[i], nums2[i] <= 10⁹`
- `nums1` and `nums2` both are sorted in **ascending order**.
- `1 <= k <= 10⁴`

*/

#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int cnt = 0;
        vector<vector<int>> res;
        auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.first + p1.second < p2.first + p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // size 为 k 的大顶堆
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            for (int j = 0; j < nums2.size() && j < k; ++j) {
                pq.push({nums1[i], nums2[j]});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        while (!pq.empty()) {
            auto [num1, num2] = pq.top();
            res.push_back({num1, num2});
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->kSmallestPairs(nums1, nums2, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
