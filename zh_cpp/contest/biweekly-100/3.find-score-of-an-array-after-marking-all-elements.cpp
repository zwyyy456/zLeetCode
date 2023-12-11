// Created by Bob at 2023/03/18 22:55
// https://leetcode.cn/problems/find-score-of-an-array-after-marking-all-elements/
// https://leetcode.cn/contest/biweekly-contest-100/problems/find-score-of-an-array-after-marking-all-elements/

/*
6351. 标记所有元素后数组的分数 (Medium)

给你一个数组 `nums` ，它包含若干正整数。

一开始分数 `score = 0` ，请你按照下面算法求出最后分数：

- 从数组中选择最小且没有被标记的整数。如果有相等元素，选择下标最小的一个。
- 将选中的整数加到 `score` 中。
- 标记 **被选中元素**，如果有相邻元素，则同时标记 **与它相邻的两个元素** 。
- 重复此过程直到数组中所有元素都被标记。

请你返回执行上述算法后最后的分数。

**示例 1：**

```
输入：nums = [2,1,3,4,5,2]
输出：7
解释：我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[2,1,3,4,5,2] 。
- 2 是最小未标记元素，所以标记它和左边相邻元素：[2,1,3,4,5,2] 。
- 4 是仅剩唯一未标记的元素，所以我们标记它：[2,1,3,4,5,2] 。
总得分为 1 + 2 + 4 = 7 。

```

**示例 2：**

```
输入：nums = [2,3,5,1,3,2]
输出：5
解释：我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[2,3,5,1,3,2] 。
- 2 是最小未标记元素，由于有两个 2 ，我们选择最左边的一个 2 ，也就是下标为 0 处的 2
，以及它右边相邻的元素：[2,3,5,1,3,2] 。
- 2 是仅剩唯一未标记的元素，所以我们标记它：[2,3,5,1,3,2] 。
总得分为 1 + 2 + 2 = 5 。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁶`
*/

// @lc code=begin
#include <map>
#include <vector>
using std::vector;
using std::map;
class Solution {
  public:
    long long findScore(vector<int> &nums) {
        long score = 0;
        auto cmp = [&](int i, int j) {
            if (nums[i] == nums[j]) {
                return i < j;
            }
            return nums[i] < nums[j];
        };
        map<int, vector<int>, decltype(cmp)> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[i] = {i - 1, i + 1};
        }
        while (!mp.empty()) {
            auto iter = mp.begin();
            score += nums[iter->first];
            int left = (iter->second)[0];
            int right = (iter->second)[1];
            if (mp.find(left) != mp.end()) {
                mp.erase(left);
            }
            if (mp.find(right) != mp.end()) {
                mp.erase(right);
            }
        }
        return score;
    }
};

// @lc code=end
