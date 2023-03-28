// Created by zwyyy456 at 2023/03/17 13:01
// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

/*
2389. Longest Subsequence With Limited Sum (Easy)

You are given an integer array `nums` of length `n`, and an integer array `queries` of length `m`.

Return an array  `answer` of length  `m` where  `answer[i]` is the **maximum** size of a
**subsequence** that you can take from  `nums` such that the **sum** of its elements is less than or
equal to  `queries[i]`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements
without changing the order of the remaining elements.

**Example 1:**

```
Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum
size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum
size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the
maximum size of such a subsequence, so answer[2] = 4.

```

**Example 2:**

```
Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1,
so answer[0] = 0.
```

**Constraints:**

- `n == nums.length`
- `m == queries.length`
- `1 <= n, m <= 1000`
- `1 <= nums[i], queries[i] <= 10⁶`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int Bfind(vector<int> &prefix, int target) {
        int left = 0, right = prefix.size();
        // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = Bfind(prefix, queries[i] + 1) - 1;
        }
        return res;
    }
};

// @lc code=end
