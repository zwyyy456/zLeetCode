// Created by Bob at 2023/03/12 10:31
// https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/
// https://leetcode.cn/contest/weekly-contest-336/problems/count-the-number-of-beautiful-subarrays/

/*
6317. 统计美丽子数组数目 (Medium)

给你一个下标从 **0** 开始的整数数组 `nums` 。每次操作中，你可以：

- 选择两个满足 `0 <= i, j < nums.length` 的不同下标 `i` 和 `j` 。
- 选择一个非负整数 `k` ，满足 `nums[i]` 和 `nums[j]` 在二进制下的第 `k` 位（下标编号从
**0** 开始）是 `1` 。
- 将 `nums[i]` 和 `nums[j]` 都减去 `2k` 。

如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 `0` 的数组，那么我们称它是一个 **美丽**
的子数组。

请你返回数组 `nums` 中 **美丽子数组** 的数目。

子数组是一个数组中一段连续 **非空** 的元素序列。

**示例 1：**

```
输入：nums = [4,3,1,2,4]
输出：2
解释：nums 中有 2 个美丽子数组：[4,3,1,2,4] 和 [4,3,1,2,4] 。
- 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
  - 选择 [3, 1, 2] 和 k = 1 。将 2 个数字都减去 2¹ ，子数组变成 [1, 1, 0] 。
  - 选择 [1, 1, 0] 和 k = 0 。将 2 个数字都减去 2⁰ ，子数组变成 [0, 0, 0] 。
- 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
  - 选择 [4, 3, 1, 2, 4] 和 k = 2 。将 2 个数字都减去 2² ，子数组变成 [0, 3,
1, 2, 0] 。
  - 选择 [0, 3, 1, 2, 0] 和 k = 0 。将 2 个数字都减去 2⁰ ，子数组变成 [0, 2,
0, 2, 0] 。
  - 选择 [0, 2, 0, 2, 0] 和 k = 1 。将 2 个数字都减去 2¹ ，子数组变成 [0, 0,
0, 0, 0] 。

```

**示例 2：**

```
输入：nums = [1,10,4]
输出：0
解释：nums 中没有任何美丽子数组。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁶`
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
class Solution {
  public:
    long long beautifulSubarrays(vector<int> &nums) {
        // vector<int> cnt(21, 0);
        // 如果这个子数组，所有的元素第k位的值之和为偶数，且对任意0 <= k <= 20都成立，则该数组是美丽子数组
        // 我们用数来表示前k个数的前缀和，例如01001，表示前k个数，第0位之和为奇数，第3位之和为奇数，其余都是偶数
        // 哈希表+前缀和数组
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        long res = 0;
        // unordered_map<int, vector<int, int>> cnt; // 统计前缀和出现的次数，以及最近一次的坐标
        unordered_map<int, int> cnt; // 前缀和出现的次数
        unordered_map<int, int> idx; //最近一次出现的坐标
        cnt[0] = 1;
        idx[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = (prefix[i - 1] ^ nums[i - 1]);
            if (cnt.find(prefix[i]) != cnt.end()) { // 说明这个键在两个哈希表中
                if (idx[prefix[i]] == i - 1) {
                    res += cnt[prefix[i]] - 1;
                } else {
                    res += cnt[prefix[i]];
                }
            }
            // 更新哈希表
            ++cnt[prefix[i]];
            idx[prefix[i]] = i;
        }
        return res;
    }
};

// @lc code=end
