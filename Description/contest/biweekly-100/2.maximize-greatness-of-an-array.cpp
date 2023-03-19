// Created by Bob at 2023/03/18 22:55
// https://leetcode.cn/problems/maximize-greatness-of-an-array/
// https://leetcode.cn/contest/biweekly-contest-100/problems/maximize-greatness-of-an-array/

/*
6324. 最大化数组的伟大值 (Medium)

给你一个下标从 0 开始的整数数组 `nums` 。你需要将 `nums` 重新排列成一个新的数组 `perm` 。

定义 `nums` 的 **伟大值** 为满足 `0 <= i < nums.length` 且 `perm[i] >
nums[i]` 的下标数目。

请你返回重新排列 `nums` 后的 **最大** 伟大值。

**示例 1：**

```
输入：nums = [1,3,5,2,1,3,1]
输出：4
解释：一个最优安排方案为 perm = [2,5,1,3,3,1,1] 。
在下标为 0, 1, 3 和 4 处，都有 perm[i] > nums[i] 。因此我们返回 4 。
```

**示例 2：**

```
输入：nums = [1,2,3,4]
输出：3
解释：最优排列为 [2,3,4,1] 。
在下标为 0, 1 和 2 处，都有 perm[i] > nums[i] 。因此我们返回 3 。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁹`
*/

// @lc code=begin

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        
    }
};

// @lc code=end
