/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    void track_back(vector<int> &nums, int index) {
        res.push_back(path);
        if (index >= nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            track_back(nums, i + 1);
            path.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return;
    }

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        track_back(nums, 0);
        return res;
    }
};
// @lc code=end
