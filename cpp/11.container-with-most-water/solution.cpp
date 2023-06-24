/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            if (height[l] >= height[r]) {
                res = max(res, (r - l) * height[r]);
                r--; // 因为此时，增加l只可能缩小res，所以减少r
            } else {
                res = max(res, (r - l) * height[l]);
                l++; // height[l] < height[r], 此时减少r也只会缩小res，所以增加l
            }
        }
        return res;
    }
};
// @lc code=end

