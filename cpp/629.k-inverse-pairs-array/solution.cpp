// Created by zwyyy456 at 2023/03/08 09:53
// https://leetcode.com/problems/k-inverse-pairs-array/

/*
629. K Inverse Pairs Array (Hard)

For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j <
nums.length` and `nums[i] > nums[j]`.

Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n`
such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it
**modulo** `10⁹ + 7`.

**Example 1:**

```
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse
pairs.

```

**Example 2:**

```
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

```

**Constraints:**

- `1 <= n <= 1000`
- `0 <= k <= 1000`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }
        int mod = 1000000007;
        if (k > n * (n - 1) / 2) {
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= (i * (i - 1) / 2); ++j) {
                if (j <= i - 1) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};

// @lc code=end
