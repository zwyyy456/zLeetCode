/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::sort;
using std::vector;
class Solution {
  private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int result = 1;
        sort(points.begin(), points.end(), cmp);
        for (int i = 1; i < points.size(); i++) {
            if (points[i - 1][1] < points[i][0])
                result++;
            else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return result;
    }
};
// @lc code=end
