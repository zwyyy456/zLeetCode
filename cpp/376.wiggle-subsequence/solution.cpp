/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int wiggleMaxLength(vector<int> &nums) {
        int first = nums[0];
        int pre = 0;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (pre == 0) { // pre == 0说明之前i之前的数都是一个定值
                if (nums[i] > nums[i - 1]) {
                    pre = 1;
                    len++;
                } else if (nums[i] < nums[i - 1]) {
                    pre = -1;
                    len++;
                }
            } else if (pre == 1) {
                if (nums[i] < nums[i - 1]) {
                    len++;
                    pre = -1;
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    len++;
                    pre = 1;
                }
            }
        }
        return len;
    }
};
// @lc code=end
