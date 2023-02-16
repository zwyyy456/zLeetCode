// Created by Bob at 2023/02/16 10:49
// https://leetcode.com/problems/increasing-triplet-subsequence/

/*
334. Increasing Triplet Subsequence (Medium)

Given an integer array `nums`, return `true` if there exists a triple of indices  `(i, j, k)` such
that  `i < j < k` and  `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.
**Example 1:**
```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```
**Example 2:**
```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```
**Example 3:**
```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```
**Constraints:**
- `1 <= nums.length <= 5 * 10⁵`
- `-2³¹ <= nums[i] <= 2³¹ - 1`
**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space
complexity?
*/

// @lc code=begin
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int left = nums[0], mid = nums[0], right = nums[0];
        if (nums.size() < 3)
            return false;
        int i = 0;
        while (i < nums.size() && nums[i] <= left) {
            left = nums[i];
            ++i;
        }
        if (i >= nums.size() - 1)
            return false;
        mid = nums[i++];
        while (i < nums.size() && nums[i] <= mid) {
            if (nums[i] > left) {
                mid = nums[i];
            } else { // nums[i] <= left，此时考虑nums[i + 1]，如果nums[i + 1]
                int left2 = nums[i];
                ++i;
                while (i < nums.size() && nums[i] <= left2) {
                    ++i;
                }
                if (i == nums.size())
                    return false;
                // 此时nums[i] > left2
                if (nums[i] > mid)
                    return true;
                mid = nums[i];
            }
            ++i;
        }
        return i < nums.size();
    }
};

// @lc code=end
