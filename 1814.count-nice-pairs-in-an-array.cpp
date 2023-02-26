/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
class Solution {
  public:
    int rev(int num) {
        vector<int> tmp;
        int ans = 0;
        while (num != 0) {
            tmp.push_back(num % 10);
            num /= 10;
        }
        for (int i = 0; i < tmp.size(); i++) {
            ans = ans * 10 + tmp[i];
        }
        return ans;
    }
    int countNicePairs(vector<int> &nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - rev(nums[i])]++;
        }
        long long ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans += (long long)it->second * (it->second - 1) / 2;
        }
        return ans % (1000000007);
    }
};
// @lc code=end
