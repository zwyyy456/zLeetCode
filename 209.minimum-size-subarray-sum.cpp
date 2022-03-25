/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> subA;
        int left = 0;
        int right = 1;
        int len = 1;
        int sum = 0;
        for (len = 0; len <= nums.size(); len++) {
            for (left = 0, right = 0 + len; sum < target; left++, right++) {
                sum = 0;
                for (int i = left; i <= right; i++)
                    sum += nums[i];
            }
            return len;
        }
        return 0;

    }
};
// @lc code=end

