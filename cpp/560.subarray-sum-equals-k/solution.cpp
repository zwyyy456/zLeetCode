// Created by zwyyy456 at 2023/03/07 15:13
// https://leetcode.com/problems/subarray-sum-equals-k/

/*
560. Subarray Sum Equals K (Medium)

Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum
equals to `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2

```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2

```

**Constraints:**

- `1 <= nums.length <= 2 * 10⁴`
- `-1000 <= nums[i] <= 1000`
- `-10⁷ <= k <= 10⁷`
*/

// @lc code=begin
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        vector<int> prefix(nums.size() + 1);
        std::unordered_map<int, int> ump;
        ump[0] = 1;
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            if (ump.find(prefix[i] - k) != ump.end()) {
                res += ump[prefix[i] - k];
            }
            ++ump[prefix[i]];
        }
        return res;
    }
};

// @lc code=end
