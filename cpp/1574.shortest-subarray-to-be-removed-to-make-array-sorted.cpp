// Created by zwyyy456 at 2023/03/25 12:17
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

/*
1574. Shortest Subarray to be Removed to Make Array Sorted (Medium)

Given an integer array `arr`, remove a subarray (can be empty) from `arr` such that the remaining
elements in `arr` are **non-decreasing**.

Return the length of the shortest subarray to remove.

A **subarray** is a contiguous subsequence of the array.

**Example 1:**

```
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements
after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

```

**Example 2:**

```
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we
need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

```

**Example 3:**

```
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.

```

**Constraints:**

- `1 <= arr.length <= 10⁵`
- `0 <= arr[i] <= 10⁹`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int Bsearch(vector<int> &len_min, int len, int target) {
        int left = 1, right = len; // 左闭右闭
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (len_min[mid] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 先求从左到右的长度的对应的值
        vector<int> l2r(arr.size() + 1, -1);
        int l_len = 0;
        for (int i = 1; i <= arr.size(); ++i) {
            if (arr[i - 1] >= l2r[i - 1]) {
                ++l_len;
                l2r[l_len] = arr[i - 1];
            } else {
                break;
            }
        }
        int r_len = 0;
        vector<int> r2l(arr.size() + 1, INT_MAX);
        for (int i = arr.size(); i > 0; --i) {
            if (arr[i - 1] <= r2l[r_len]) {
                ++r_len;
                r2l[r_len] = arr[i - 1];
            } else {
                break;
            }
        }
        int len = r_len;
        for (int i = 1; i <= l_len; ++i) {
            len = std::max(len, i + Bsearch(r2l, r_len, l2r[i]));
            if (len >= arr.size()) {
                return 0;
            }
        }
        return arr.size() - len;
    }
};

// @lc code=end
