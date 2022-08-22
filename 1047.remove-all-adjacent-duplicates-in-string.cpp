/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
#include <stack>
#include <string>
using std::stack;
using std::string;
class Solution {
  public:
    string removeDuplicates(string s) {
        string st;
        char temp;
        for (char c : s) {
            if (st.empty() || st.back() != c)
                st.push_back(c);
            else {
                st.pop_back();
            }
        }
        return st;
    }
};

// @lc code=end
