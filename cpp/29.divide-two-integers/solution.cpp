/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
  public:
    int divide(int dividend, int divisor) {
        
        int res = 0;
        if (dividend == 0)
            return 0;
        else if (dividend > 0) {
            if (divisor > 0) {
                int tmp = divisor;
                while (tmp <= dividend) {
                    tmp += divisor;
                    res++;
                }
            } else if (divisor < 0) {
                int tmp = -divisor;
                while (tmp <= dividend) {
                    tmp -= divisor;
                    res--;
                }
            }
        } else {
            if (divisor > 0) {
                int tmp = divisor;
                while (tmp <= -dividend) {
                    tmp += divisor;
                    res--;
                }
            } else if (divisor < 0) {
                int tmp = -divisor;
                while (tmp <= -dividend) {
                    tmp -= divisor;
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
