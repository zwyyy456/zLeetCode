/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
#include <stack>
#include <vector>
using std::stack;
using std::vector;
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        stk.push(0);
        int j = 0;
        for (int i = 1; i < 2 * nums.size(); i++) {
            if (i >= nums.size()) {
                j = i - nums.size();
                while (!stk.empty() && nums[j] > nums[stk.top()]) {
                    res[stk.top()] = nums[j];
                    stk.pop();
                }
                stk.push(j);
            } else {
                while (!stk.empty() && nums[i] > nums[stk.top()]) {
                    res[stk.top()] = nums[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return res;
    }
};
// @lc code=end
