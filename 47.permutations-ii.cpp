/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    int used[8] = {0};
    void track_back(vector<int> nums, int index) {
        if (path.size() >= nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
                continue;
            if (used[i] == 1)
                continue;
            path.push_back(nums[i]);
            used[i] = 1;
            track_back(nums, 0);
            path.pop_back();
            used[i] = 0;
        }
        return;
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        track_back(nums, 0);
        return res;
    }
};
// @lc code=end
