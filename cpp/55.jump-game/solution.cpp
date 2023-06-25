/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int r = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            while (i >= 0 && nums[i] + i >= r) {
                r = i;
                i--;
            }
        }
        if (r != 0)
            return false;
        else
            return true;
    }
};
// @lc code=end
