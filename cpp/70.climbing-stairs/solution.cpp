/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int climbStairs(int n) {
        int cnt[2] = {1, 1};
        if (n == 1)
            return 1;
        for (int i = 1; i < n; i++) {
            int sum = cnt[0] + cnt[1];
            cnt[0] = cnt[1];
            cnt[1] = sum;
        }
        return cnt[1];
    }
    int climb_stair_m(int m, int n) { // m为可以选的步数
        vector<int> cnt(m + 1);
        vector<int> sum(m + 1);
        cnt[0] = cnt[1] = 1;
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; i++) {
                }
    }
};
// @lc code=end
