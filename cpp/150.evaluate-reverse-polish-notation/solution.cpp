// Created by zwyyy456 at 2023/04/30 16:31
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

/*
150. Evaluate Reverse Polish Notation (Medium)
You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse
Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return an integer that represents the value of the expression.

**Note** that:

- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncates toward zero**.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a **32-bit** integer.

**Example 1:**

```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

```

**Example 2:**

```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

```

**Example 3:**

```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

```

**Constraints:**

- `1 <= tokens.length <= 10⁴`
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200,
200]`.

*/

#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        int res = 0;
        stack<int> stk;
        int tmp1 = 0, tmp2 = 0;
        auto fun = [&stk, &tmp1, &tmp2]() {
            tmp1 = stk.top();
            stk.pop();
            tmp2 = stk.top();
            stk.pop();
        };
        for (auto &str : tokens) {
            if (str == "*") {
                fun();
                stk.push(tmp1 * tmp2);
            } else if (str == "-") {
                fun();
                stk.push(tmp2 - tmp1);
            } else if (str == "+") {
                fun();
                stk.push(tmp1 + tmp2);
            } else if (str == "/") {
                fun();
                stk.push(tmp2 / tmp1);
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> tokens;
    LeetCodeIO::scan(cin, tokens);

    Solution *obj = new Solution();

    auto res = obj->evalRPN(tokens);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
