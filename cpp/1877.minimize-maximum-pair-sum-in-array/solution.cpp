/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, nums[i] + nums[nums.size() - 1 - i]);
        }
        return res;
    }
};
// @lc code=end
