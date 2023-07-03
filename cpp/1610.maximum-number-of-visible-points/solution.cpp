/*
 * @lc app=leetcode id=1610 lang=cpp
 *
 * [1610] Maximum Number of Visible Points
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <vector>
using std::max;
using std::min;
using std::vector;
class Solution {
  public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        vector<float> point_angle(points.size(), 0);
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == location[0]) {
                if (points[i][1] > location[1])
                    point_angle[i] = 90;
                else if (points[i][1] == location[1])
                    point_angle[i] = 361; // 用来标记这是一个重叠的点
                else
                    point_angle[i] = -90;
            } else {
                point_angle[i] = atan2(points[i][1] - location[1], points[i][0] - location[0]) * 180 / M_PI;
            }
        }
        int cnt = 0;
        std::sort(point_angle.begin(), point_angle.end());
        for (int i = point_angle.size() - 1; i >= 0; i--) {
            if (point_angle[i] > 360) {
                point_angle.pop_back();
                cnt++;
            }
        }
        int ans = 0;
        vector<float> angle2(point_angle.size() * 2, 0);
        for (int i = 0; i < point_angle.size(); i++) {
            angle2[i] = point_angle[i];
            angle2[i + point_angle.size()] = point_angle[i] + 2 * M_PI;
        }

        int l = 0;

        for (int r = 0; r < angle2.size(); r++) {
            if (angle2[r] - angle2[l] > angle)
                while (l <= r && angle2[r] - angle2[l] > angle)
                    l++;
            else
                ans = max(ans, r - l + 1);
        }
        return ans + cnt;
    }
};
// @lc code=end
