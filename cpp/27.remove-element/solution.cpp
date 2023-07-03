/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            while (fast < nums.size() && nums[fast] == val)
                fast++;
            if (fast == nums.size())
                break;
            nums[slow++] = nums[fast];
        }
        return slow;
    }
};
// @lc code=end
