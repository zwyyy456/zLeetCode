/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int tmp = 0, index = 0;
        int l = 0, r = nums.size() - 1;
        while (index <= r) {
            if (nums[index] == 0) {
                tmp = nums[l];
                nums[l++] = 0;
                nums[index++] = tmp;
            } else if (nums[index] == 2) {
                tmp = nums[r];
                nums[r--] = 2;
                nums[index] = tmp;
            } else
                index++;
        }
    }
};
// @lc code=end
