// Created by zwyyy456 at 2023/03/03 09:50
// https://leetcode.com/problems/n-th-tribonacci-number/

/*
1137. N-th Tribonacci Number (Easy)

The Tribonacci sequence T is defined as follows:

T = 0, T = 1, T = 1, and T = T \+ T \+ T for n >= 0.

Given `n`, return the value of T.

**Example 1:**

```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

```

**Example 2:**

```
Input: n = 25
Output: 1389537

```

**Constraints:**

- `0 <= n <= 37`
- The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.
*/

// @lc code=begin

class Solution {
  public:
    int tribonacci(int n) {
        int num0 = 0, num1 = 1, num2 = 1;
        if (n == 0) {
            return num0;
        }
        if (n == 1) {
            return num1;
        }
        if (n == 2) {
            return num2;
        }
        for (int i = 2; i <= n; i++) {
            int tmp2 = num2;
            int tmp = num1;
            num2 += num0 + num1;
            num1 = tmp2;
            num0 = tmp;
        }
        return num1;
    }
};

// @lc code=end
