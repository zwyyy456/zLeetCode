// Created by zwyyy456 at 2023/03/05 14:24
// https://leetcode.com/problems/find-peak-element/

/*
162. Find Peak Element (Medium)

A peak element is an element that is strictly greater than its neighbors.

Given a **0-indexed** integer array `nums`, find a peak element, and return its index. If the array
contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to
be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

**Example 2:**

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index
number 5 where the peak element is 6.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-2³¹ <= nums[i] <= 2³¹ - 1`
- `nums[i] != nums[i + 1]` for all valid `i`.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right && nums[left] < nums[left + 1] && nums[right] < nums[right - 1]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] < nums[mid - 1]) {
                right = mid - 1;;
            } else if ( nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
        }
        if (nums[left] > nums[left + 1]) {
            return left;
        }
        return right;
    }
};

// @lc code=end
