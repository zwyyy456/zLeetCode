// Created by zwyyy456 at 2023/02/23 15:46
// https://leetcode.com/problems/integer-replacement/

/*
397. Integer Replacement (Medium)

Given a positive integer `n`, you can apply one of the following operations:

1. If `n` is even, replace `n` with `n / 2`.
2. If `n` is odd, replace `n` with either `n + 1` or `n - 1`.

Return the minimum number of operations needed for `n`to become `1`.

**Example 1:**

```
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

```

**Example 2:**

```
Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

```

**Example 3:**

```
Input: n = 4
Output: 2

```

**Constraints:**

- `1 <= n <= 2³¹ - 1`
*/

// @lc code=begin

class Solution {
  public:
    int integerReplacement(int n) {
        int cnt = 0;
        while (n != 1) {
            while ((n & 1) == 0) { // n为偶数
                n >>= 1;         // 相当于除以2
                cnt++;
            }
            if (n == 1) {
                return cnt;
            }
            if (n == 3)
                return cnt + 2;
            if ((n + 1) & 3 == 0) { // n能被4整除
                n += 1;
                cnt++;
            } else {
                n -= 1;
                cnt++;
            }
        }
        return cnt;
    }
};

// @lc code=end
