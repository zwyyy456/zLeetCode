/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> result(k + 1, 0);
        int left = 0;
        int right = k;
        while (left <= right) {
            if (nums[left] * nums[left] >= nums[right] * nums[right]) {
                result[k] = nums[left] * nums[left];
                k--;
                left++;
            }
            else {
                result[k] = nums[right] * nums[right];
                k--;
                right--;
            }
        }
        return result;
        
    }
};
// @lc code=end

