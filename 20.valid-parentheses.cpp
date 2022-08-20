/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stack>
#include <string>
using std::stack;
using std::string;
class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        char temp;
        for (char c : s) {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            //碰到右括号时栈为空或者上一个字符不是对应的左括号
            else if (st.empty() || c != st.top())
                return false;
            else
                st.pop(); //括号匹配时出栈
        }
        return st.empty();
    }
};
// @lc code=end
