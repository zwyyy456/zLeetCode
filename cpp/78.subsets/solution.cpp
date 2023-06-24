/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    void track_back(vector<int> &nums, int index) {
        if (index >= nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);
            track_back(nums, i + 1);
            path.pop_back();
        }
        return;
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        res.push_back(path);
        track_back(nums, 0);
        return res;
    }
};
// @lc code=end
