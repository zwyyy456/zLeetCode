/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
#include <stack>
#include <string>
using std::stack;
using std::string;
class Solution {
  public:
    bool checkValidString(string s) {
        // 如何标识这是第一个'('
        int flag = 1;
        stack<char> stk;
        int arr[3] = {0};  // ()*
        int diff_flag = 0; // 为零表示能满足条件
        for (char c : s) {
            if (c == '(') {
                if (flag == 0) { // 说明前面必然不是'('，且前面必然有')'
                    if (arr[0] > arr[1] + arr[2] || arr[2] > arr[0] + arr[1])
                        diff_flag = 1;
                    else {
                        arr[1] -= abs(arr[2] - arr[0]);
                    }
                    if (diff_flag != 0)
                        return false;
                }
                stk.push(c);
                flag = 1;
                arr[0]++;
            } else if (c == ')') {
                if (stk.empty())
                    return false;
                else if (stk.top() == '(') {
                    stk.pop();
                    arr[0]--;
                } else {
                    flag = 0; // 说明已经出现'('
                    stk.push(c);
                    arr[1]++;
                }

            } else {
                stk.push(c);
                arr[2]++;
            }
        }
        if (arr[0] > arr[1] + arr[2] || arr[2] > arr[0] + arr[1])
            return false;
        else
            return true;
    }
};
// @lc code=end
