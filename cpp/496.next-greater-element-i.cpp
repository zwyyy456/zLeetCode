// Created by zwyyy456 at 2023/03/18 11:31
// https://leetcode.com/problems/next-greater-element-i/

/*
496. Next Greater Element I (Easy)

The **next greater element** of some element `x` in an array is the **first greater** element that
is **to the right** of `x` in the same array.

You are given two **distinct 0-indexed** integer arrays `nums1` and `nums2`, where `nums1` is a
subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine
the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the
answer for this query is `-1`.

Return an array  `ans` of length  `nums1.length` such that  `ans[i]` is the **next greater element**
as described above.

**Example 1:**

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

```

**Example 2:**

```
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

```

**Constraints:**

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 10⁴`
- All integers in `nums1` and `nums2` are **unique**.
- All the integers of `nums1` also appear in `nums2`.

**Follow up:** Could you find an `O(nums1.length + nums2.length)` solution?
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // 直接用vector作为单调栈
        vector<int> stk;
        vector<int> next(10001, -1);
        // 从右往左遍历nums2
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stk.empty() && nums2[i] > stk.back()) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                next[nums2[i]] = stk.back();
            }
            stk.push_back(nums2[i]);
        }
        // 遍历nums1
        for (int &i : nums1) {
            i = next[i];
        }
        return nums1;
    }
};

// @lc code=end
