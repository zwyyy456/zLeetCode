// Created by zwyyy456 at 2023/04/21 15:57
// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

/*
1723. Find Minimum Time to Finish All Jobs (Hard)
You are given an integer array `jobs`, where `jobs[i]` is the amount of time it takes to complete
the `ith` job.

There are `k` workers that you can assign jobs to. Each job should be assigned to **exactly** one
worker. The **working time** of a worker is the sum of the time it takes to complete all jobs
assigned to them. Your goal is to devise an optimal assignment such that the **maximum working
time** of any worker is **minimized**.

Return the **minimum** possible **maximum working time** of any assignment.

**Example 1:**

```
Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.

```

**Example 2:**

```
Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
```

**Constraints:**

- `1 <= k <= jobs.length <= 12`
- `1 <= jobs[i] <= 10⁷`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int cal(vector<int> &jobs, int chose, int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & chose) != 0) {
                res += jobs[i];
            }
        }
        return res;
    }
    int minimumTimeRequired(vector<int> &jobs, int k) {
        int n = jobs.size();
        std::sort(jobs.begin(), jobs.end());
        // 状态压缩+记忆化搜索
        // 很明显每个人都有工作肯定优于有人没有工作
        // 说明一个人最多选n - k + 1个
 		// 直接 dp
 		vector<vector<int>> dp(1 << n, vector<int>(k + 1)); // dp[i][j] 表示前 j 个人分配工作情况为 i 时的最小值
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); ++i) {
            sum[i] = cal(jobs, i, n);
        }
        for (int i = 1; i < (1 << n); ++i) {
            dp[i][1] = cal(jobs, i, n);
        }
 		for (int i = 1; i < (1 << n); ++i) {
 			for (int j = 2; j <= k; ++j) {
                int tmp = INT_MAX;
 				for (int chose = 1; chose <= i; ++chose) {
 					if ((chose & i) == chose) {
 					    tmp = min(tmp, max(dp[i ^ chose][j - 1], sum[i]));	
 					}
 				}
                dp[i][j] = tmp;
 			}
 		}
        return dp[(1 << n) - 1][k];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> jobs;
    LeetCodeIO::scan(cin, jobs);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->minimumTimeRequired(jobs, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
