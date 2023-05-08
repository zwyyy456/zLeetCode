// Created by zwyyy456 at 2023/05/08 09:39
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

/*
857. Minimum Cost to Hire K Workers (Hard)
There are `n` workers. You are given two integer arrays `quality` and `wage` where `quality[i]` is
the quality of the `ith` worker and `wage[i]` is the minimum wage expectation for the `ith` worker.

We want to hire exactly `k` workers to form a paid group. To hire a group of `k` workers, we must
pay them according to the following rules:

1. Every worker in the paid group should be paid in the ratio of their quality compared to other
workers in the paid group.
2. Every worker in the paid group must be paid at least their minimum wage expectation.

Given the integer `k`, return the least amount of money needed to form a paid group satisfying the
above conditions. Answers within `10-⁵` of the actual answer will be accepted.

**Example 1:**

```
Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2ⁿd worker.

```

**Example 2:**

```
Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2ⁿd and 3rd workers separately.

```

**Constraints:**

- `n == quality.length == wage.length`
- `1 <= k <= n <= 10⁴`
- `1 <= quality[i], wage[i] <= 10⁴`

*/

#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        // frac 表示单位质量的工资 frac[i] = wage[i] / quality[i];
        int n = quality.size();
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        vector<double> frac(n);
        for (int i = 0; i < n; ++i) {
            frac[i] = static_cast<double>(wage[i]) / quality[i];
        }
        sort(indexes.begin(), indexes.end(), [&quality, &wage](int i, int j) {
            return wage[i] * quality[j] < wage[j] * quality[i];
        });
        double ans = 0;
        auto cmp = [&quality](int i, int j) {
            return quality[i] < quality[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < k; ++i) {
            int id = indexes[i];
            ans += static_cast<double>(quality[id]) * frac[indexes[k - 1]];
            pq.push(id);
        }
        for (int i = k; i < n; ++i) {
            int cur_id = indexes[i];
            if (quality[cur_id] < quality[pq.top()]) {
                pq.pop();
                ans = min(ans, ans + quality[cur_id] * frac[cur_id] - quality[pq.top()] * frac[indexes[i - 1]]);
                pq.push(cur_id);
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> quality;
    LeetCodeIO::scan(cin, quality);
    vector<int> wage;
    LeetCodeIO::scan(cin, wage);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->mincostToHireWorkers(quality, wage, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
