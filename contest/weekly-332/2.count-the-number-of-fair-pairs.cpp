// Created by Bob at 2023/02/12 14:16
// https://leetcode.com/problems/count-the-number-of-fair-pairs/
// https://leetcode.com/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/

/*
2563. Count the Number of Fair Pairs (Medium)

Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return
the number of fair pairs.
A pair `(i, j)` is **fair** if:
- `0 <= i < j < n`, and
- `lower <= nums[i] + nums[j] <= upper`
**Example 1:**
```
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
```
**Example 2:**
```
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
```
**Constraints:**
- `1 <= nums.length <= 10⁵`
- `nums.length == n`
- `-10⁹ <= nums[i] <= 10⁹`
- `-10⁹ <= lower <= upper <= 10⁹`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int LowerBound(vector<int> &nums, int i, int target) {
        int l = i + 1;
        int r = nums.size();
        int mid = l + (r - l) / 2;
        while (l < r) {
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }
        return l;
    }
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        if (nums.size() == 1)
            return 0;
        std::sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = 0; i < nums.size() - 1; i++) { // 还需要去重
            if (nums[i] + nums[i + 1] > upper)
                break;
            else {
                if (nums[i] + nums[nums.size() - 1] < lower)
                    continue;
                else {
                    int l = LowerBound(nums, i, lower - nums[i]);
                    if (nums[l] > upper - nums[i])
                        continue;
                    int r = LowerBound(nums, i, upper - nums[i] + 1); // 存在upper - nums[i] + 1
                    r--;
                    if (r >= l)
                        res += r - l + 1;
                }
            }
        }
        return res;
    }
};

// @lc code=end
