/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>
using std::stack;
using std::string;
using std::vector;
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int tmp1, tmp2;
        for (string s : tokens) {
            if (s == "/" || s == "+" || s == "*" || s == "-") {
                if (s == "/") {
                    tmp1 = getTop(stk);
                    tmp2 = getTop(stk);
                    stk.push(tmp2 / tmp1);
                } else if (s == "+") {
                    tmp1 = getTop(stk);
                    tmp2 = getTop(stk);
                    stk.push(tmp2 + tmp1);
                } else if (s == "*") {
                    tmp1 = getTop(stk);
                    tmp2 = getTop(stk);
                    stk.push(tmp2 * tmp1);
                } else if (s == "-") {
                    tmp1 = getTop(stk);
                    tmp2 = getTop(stk);
                    stk.push(tmp2 - tmp1);
                }
            } else {
                int tmp = std::stoi(s);
                stk.push(tmp);
            }
        }
        return getTop(stk);
    }
    int getTop(stack<int> &st) {
        int temp = st.top();
        st.pop();
        return temp;
    }
};
// @lc code=end
