// Created by Bob at 2023/05/16 09:21
// https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/

/*
1335. 工作计划的最低难度 (Hard)
你需要制定一份 `d` 天的工作计划表。工作之间存在依赖，要想执
行第 `i` 项工作，你必须完成全部 `j` 项工作（ `0 <= j < i`）
。

你每天 **至少** 需要完成一项任务。工作计划的总难度是这 `d`
天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大
难度。

给你一个整数数组 `jobDifficulty` 和一个整数 `d`，分别代表工
作难度和需要计划的天数。第 `i` 项工作的难度是 `jobDifficulty
[i]`。

返回整个工作计划的 **最小难度** 。如果无法制定工作计划，则返
回 **-1**。

**示例 1：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/
2020/01/26/untitled.png)

```
输入：jobDifficulty = [6,5,4,3,2,1], d = 2
输出：7
解释：第一天，您可以完成前 5 项工作，总难度 = 6.
第二天，您可以完成最后一项工作，总难度 = 1.
计划表的难度 = 6 + 1 = 7

```

**示例 2：**

```
输入：jobDifficulty = [9,9,9], d = 4
输出：-1
解释：就算你每天完成一项工作，仍然有一天是空闲的，你无法制定
一份能够满足既定工作时间的计划表。

```

**示例 3：**

```
输入：jobDifficulty = [1,1,1], d = 3
输出：3
解释：工作计划为每天一项工作，总难度为 3 。

```

**示例 4：**

```
输入：jobDifficulty = [7,1,7,1,7,1], d = 3
输出：15

```

**示例 5：**

```
输入：jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
输出：843

```

**提示：**

- `1 <= jobDifficulty.length <= 300`
- `0 <= jobDifficulty[i] <= 1000`
- `1 <= d <= 10`

*/

#include <bits/stdc++.h>
#include <climits>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        if (d > jobDifficulty.size()) {
            return -1;
        }
        // 动态规划
        // 维护一个 后缀最大值数组
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));
        dp[0][0] = 0;
        vector<vector<int>> max_diff(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            max_diff[i][i] = jobDifficulty[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                max_diff[i][j] = max(max_diff[i][j - 1], jobDifficulty[j - 1]);
                // cout << max_diff[i][j] << endl;
            }
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max_diff[1][i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i && j <= d; ++j) {
                for (int k = j; k <= i; ++k) {
                    // cout << k << " " << j << " " << i << endl;
                    dp[i][j] = min(dp[k - 1][j - 1] + max_diff[k][i], dp[i][j]);
                    // cout << dp[i][j] << " " << i << " " << j << " " << k << endl;
                }
            }
        }
        // cout << dp[2][2] << " dp[2][2]" << endl;
        return dp[n][d];
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> jobDifficulty;
    LeetCodeIO::scan(cin, jobDifficulty);
    int d;
    LeetCodeIO::scan(cin, d);

    Solution *obj = new Solution();

    auto res = obj->minDifficulty(jobDifficulty, d);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
