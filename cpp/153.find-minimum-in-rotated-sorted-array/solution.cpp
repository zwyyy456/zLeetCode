// Created by zwyyy456 at 2023/03/04 12:11
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
153. Find Minimum in Rotated Sorted Array (Medium)

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times.
For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated `4` times.
- `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array
`[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return the minimum element of this
array.

You must write an algorithm that runs in `O(log n) time.`

**Example 1:**

```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

```

**Example 3:**

```
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are **unique**.
- `nums` is sorted and rotated between `1` and `n` times.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int findMin(vector<int> &nums) {
        // 二分答案
        // 假设新数组是由原来的数组旋转k次得到的（1 <= k <= 7）
        // 那么所有结果为nums[0 + k]
        int n = nums.size();
        // 旋转k次，新数组的nums[0]是原数组的nums[n - k]
        int left = 0, right = n - 1;
        int mid = left + (right - left) / 2;
        // 反向旋转mid次
        while (left <= right) {
            // nums[0]对应origin[n - k]，nums[mid]对应origin[mid - k]或者origin[mid + n - k]
            // 取决于mid是否大于k
            if (nums[0] > nums[mid]) { // 说明mid >= k, mid = k时，仍有nums[0] > nums[mid % n]
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        return nums[left % n];
    }
};

// @lc code=end
