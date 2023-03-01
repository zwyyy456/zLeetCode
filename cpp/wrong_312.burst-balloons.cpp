// Created by zwyyy456 at 2023/02/23 16:22
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
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>
#include <set>
using std::vector;
using std::set;
class Solution {
  public:
    int dfs(vector<int> &nums, set<int> &rset, set<int, std::greater<int>> &lset, vector<vector<vector<int>>> &cach, int n) {
        if (rset.size() == 2)
            return 0;
        int maxnum = 0; //应该说递归，转化为子问题的时候就出问题了，完全变成回溯了
        for (int i = 1; i <= n; i++) {
            auto iter = rset.find(i);
            if (iter != rset.end()) {
                int idx_left = *lset.upper_bound(i);
                int idx_right = *rset.upper_bound(i);
                if (cach[i][idx_left][idx_right] > 0) {
                    maxnum = std::max(maxnum, cach[i][idx_left][idx_right]);
                } else {
                    rset.erase(i);
                    lset.erase(i);
                    cach[i][idx_left][idx_right] = nums[i] * nums[idx_left] * nums[idx_right] + dfs(nums, rset, lset, cach, n);
                    maxnum = std::max(maxnum, cach[i][idx_left][idx_right]);
                    rset.insert(i);
                    lset.insert(i);
                }
            }
        }
        return maxnum;
    }
    int maxCoins(vector<int> &nums) {
        set<int> rset;
        set<int, std::greater<int>> lset;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            rset.insert(i);
            lset.insert(i);
        }
        vector<vector<vector<int>>> cach(nums.size(), vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1)));
        return dfs(nums, rset, lset, cach, n);
    }
};

// @lc code=end
