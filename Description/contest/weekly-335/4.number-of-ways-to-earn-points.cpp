// Created by Bob at 2023/03/05 10:30
// https://leetcode.cn/problems/number-of-ways-to-earn-points/
// https://leetcode.cn/contest/weekly-contest-335/problems/number-of-ways-to-earn-points/

/*
6310. 获得分数的方法数 (Hard)

考试中有 `n` 种类型的题目。给你一个整数 `target` 和一个下标从 **0** 开始的二维整数数组
`types` ，其中 `types[i] = [countᵢ, marksᵢ] ` 表示第 `i` 种类型的题目有
`countᵢ` 道，每道题目对应 `marksᵢ` 分。

返回你在考试中恰好得到 `target` 分的方法数。由于答案可能很大，结果需要对 `10⁹ +7` 取余。

**注意**，同类型题目无法区分。

- 比如说，如果有 `3` 道同类型题目，那么解答第 `1` 和第 `2` 道题目与解答第 `1` 和第 `3`
道题目或者第 `2` 和第 `3` 道题目是相同的。

**示例 1：**

```
输入：target = 6, types = [[6,1],[3,2],[2,3]]
输出：7
解释：要获得 6 分，你可以选择以下七种方法之一：
- 解决 6 道第 0 种类型的题目：1 + 1 + 1 + 1 + 1 + 1 = 6
- 解决 4 道第 0 种类型的题目和 1 道第 1 种类型的题目：1 + 1 + 1 + 1 + 2 = 6
- 解决 2 道第 0 种类型的题目和 2 道第 1 种类型的题目：1 + 1 + 2 + 2 = 6
- 解决 3 道第 0 种类型的题目和 1 道第 2 种类型的题目：1 + 1 + 1 + 3 = 6
- 解决 1 道第 0 种类型的题目、1 道第 1 种类型的题目和 1 道第 2 种类型的题目：1 + 2 + 3 =
6
- 解决 3 道第 1 种类型的题目：2 + 2 + 2 = 6
- 解决 2 道第 2 种类型的题目：3 + 3 = 6

```

**示例 2：**

```
输入：target = 5, types = [[50,1],[50,2],[50,5]]
输出：4
解释：要获得 5 分，你可以选择以下四种方法之一：
- 解决 5 道第 0 种类型的题目：1 + 1 + 1 + 1 + 1 = 5
- 解决 3 道第 0 种类型的题目和 1 道第 1 种类型的题目：1 + 1 + 1 + 2 = 5
- 解决 1 道第 0 种类型的题目和 2 道第 1 种类型的题目：1 + 2 + 2 = 5
- 解决 1 道第 2 种类型的题目：5

```

**示例 3：**

```
输入：target = 18, types = [[6,1],[3,2],[2,3]]
输出：1
解释：只有回答所有题目才能获得 18 分。

```

**提示：**

- `1 <= target <= 1000`
- `n == types.length`
- `1 <= n <= 50`
- `types[i].length == 2`
- `1 <= countᵢ, marksᵢ <= 50`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    long combine(int n, int m) {
        if (n == m || m == 0) {
            return 1;
        }
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i && j <= m; j++) {
                if (i == j || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mod = 1000000007;
        vector<vector<long>> dp(target + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1];
                for (int k = 0; k <= types[j - 1][0]; ++k) {
                    int pick = k * types[j - 1][1]; // 表示types[n - 1]选k个
                    if (i >= pick) {
                        dp[i][j] = (dp[i][j] + dp[i - pick][j - 1] * combine(types[j - 1][0], k)) % mod;
                    }
                }
            }
        }
        return dp[target][n] % mod;
    }
};

// @lc code=end
