// Created by zwyyy456 at 2023/02/23 19:38
// https://leetcode.com/problems/burst-balloons/

/*
312. Burst Balloons (Hard)

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it
represented by an array `nums`. You are asked to burst all the balloons.

If you burst the `ith` balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1`
or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1`
painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

**Example 1:**

```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

**Example 2:**

```
Input: nums = [1,5]
Output: 10

```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `0 <= nums[i] <= 100`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    //     保证子问题之间不存在依赖， 分治：递归搜索+保存计算结果
    //     int dfs(vector<int> &nums, int left, int right, vector<vector<int>> &cach) {
    //         if (left >= right) {
    //             return 0;
    //         }
    //         int maxnum = 0;
    //         for (int i = left + 1; i < right; i++) {
    //             if (cach[left][right] > 0)
    //                 return cach[left][right];
    //             else
    //                 maxnum = std::max(maxnum, nums[left] * nums[i] * nums[right] + dfs(nums, left, i, cach) + dfs(nums, i, right, cach));
    //         }
    //         cach[left][right] = maxnum;
    //         return maxnum;
    //     }
    //     int maxCoins(vector<int> &nums) {
    //         nums.insert(nums.begin(), 1);
    //         nums.push_back(1);
    //         int n = nums.size();
    //         vector<vector<int>> cach(n, vector<int>(n, 0));
    //         return dfs(nums, 0, n - 1, cach);
    //     }
    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = 0; r < n; r++) {
                for (int mid = l + 1; mid < r; mid++) {
                    dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid][r] + nums[mid] * nums[l] * nums[r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
