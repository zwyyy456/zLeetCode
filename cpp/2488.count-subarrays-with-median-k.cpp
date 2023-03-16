// Created by zwyyy456 at 2023/03/16 09:13
// https://leetcode.com/problems/count-subarrays-with-median-k/

/*
2488. Count Subarrays With Median K (Hard)

You are given an array `nums` of size `n` consisting of **distinct** integers from `1` to `n` and a
positive integer `k`.

Return the number of non-empty subarrays in  `nums` that have a **median** equal to  `k`.

**Note**:

- The median of an array is the **middle** element after sorting the array in **ascending** order.
If the array is of even length, the median is the **left** middle element.

  - For example, the median of `[2,3,1,4]` is `2`, and the median of `[8,4,3,5,1]` is `4`.
- A subarray is a contiguous part of an array.

**Example 1:**

```
Input: nums = [3,2,1,4,5], k = 4
Output: 3
Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].

```

**Example 2:**

```
Input: nums = [2,3,1], k = 3
Output: 1
Explanation: [3] is the only subarray that has a median equal to 3.

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10⁵`
- `1 <= nums[i], k <= n`
- The integers in `nums` are distinct.
*/

// @lc code=begin
#include <unordered_map>
#include <vector>
using std::vector;
class Solution {
  public:
    int countSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        // 将数组中大于k的数置为1，小于k的数置为-1
        int idx_k = 0; // 找k所在的坐标
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < k) {
                nums[i] = -1;
            } else if (nums[i] > k) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
                idx_k = i;
            }
        }
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = idx_k - 1, x = 0; i >= 0; --i) {
            x += nums[i] > k ? 1 : -1;
            ++cnt[x];
        }
        int ans = cnt[0] + cnt[1];
        for (int i = idx_k + 1, x = 0; i < n; ++i) {
            x += nums[i] > k ? 1 : -1;
            ans += cnt[x] + cnt[x - 1];
        }
        return ans;
    }
};

// @lc code=end
