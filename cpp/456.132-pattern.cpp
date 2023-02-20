// Created by Bob at 2023/02/16 13:02
// https://leetcode.com/problems/132-pattern/

/*
456. 132 Pattern (Medium)

Given an array of `n` integers `nums`, a **132 pattern** is a subsequence of three integers
`nums[i]`, `nums[j]` and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.
Return `true` if there is a **132 pattern** in  `nums`, otherwise, return  `false`.
**Example 1:**
```
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```
**Example 2:**
```
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
```
**Example 3:**
```
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
```
**Constraints:**
- `n == nums.length`
- `1 <= n <= 2 * 10⁵`
- `-10⁹ <= nums[i] <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <stack>
#include <algorithm>
using std::stack;
using std::vector;
class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int first = nums[0], second = nums[nums.size() - 1], third = -INT_MAX;
        int i = 0;
        stack<int> stk; // 栈顶到栈底从小到大
        stk.push(nums[nums.size() - 1]);
        for (int r = nums.size() - 2; r >= 0; r--) {
            // 栈应该不可能为空
            if (nums[r] < stk.top()) {
                // if (stk.top() > third) {
                if (nums[r] < third) {
                    return true;
                    // }
                }
                stk.push(nums[r]);
            } else if (nums[r] == stk.top()) {
                stk.push(nums[r]);
            } else {
                while (!stk.empty() && nums[r] > stk.top()) {
                    third = std::max(stk.top(), third);
                    stk.pop();
                }
                stk.push(nums[r]);
            }
        }
        return false;
    }
};

// @lc code=end
