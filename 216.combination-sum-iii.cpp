/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> path;
    vector<vector<int>> res;
    void back_track(int k, int n, int index) {
        if (path.size() == k) {
            int sum = 0;
            for (int i = 0; i < k; i++)
                sum += path[i];
            if (n == sum)
                res.push_back(path);
            return;
        }
        for (int j = index; j <= 10 - (k - path.size()); j++) {
            path.push_back(j);
            back_track(k, n, j + 1);
            path.pop_back();
        }
        return;
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        back_track(k, n, 1);
        return res;
    }
};
// @lc code=end
