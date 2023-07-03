/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
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
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1])
                cnt++;
            else {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return intervals.size() - cnt;
    }
};
// @lc code=end
