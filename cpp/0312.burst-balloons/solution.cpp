// Created by zwyyy456 at 2023/02/22 17:44
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
#include <functional>
#include <set>
#include <vector>
using std::vector;
using std::set;
class Solution {
  public:
    int dfs(vector<int> &nums, set<int> &rset, vector<vector<vector<int>>> &cach) {
        if (rset.empty())
            return 0;
        int maxnum = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = rset.find(i);
            if (iter != rset.end()) { // 说明i没有被选择过
                auto iter_right = iter;
                iter--;
                iter_right++;
                if (iter == rset.end()) {           // 左边没有数了
                    if (iter_right == rset.end()) { // 右边已经没有数了
                        if (cach[i][300][300] >= 0) {
                            return cach[i][300][300];
                        } else {
                            rset.erase(i);
                            cach[i][300][300] = nums[i] + dfs(nums, rset, cach);
                            maxnum = std::max(maxnum, cach[i][300][300]);
                            rset.insert(i);
                        }
                    } else { // 左边没有数，但是右变还有数
                        int idx_right = *iter_right;
                        if (cach[i][300][idx_right] >= 0) {
                            return cach[i][300][idx_right];
                        } else {
                            rset.erase(i);
                            cach[i][300][idx_right] = nums[i] * nums[idx_right] + dfs(nums, rset, cach);
                            maxnum = std::max(maxnum, cach[i][300][idx_right]);
                            rset.insert(i);
                        }
                    }
                } else {
                    int idx_left = *iter;           // 左边有数
                    if (iter_right == rset.end()) { // 右边已经没有数了
                        if (cach[i][idx_left][300] >= 0) {
                            return cach[i][idx_left][300];
                        } else {
                            rset.erase(i);
                            cach[i][idx_left][300] = nums[i] + dfs(nums, rset, cach);
                            maxnum = std::max(maxnum, cach[i][idx_left][300]);
                            rset.insert(i);
                        }
                    } else { // 左边右边都有数
                        int idx_right = *iter_right;
                        if (cach[i][idx_left][idx_right] >= 0) {
                            return cach[i][idx_left][idx_right];
                        } else {
                            rset.erase(i);
                            cach[i][idx_left][idx_right] = nums[i] * nums[idx_right] + dfs(nums, rset, cach);
                            maxnum = std::max(maxnum, cach[i][idx_left][idx_right]);
                            rset.insert(i);
                        }
                    }
                }
            }
        }
        return maxnum;
    }
    int maxCoins(vector<int> &nums) {
        set<int> rset;
        for (int i = 0;i < nums.size(); i++) {
            rset.insert(i);
        }
        set<int, std::greater<int>> left_set;
        vector<vector<vector<int>>> cach(300, vector<vector<int>>(301, vector<int>(301, -1)));
        return dfs(nums, rset, cach);
    }
};

// @lc code=end
