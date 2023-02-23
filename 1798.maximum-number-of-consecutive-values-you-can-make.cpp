/*
 * @lc app=leetcode id=1798 lang=cpp
 *
 * [1798] Maximum Number of Consecutive Values You Can Make
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        std::sort(coins.begin(), coins.end());
        vector<int> res(coins.size() + 1, 0); // 表示前n个数能表示出来的最大值
        for (int i = 1; i <= coins.size(); i++) { 
            if (coins[i - 1] > res[i - 1] + 1)
                res[i] = res[i - 1];
            else
                res[i] = res[i - 1] + coins[i - 1];
        }
        return res[coins.size()] + 1;
    }
};

// @lc code=end

