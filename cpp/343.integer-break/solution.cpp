/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int get_max(int a, int b) {
        return a > b ? a : b;
    }
    int integerBreak(int n) {
        vector<int> res(n);
        if (n == 1 || n == 4)
            return n;
        else if (n == 2 || n == 3)
            return 1 * (n - 1);
        else {
            for (int i = 0; i < 4; i++)
                res[i] = i + 1;
            for (int i = 4; i < n; i++) {
                res[i] = get_max(res[i - 3] * 3, res[i - 4] * 4);
            }
            return res[n - 1];
        }
    }
};
// @lc code=end
