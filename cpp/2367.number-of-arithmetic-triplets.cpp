// Created by zwyyy456 at 2023/03/31 15:27
// https://leetcode.com/problems/number-of-arithmetic-triplets/

/*
2367. Number of Arithmetic Triplets (Easy)

You are given a **0-indexed**, **strictly increasing** integer array `nums` and a positive integer
`diff`. A triplet `(i, j, k)` is an **arithmetic triplet** if the following conditions are met:

- `i < j < k`,
- `nums[j] - nums[i] == diff`, and
- `nums[k] - nums[j] == diff`.

Return the number of unique **arithmetic triplets**.

**Example 1:**

```
Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.

```

**Example 2:**

```
Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.

```

**Constraints:**

- `3 <= nums.length <= 200`
- `0 <= nums[i] <= 200`
- `1 <= diff <= 50`
- `nums` is **strictly** increasing.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int Bsearch(vector<int> &nums, int target, int idx) {
        int left = idx + 1, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int mid = Bsearch(nums, nums[i] + diff, i);
            int right = Bsearch(nums, nums[i] + 2 * diff, i);
            if (right < n && mid < right) {
                if (nums[mid] == nums[i] + diff && nums[right] == nums[i] + 2 * diff) {
                    ++res;
                }
            }
        }
        return res;
    }   
};

// @lc code=end
