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
        vector<vector<int>> nums;
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++)
                nums[0][j] = j + 1;
            for (int j = 0; j < i; j++)
                nums[j][i - 1] = nums[0][j] + i - 1;
            for (int j = 0; j < i; j++)
                nums[i - 1]
        }
};
// @lc code=end

