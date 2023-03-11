// Created by zwyyy456 at 2023/03/10 09:04
// https://leetcode.com/problems/make-sum-divisible-by-p/

/*
1590. Make Sum Divisible by P (Medium)

Given an array of positive integers `nums`, remove the **smallest** subarray (possibly **empty**)
such that the **sum** of the remaining elements is divisible by `p`. It is **not** allowed to remove
the whole array.

Return the length of the smallest subarray that you need to remove, or  `-1` if it's impossible.

A **subarray** is defined as a contiguous block of elements in the array.

**Example 1:**

```
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the
subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

```

**Example 2:**

```
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to
remove the subarray [5,2], leaving us with [6,3] with sum 9.

```

**Example 3:**

```
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove
anything.

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁹`
- `1 <= p <= 10⁹`
*/

// @lc code=begin
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = (prefix[i - 1] + nums[i - 1]) % p;
        }
        int mod = prefix[n] % p;
        if (mod == 0) {
            return 0;
        }
        unordered_map<int, int> ump;
        ump[0] = 0;
        int res = n;
        for (int i = 1; i <= n; ++i) {
            int tmp_mod = prefix[i] % p;
            ump[tmp_mod] = i;
            if (ump.find((tmp_mod - mod + p) % p) != ump.end()) {
                res = std::min(res, i - ump[(tmp_mod - mod + p) % p]);
            }
        }
        if (res == n) {
            return -1;
        }
        return res;
    }
};

// @lc code=end
