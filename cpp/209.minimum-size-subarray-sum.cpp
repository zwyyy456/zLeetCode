// Created by zwyyy456 at 2023/03/05 15:05
// https://leetcode.com/problems/minimum-size-subarray-sum/

/*
209. Minimum Size Subarray Sum (Medium)

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal
length** of a subarray whose sum is greater than or equal to `target`. If there is no such subarray,
return `0` instead.

**Example 1:**

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

```

**Example 2:**

```
Input: target = 4, nums = [1,4,4]
Output: 1

```

**Example 3:**

```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

```

**Constraints:**

- `1 <= target <= 10⁹`
- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁴`

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution of which the
time complexity is `O(n log(n))`.
*/

// @lc code=begin
#include <functional>
#include <vector>
#include <numeric>
#include <map>
using std::map;
using std::vector;
class Solution {
  public:
    int BSearch(int idx, int target, vector<int> &prefix) {
        int left = 0, right = idx;
        // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] < prefix[idx] - target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int minSubArrayLen(int target, vector<int> &nums) {
        // 前缀和
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        // 二分查找
        int res = n + 1;
        for (int i = 1; i <= n; i++) {
            int j = BSearch(i, target - 1, prefix);
            if (prefix[i] >= target) {
                // if (prefix[j] == prefix[i] - target)
                //     res = std::min(i - j, res);
                // else {
                res = std::min(i - j + 1, res);
            }
        }
        if (res == n + 1) {
            return 0;
        }
        return res;
    }
};
// @lc code=end
