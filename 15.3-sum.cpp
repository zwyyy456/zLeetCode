/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
// using std::sort;
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 1, j = nums.size() - 1;
        if (nums[0] > 0 || nums[nums.size() - 1] < 0)
            return res;
        for (int k = 0; k < nums.size() - 2; k++) {
            //跳过重复的值，注意防止数组溢出
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            i = k + 1;
            j = nums.size() - 1;
            if (nums[k] + nums[i] + nums[j] > 0) {
                j--;
                //跳过重复的值，同时注意i<j的限定条件
                while (nums[j + 1] == nums[j] && i < j - 1)
                    j--;
            } else if (nums[k] + nums[i] + nums[j] < 0) {
                i++;
                //跳过重复的值，同时注意i<j的限定条件
                while (nums[i - 1] == nums[i] && i < j - 1)
                    i++;
            } else {
                res.push_back({nums[k], nums[i], nums[j]});
                j--;
                while (nums[j + 1] == nums[j] && i < j - 1)
                    j--;
                i++;
                while (nums[i - 1] == nums[i] && i < j - 1)
                    i++;
            }
        }
        return res;
    }
};
// @lc code=end
