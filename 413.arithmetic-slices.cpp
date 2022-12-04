/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3)
            return 0;
        int dif = nums[1] - nums[0];
        int len = 2;
        int cnt = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == dif)
                len++;
            else {
                if (len >= 3)
                    cnt += (len - 2) * (len - 1) / 2;
                len = 2;
                dif = nums[i] - nums[i - 1];
            }
        }
        if (len >= 3)
            cnt += (len - 2) * (len - 1) / 2;
        return cnt;
    }
};
// @lc code=end
