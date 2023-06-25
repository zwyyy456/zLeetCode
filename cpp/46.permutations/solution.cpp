/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    int used[6] = {0};
    void track_back(vector<int> &nums) {
        if (path.size() >= nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1)
                continue;
            used[i] = 1;
            path.push_back(nums[i]);
            track_back(nums);
            path.pop_back();
            used[i] = 0;
        }
        return;
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        int used[6] = {0};
        track_back(nums);
        return res;
    }
};
// @lc code=end
