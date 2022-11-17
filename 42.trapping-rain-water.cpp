/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <stack>
#include <vector>
using std::stack;
using std::vector;
class Solution {
  public:
    int trap(vector<int> &height) {
        stack<int> stk;
        stk.push(0);
        int res = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int h = min(height[i], height[stk.top()]) - height[mid];
                    int w = i - stk.top() - 1;
                    res += h * w;
                }
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end
