// Created by zwyyy456 at 2023/02/27 09:04
// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

/*
1144. Decrease Elements To Make Array Zigzag (Medium)

Given an array `nums` of integers, a move consists of choosing any element and **decreasing it by
1**.

An array `A` is a zigzag array if either:

- Every even-indexed element is greater than adjacent elements, ie. `A[0] > A[1] < A[2] > A[3] <
A[4] > ...`
- OR, every odd-indexed element is greater than adjacent elements, ie. `A[0] < A[1] > A[2] < A[3] >
A[4] < ...`

Return the minimum number of moves to transform the given array `nums` into a zigzag array.

**Example 1:**

```
Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.

```

**Example 2:**

```
Input: nums = [9,6,1,6,2]
Output: 4

```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int movesToMakeZigzag(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;
        // 考虑偶数索引大的情况
        int cnt2 = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            if (i + 1 < nums.size() && i - 1 >= 0) {
                int tmp = std::min(nums[i + 1], nums[i - 1]);
                if (tmp <= nums[i]) {
                    cnt2 += nums[i] - tmp + 1;
                }
            } else if (i + 1 >= nums.size()) {
                if (nums[i - 1] <= nums[i]) {
                    cnt2 += nums[i] - nums[i - 1] + 1;
                }
            } else {
                if (nums[i + 1] <= nums[i]) {
                    cnt2 += nums[i] - nums[i + 1] + 1;
                }
            }
        }
        // 考虑奇数索引大的情况
        int cnt4 = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            if (i + 1 < nums.size() && i - 1 >= 0) {
                int tmp = std::min(nums[i + 1], nums[i - 1]);
                if (tmp <= nums[i]) {
                    cnt4 += nums[i] - tmp + 1;
                }
            } else if (i + 1 >= nums.size()) {
                if (nums[i - 1] <= nums[i]) {
                    cnt4 += nums[i] - nums[i - 1] + 1;
                }
            } else {
                if (nums[i + 1] <= nums[i]) {
                    cnt4 += nums[i] - nums[i + 1] + 1;
                }
            }
        }
        return std::min(cnt2, cnt4);
    }
};

// @lc code=end
