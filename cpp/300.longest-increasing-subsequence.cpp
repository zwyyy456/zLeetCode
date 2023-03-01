// Created by zwyyy456 at 2023/02/23 15:47
// https://leetcode.com/problems/longest-increasing-subsequence/

/*
300. Longest Increasing Subsequence (Medium)

Given an integer array `nums`, return the length of the longest **strictly
increasing****subsequence**.

**Example 1:**

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

```

**Example 2:**

```
Input: nums = [0,1,0,3,2,3]
Output: 4

```

**Example 3:**

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1

```

**Constraints:**

- `1 <= nums.length <= 2500`
- `-10⁴ <= nums[i] <= 10⁴`

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?
*/

// @lc code=begin

#include <vector>
using std::vector;
class Solution {
  public:
    int GetIdx(vector<int> &min_len_tail, int len, int target) {
        int left = 1, right = len;
        int mid = left + (right - left) / 2;
        while (left < right) {
            if (min_len_tail[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }
    int lengthOfLIS(vector<int> &nums) {
        // 贪心，要让序列上升得尽可能慢
        // 先找到第一个波谷
        int n = nums.size();
        vector<int> min_len_tail(n + 1, nums[0]); // min_len_tail[i]表示长度为i的上升子序列的末尾元素的最小值
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > min_len_tail[len]) {
                min_len_tail[++len] = nums[i];
            } else {
                int idx = GetIdx(min_len_tail, len, nums[i]);
                min_len_tail[idx] = nums[i];
            }
        }
        return len;
    }
};

// @lc code=end
