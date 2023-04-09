// Created by Bob at 2023/04/09 10:55
// https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/
// https://leetcode.cn/contest/weekly-contest-340/problems/minimize-the-maximum-difference-of-pairs/

/*
6359. 最小化数对的最大差值 (Medium)

给你一个下标从 **0** 开始的整数数组 `nums` 和一个整数 `p` 。请你从 `nums` 中找到 `p`
个下标对，每个下标对对应数值取差值，你需要使得这 `p` 个差值的 **最大值**
**最小**。同时，你需要确保每个下标在这 `p` 个下标对中最多出现一次。

对于一个下标对 `i` 和 `j` ，这一对的差值为 `|nums[i] - nums[j]|` ，其中 `|x|`
表示 `x` 的 **绝对值** 。

请你返回 `p` 个下标对对应数值 **最大差值** 的 **最小值** 。

**示例 1：**

```
输入：nums = [10,1,2,7,1,3], p = 2
输出：1
解释：第一个下标对选择 1 和 4 ，第二个下标对选择 2 和 5 。
最大差值为 max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0,
1) = 1 。所以我们返回 1 。

```

**示例 2：**

```
输入：nums = [4,2,1,2], p = 1
输出：0
解释：选择下标 1 和 3 构成下标对。差值为 |2 - 2| = 0 ，这是最大差值的最小值。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁹`
- `0 <= p <= (nums.length)/2`
*/

// @lc code=begin
#include <queue>
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1);
        std::priority_queue<int> pq;
        // 先要让pq.size() == p
        for (int i = 0; i < )
        for (int i = 2; i <= n; ++i) {
            // if (nums[i - 1] - nums[i - 2] <= pq.top()) {
            //     if (pq.size() >= p) {
            //         pq.pop();
            //         pq.push(nums[i - 1] - nums[i - 2]);
            //     }
            // }
            if (nums[i - 1] - nums[i - 2] < dp[i - 2]) {

            }
        }

    }
};

// @lc code=end
