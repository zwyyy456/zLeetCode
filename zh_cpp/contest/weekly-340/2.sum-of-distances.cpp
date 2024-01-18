// Created by Bob at 2023/04/09 10:55
// https://leetcode.cn/problems/sum-of-distances/
// https://leetcode.cn/contest/weekly-contest-340/problems/sum-of-distances/

/*
6360. 等值距离和 (Medium)

给你一个下标从 **0** 开始的整数数组 `nums` 。现有一个长度等于 `nums.length` 的数组
`arr` 。对于满足 `nums[j] == nums[i]` 且 `j != i` 的所有 `j` ，
`arr[i]` 等于所有 `|i - j|` 之和。如果不存在这样的 `j` ，则令 `arr[i]` 等于 `0`
。

返回数组 `arr` 。

**示例 1：**

```
输入：nums = [1,3,1,1,2]
输出：[5,0,3,4,0]
解释：
i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] =
|0 - 2| + |0 - 3| = 5 。
i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] =
|2 - 0| + |2 - 3| = 3 。
i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] =
|3 - 0| + |3 - 2| = 4 。
i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。

```

**示例 2：**

```
输入：nums = [0,5,3]
输出：[0,0,0]
解释：因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < nums.size(); ++i) {
            ump[nums[i]].push_back(i);
        }
        for (auto &p : ump) {
            auto &vec = p.second;
            int val = p.first;
            if (vec.size() == 1) {
                res[vec[0]] = 0;
                continue;
            }
            long long tmp = 0;
            vector<long long> prefix(vec.size() + 1);
            for (int i = 1; i <= vec.size(); ++i) {
                prefix[i] = prefix[i - 1] + nums[i - 1];
            }
            for (int i = 1; i <= vec.size(); ++i) {
                res[vec[i - 1]] = prefix[vec.size()] - 2 * prefix[i] + 2 * i * nums[i - 1] - n * nums[i - 1];
            }
        }
        return res;
    }
};

// @lc code=end
