/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int mcmp(int a, int b, int target) {
        if (abs(a - target) < abs(b - target))
            return true;
        else
            return false;
    }

  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2]; // 记录三数之和
        for (int i = 0; i < nums.size() - 2; i++) {
            // 跳过重复的
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == target)
                    return target;
                else if (nums[i] + nums[l] + nums[r] < target) {
                    if (mcmp(nums[i] + nums[l] + nums[r], sum, target))
                        sum = nums[i] + nums[l] + nums[r];
                    while (l < nums.size() - 2 && nums[l] == nums[l + 1])
                        l++;
                    l++;
                } else {
                    if (mcmp(nums[i] + nums[l] + nums[r], sum, target))
                        sum = nums[i] + nums[l] + nums[r];
                    while (r > 2 && nums[r] == nums[r - 1])
                        r--;
                    r--;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
