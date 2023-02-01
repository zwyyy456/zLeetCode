/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int minSum(int ans, int n, int index) {
        int sum = 0;
        if (index + 1 <= ans)
            sum += (index + 1) * (2 * ans - index) / 2;
        else {
            sum += (1 + ans) * ans / 2 + index + 1 - ans;
        }
        if (n - index - 1 <= ans - 1)
            sum += (n - index - 1) * (2 * ans - n + index) / 2;
        else
            sum += ans * (ans - 1) / 2 + n - index - ans;
        return sum;
    }
    int maxValue(int n, int index, int maxSum) {
        int ans = 1;
        int res = 0;
        int sum = 0;
        // 二分法
        if (n == 1)
            return maxSum;
        else {
            int l = 1, r = maxSum / 2 + 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (minSum(mid, n, index) > maxSum) {
                    r = mid - 1;
                } else if (minSum(mid, n, index) == maxSum)
                    return mid;
                else {
                    l = mid + 1;
                }
            }
            return r;
        }
    }
};
// @lc code=end
