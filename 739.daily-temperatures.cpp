/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <stack>
#include <vector>
using std::stack;
using std::vector;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            int j = i;
            // if (!st.empty()) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
            // }
        }
        return res;
    }
};
// @lc code=end
