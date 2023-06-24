/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end())
                return {i, map[target - nums[i]]};
            else {
                map.insert(std::pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};
// @lc code=end
