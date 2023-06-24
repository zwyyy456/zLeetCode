/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int fast = 1;
        int slow = 0;
        for (slow = 0; slow < nums.size(); slow++) {
            while (fast < nums.size() && nums[fast] == nums[fast - 1])
                fast++;
            if (fast == nums.size())
                break;
            nums[slow + 1] = nums[fast++];
        }
        return slow + 1;
    }
};
// @lc code=end
