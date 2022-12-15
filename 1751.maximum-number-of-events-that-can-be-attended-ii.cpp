/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    int maxValue(vector<vector<int>> &events, int k) {
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, 0));
        // 按照会议结束顺序排序
        std::sort(events.begin(), events.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        // for (int i = 1; i <= events.size(); i++) {
        //     dp[i][1] = events[i - 1][2];
        // }
        for (int i = 1; i <= events.size(); i++) {
            for (int j = 1; j <= k; j++) {
                int tmp1 = dp[i - 1][j]; // 不包含event[i - 1]的情况
                int find_idx = 0;
                int l = 0;
                int r = i - 2;
                for (; l <= r && r >= 0;) {
                    int mid = l + (r - l) / 2;
                    if (events[mid][1] >= events[i - 1][0]) {
                        r = mid - 1;
                        // mid = l + (r - l) / 2;
                    } else {
                        l = mid + 1;
                        // mid = l + (r - l) / 2;
                    }
                }
                // if (l == 0)
                //     dp[i][j] = std::max(tmp1, events[i - 1][2]);
                // else
                dp[i][j] = std::max(tmp1, dp[l][j - 1] + events[i - 1][2]);
            }
        }
        return dp[events.size()][k];
    }
};
// @lc code=end
