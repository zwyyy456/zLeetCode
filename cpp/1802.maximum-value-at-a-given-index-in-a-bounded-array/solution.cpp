// Created by zwyyy456 at 2023/06/08 08:49
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

/*
1802. Maximum Value at a Given Index in a Bounded Array (Medium)
You are given three positive integers: `n`, `index`, and `maxSum`. You want to construct an array
`nums` ( **0-indexed**)that satisfies the following conditions:

- `nums.length == n`
- `nums[i]` is a **positive** integer where `0 <= i < n`.
- `abs(nums[i] - nums[i+1]) <= 1` where `0 <= i < n-1`.
- The sum of all the elements of `nums` does not exceed `maxSum`.
- `nums[index]` is **maximized**.

Return `nums[index]` of the constructed array.

Note that `abs(x)` equals `x` if `x >= 0`, and `-x` otherwise.

**Example 1:**

```
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum
nums[2].

```

**Example 2:**

```
Input: n = 6, index = 1,  maxSum = 10
Output: 3

```

**Constraints:**

- `1 <= n <= maxSum <= 10⁹`
- `0 <= index < n`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(int mid, int maxSum, int index, int n) {
        long sum = 0;
        long left_sum = 0, right_sum = 0;
        if (mid >= index + 1) {
            left_sum = (mid + mid - index) * (index + 1) / 2;
        } else {
            left_sum = (1 + mid) * mid / 2 + index + 1 - mid;
        }
        if (mid - n + index + 1 >= 1) {
            right_sum = (mid - 1 + mid - n + index + 1) * (n - index - 1) / 2;
        } else {
            right_sum = mid * (mid - 1) / 2 + (n - index - 1) - (mid - 1);
        }
        return left_sum + right_sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        // 二分答案
        int left = 1, right = maxSum + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (Check(mid, maxSum, index, n)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int index;
    LeetCodeIO::scan(cin, index);
    int maxSum;
    LeetCodeIO::scan(cin, maxSum);

    Solution *obj = new Solution();

    auto res = obj->maxValue(n, index, maxSum);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
