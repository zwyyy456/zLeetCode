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
        for (len = 1; len <= nums.size(); len++) {
            sum = 0;
            for (int i = 0; i < len; i++)
                sum += nums[i];
            if (sum >= target)
                return len;
            for (left = 1, right = 1 + len; right <= nums.size(); left++, right++) {
                sum = sum + nums[right - 1] -nums[left - 1];
                if (sum >= target)
                    return len;
            }
        }
        return 0;
    }
};
// @lc code=end

