/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] < intervals[i][0])
                res.push_back(intervals[i]);
            else {
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
                res[res.size() - 1][1] = intervals[i][1];
            }
        }
        return res;
    }
};
// @lc code=end
