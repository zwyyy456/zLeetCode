/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n, vector<int>(n, 0));
        int num = 0;
        for (int i = n; i > 0; i = i - 2) {
            for (int j = 0; j < i - 1; j++)
                nums[(n - i) / 2][j + (n - i) / 2] = ++num;
            for (int j = 0; j < i -1; j++)
                nums[j + (n - i) / 2][i - 1 + (n - i) / 2] = ++num;
            for (int j = i; j > 1; j--)
                nums[i - 1 + (n - i) / 2][j - 1 + (n - i) / 2] = ++num;
            for (int j = i; j > 1; j--)
                nums[j - 1 + (n - i) / 2][(n - i) / 2] = ++num;
        }
        return nums;
    }
};
// @lc code=end
