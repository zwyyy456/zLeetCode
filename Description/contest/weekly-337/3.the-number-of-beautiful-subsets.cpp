// Created by Bob at 2023/03/19 10:49
// https://leetcode.cn/problems/the-number-of-beautiful-subsets/
// https://leetcode.cn/contest/weekly-contest-337/problems/the-number-of-beautiful-subsets/

/*
6352. 美丽子集的数目 (Medium)

给你一个由正整数组成的数组 `nums` 和一个 **正** 整数 `k` 。

如果 `nums` 的子集中，任意两个整数的绝对差均不等于 `k` ，则认为该子数组是一个 **美丽** 子集。

返回数组 `nums` 中 **非空** 且 **美丽** 的子集数目。

`nums` 的子集定义为：可以经由 `nums`
删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。

**示例 1：**

```
输入：nums = [2,4,6], k = 2
输出：4
解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
可以证明数组 [2,4,6] 中只存在 4 个美丽子集。

```

**示例 2：**

```
输入：nums = [1], k = 1
输出：1
解释：数组 nums 中的美丽数组有：[1] 。
可以证明数组 [1] 中只存在 1 个美丽子集。

```

**提示：**

- `1 <= nums.length <= 20`
- `1 <= nums[i], k <= 1000`
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
class Solution {
  public:
    int dfs(int idx, int sta, unordered_map<int, int> &cnt, vector<int> &nums, unordered_map<int, int> &cmp) {
        if (idx >= nums.size()) {
            if (sta != 0) {
                return 1;
            }
            return 0;
        }
        int res = 0;
        if ((sta & (~cnt[idx])) == cnt[idx]) {
            res += dfs(idx + 1, sta, cnt, nums, cmp) + dfs(idx + 1, sta | (1 << idx), cnt, nums, cmp);
        } else {
            res += dfs(idx + 1, sta, cnt, nums, cmp);
        }
        return res;
    } 
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, int> cnt; // 表示每个值对应的
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]] |= (1 << i);
        }
        unordered_map<int, int> cmp;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt.find(nums[i] + k) != cnt.end()) {
                cmp[i] |= cnt[nums[i] + k];
            }
            if (cnt.find(nums[i] - k) != cnt.end()) {
                cmp[i] |= cnt[nums[i] - k];
            }
        }
        return dfs(0, 0, cnt, nums, cmp);
    }
};

// @lc code=end
