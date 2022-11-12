/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int jump(vector<int> &nums) {
        int cur_end = nums.size() - 1;
        int cnt = 0;
        while (cur_end != 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] + i >= cur_end) {
                    cur_end = i;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
