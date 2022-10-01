/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int sum_half = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i < nums.size() / 2)
                sum_half += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        for (int i = nums.size() / 2; i < nums.size(); i++) {
            if (sum_half == sum / 2)
                return true;
            sum_half += nums[i];
            if (sum_half > sum / 2)
                return false;
        }
        return false;
    }
};
// @lc code=end
