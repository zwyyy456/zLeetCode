// Created by zwyyy456 at 2023/03/28 10:22
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

/*
442. Find All Duplicates in an Array (Medium)

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1,
n]` and each integer appears **once** or **twice**, return an array of all the integers that appears
**twice**.

You must write an algorithm that runs in `O(n) ` time and uses only constant extra space.

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]

```

**Example 3:**

```
Input: nums = [1]
Output: []

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10⁵`
- `1 <= nums[i] <= n`
- Each element in `nums` appears **once** or **twice**.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int num = abs(nums[i]);
            if (num > nums.size()) {
                num -= nums.size();
            }
            if (nums[num - 1] > 0) {
                nums[num - 1] = -nums[num - 1];
            } else {
                nums[num - 1] -= nums.size();
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < -static_cast<int>(nums.size())) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// @lc code=end
