/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        vector<vector<int>> res(nums.size() + 1, vector<int>(k + 1, 0));
        res[1][1] = 1;
        int r = 0;
        // 先找到第一个长度为k的子数组
        while (r < nums.size()) {
            mp[nums[r]]++;
            if (mp.size() == k - 1)
                break;
            r++;
        }
        // 如果直接运动到了数组末端
        if (r == nums.size()) {
                return 0;
        }
        res[r + 1][k - 1] = 1;
        int i = 0;
        for (i = 0; i < r; i++) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                break;
        }
        for (int r = k, l = 0; r < nums.size() && r - l >= k - 1; r++) {
            mp[nums[r]]++;
            if (mp.size() > k) {
                while (mp.size() > k) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0)
                        mp.erase(nums[l]);
                    l++;
                } 
                res[r + 1][k] = res[r][k];
            } else if (mp.size() == k) {
                res[r + 1][k] = res[r][k] + res[r][k - 1];
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            ans += res[i][k];
        }
        return ans;
    }
};
// @lc code=end

