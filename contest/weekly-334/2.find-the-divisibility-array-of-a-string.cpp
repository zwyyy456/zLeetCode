// Created by zwyyy456 at 2023/02/26 14:41
// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/
// https://leetcode.com/contest/weekly-contest-334/problems/find-the-divisibility-array-of-a-string/

/*
2575. Find the Divisibility Array of a String (Medium)

You are given a **0-indexed** string `word` of length `n` consisting of digits, and a positive
integer `m`.

The **divisibility array** `div` of `word` is an integer array of length `n` such that:

- `div[i] = 1` if the **numeric value** of `word[0,...,i]` is divisible by `m`, or
- `div[i] = 0` otherwise.

Return the divisibility array of `word`.

**Example 1:**

```
Input: word = "998244353", m = 3
Output: [1,1,0,0,0,1,1,0,0]
Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".

```

**Example 2:**

```
Input: word = "1010", m = 10
Output: [0,1,0,1]
Explanation: There are only 2 prefixes that are divisible by 10: "10", and "1010".

```

**Constraints:**

- `1 <= n <= 10⁵`
- `word.length == n`
- `word` consists of digits from `0` to `9`
- `1 <= m <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
  public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= word.size(); i++) {
            dp[i] = (10 * dp[i - 1] + word[i - 1] - '0') % m;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

// @lc code=end
