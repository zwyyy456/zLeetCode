// Created by zwyyy456 at 2023/03/18 12:04
// https://leetcode.com/problems/next-greater-element-ii/

/*
503. Next Greater Element II (Medium)

Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is
`nums[0]`), return the **next greater number** for every element in `nums`.

The **next greater number** of a number `x` is the first greater number to its traversing-order next
in the array, which means you could search circularly to find its next greater number. If it doesn't
exist, return `-1` for this number.

**Example 1:**

```
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

```

**Example 2:**

```
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

```

**Constraints:**

- `1 <= nums.length <= 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
#include <stack>
using std::vector;
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> nums2(2 * nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            nums2[i] = nums[i];
            nums2[i + nums.size()] = nums[i];
        }
        std::unordered_map<int, int> next;
        std::stack<int> stk;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums2[i] >= stk.top()) {
                stk.pop();
            }
            if (!stk.empty()) {
                if (next.find(nums2[i]) == next.end()) {
                    next[nums2[i]] = stk.top();
                }
            }
            stk.push(nums2[i]);
        }
        for (int &i : nums) {
            if (next.find(i) != next.end()) {
                i = next[i];
            } else {
                i = -1;
            }
        }
        return nums;
    }
};

// @lc code=end
