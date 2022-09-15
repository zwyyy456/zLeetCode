/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    void back_track(int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int start_index =)
    }

  public:
    vector<vector<int>> combine(int n, int k) {
    }
};
// @lc code=end
