// Created by zwyyy456 at 2023/03/03 15:43
// https://leetcode.com/problems/dice-roll-simulation/

/*
1223. Dice Roll Simulation (Hard)

A die simulator generates a random number from `1` to `6` for each roll. You introduced a constraint
to the generator such that it cannot roll the number `i` more than `rollMax[i]` ( **1-indexed**)
consecutive times.

Given an array of integers `rollMax` and an integer `n`, return the number of distinct sequences
that can be obtained with exact  `n` rolls. Since the answer may be too large, return it **modulo**
`10⁹ + 7`.

Two sequences are considered different if at least one element differs from each other.

**Example 1:**

```
Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 =
36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most
once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 =
34.

```

**Example 2:**

```
Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30

```

**Example 3:**

```
Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181

```

**Constraints:**

- `1 <= n <= 5000`
- `rollMax.length == 6`
- `1 <= rollMax[i] <= 15`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int dieSimulator(int n, vector<int> &rollMax) {
        int mod = 1000000007;
        if (n == 1) return 6;
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        for (int i = 0; i < 6; i++) {
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                if (i <= rollMax[j]) {
                    dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % mod;
                } else if (i == rollMax[j] + 1) {
                    int tmp_sum = 0;
                    for (int k = 0; k < 6; k++) {
                        tmp_sum = (tmp_sum + dp[i - 1][k]) % mod;
                    }
                    dp[i][j] = (tmp_sum - 1) % mod;
                } else {
                    int tmp_sum = 0;
                    int tmp_minus = 0;
                    for (int k = 0; k < 6; k++) {
                        tmp_sum = (tmp_sum + dp[i - 1][k]) % mod;
                        if (k == j) {
                            continue;
                        }
                        tmp_minus = (tmp_minus + dp[i - rollMax[j] - 1][k]) % mod;
                    }
                    dp[i][j] = (tmp_sum - tmp_minus + mod) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 6; j++) {
            res = (res + dp[n][j]) % mod;
        }
        return res;
    }
};

// @lc code=end
