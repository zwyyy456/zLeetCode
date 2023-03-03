// Created by zwyyy456 at 2023/03/03 10:24
// https://leetcode.com/problems/student-attendance-record-ii/

/*
552. Student Attendance Record II (Hard)

An attendance record for a student can be represented as a string where each character signifies
whether the student was absent, late, or present on that day. The record only contains the following
three characters:

- `'A'`: Absent.
- `'L'`: Late.
- `'P'`: Present.

Any student is eligible for an attendance award if they meet **both** of the following criteria:

- The student was absent ( `'A'`) for **strictly** fewer than 2 days **total**.
- The student was **never** late ( `'L'`) for 3 or more **consecutive** days.

Given an integer `n`, return the **number** of possible attendance records of length `n` that make a
student eligible for an attendance award. The answer may be very large, so return it **modulo** `10⁹
+ 7`.

**Example 1:**

```
Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

```

**Example 2:**

```
Input: n = 1
Output: 3

```

**Example 3:**

```
Input: n = 10101
Output: 183236316

```

**Constraints:**

- `1 <= n <= 10⁵`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int checkRecord(int n) {
        if (n == 1)
            return 3;
        if (n == 2)
            return 8;
        if (n == 3)
            return 19;
        vector<vector<long long>> dp3(n + 1, vector<long long>(3, 0));
        vector<vector<long long>> dp2(n, vector<long long>(2, 0));
        int mod = 1000000007;
        // 0表示迟到，1表示到场，2表示缺勤
        dp2[0][0] = dp2[0][1] = 1;
        dp2[1][0] = dp2[1][1] = 2;
        dp2[2][0] = 3;
        dp2[2][1] = 4;
        for (int i = 3; i < n; i++) {
            dp2[i][1] = (dp2[i - 1][0] % mod + dp2[i - 1][1] % mod) % mod;
            dp2[i][0] = (dp2[i - 1][1] % mod + (dp2[i - 1][0] - dp2[i - 3][1] + mod) % mod) % mod;
        }
        dp3[0][1] = dp3[0][0] = dp3[0][2] = 1;
        dp3[1][0] = 3, dp3[1][1] = 3, dp3[1][2] = 2;
        dp3[2][0] = 3 + 2 + 3 - 1, dp3[2][1] = 8, dp3[2][2] = 4;
        for (int i = 1; i < n; i++) {
            dp3[i][2] = (dp2[i - 1][0] % mod + dp2[i - 1][1] % mod) % mod;
        }
        for (int i = 3; i < n; i++) {
            dp3[i][0] = (dp3[i - 1][1] % mod + dp3[i - 1][2] % mod + (dp3[i - 1][0] - (dp3[i - 3][1] + dp3[i - 3][2]) + mod) % mod) % mod;
            dp3[i][1] = (dp3[i - 1][1] % mod + dp3[i - 1][0] % mod + dp3[i - 1][2] % mod) % mod;
        }
        return (dp3[n - 1][0] + dp3[n - 1][1] + dp3[n - 1][2]) % mod;
    }
};

// @lc code=end
