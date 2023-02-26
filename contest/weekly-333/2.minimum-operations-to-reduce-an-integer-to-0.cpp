// Created by zwyyy456 at 2023/02/19 15:54
// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
// https://leetcode.com/contest/weekly-contest-333/problems/minimum-operations-to-reduce-an-integer-to-0/

/*
2571. Minimum Operations to Reduce an Integer to 0 (Easy)

You are given a positive integer `n`, you can do the following operation **any** number of times:

- Add or subtract a **power** of `2` from `n`.

Return the **minimum** number of operations to make  `n` equal to  `0`.

A number `x` is power of `2` if `x == 2ⁱ` where `i >= 0`.

**Example 1:**

```
Input: n = 39
Output: 3
Explanation: We can do the following operations:
- Add 2⁰ = 1 to n, so now n = 40.
- Subtract 2³ = 8 from n, so now n = 32.
- Subtract 2⁵ = 32 from n, so now n = 0.
It can be shown that 3 is the minimum number of operations we need to make n equal to 0.

```

**Example 2:**

```
Input: n = 54
Output: 3
Explanation: We can do the following operations:
- Add 2¹ = 2 to n, so now n = 56.
- Add 2³ = 8 to n, so now n = 64.
- Subtract 2⁶ = 64 from n, so now n = 0.
So the minimum number of operations is 3.

```

**Constraints:**

- `1 <= n <= 10⁵`
*/

// @lc code=begin
#include <algorithm>
#include <tuple>
class Solution {
  public:
    int Findn(int n) {
        int base = 1;
        while (base < n) {
            base *= 2;
        }
        return base;
    }
    int GetNum(int n) {
        if (Findn(n) == n)
            return 1;
        int base = Findn(n);
    }
    int minOperations(int n) {
        return GetNum(n);
    }
};

// @lc code=end
