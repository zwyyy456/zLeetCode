// Created by zwyyy456 at 2023/04/30 16:45
// https://leetcode.com/problems/parsing-a-boolean-expression/

/*
1106. Parsing A Boolean Expression (Hard)
A **boolean expression** is an expression that evaluates to either `true` or `false`. It can be in
one of the following shapes:

- `'t'` that evaluates to `true`.
- `'f'` that evaluates to `false`.
- `'!(subExpr)'` that evaluates to **the logical NOT** of the inner expression `subExpr`.
- `'&(subExpr₁, subExpr₂, ..., subExprₙ)'` that evaluates to **the logical AND** of the inner
expressions `subExpr₁, subExpr₂, ..., subExprₙ` where `n >= 1`.
- `'|(subExpr₁, subExpr₂, ..., subExprₙ)'` that evaluates to **the logical OR** of the inner
expressions `subExpr₁, subExpr₂, ..., subExprₙ` where `n >= 1`.

Given a string `expression` that represents a **boolean expression**, return the evaluation of that
expression.

It is **guaranteed** that the given expression is valid and follows the given rules.

**Example 1:**

```
Input: expression = "&(|(f))"
Output: false
Explanation:
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.

```

**Example 2:**

```
Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.

```

**Example 3:**

```
Input: expression = "!(&(f,t))"
Output: true
Explanation:
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

```

**Constraints:**

- `1 <= expression.length <= 2 * 10⁴`
- expression\[i\] is one following characters: `'('`, `')'`, `'&'`, `'|'`, `'!'`, `'t'`, `'f'`, and
`','`.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        stack<char> letter;
        for (auto &c : expression) {
            if (c == '&' || c == '|' || c == '!') {
                stk.push(c);
            } else if (c == '(') {
                letter.push(c);
            } else if (c == ')') {
                auto op = stk.top();
                stk.pop();
                if (op == '!') {
                    auto res = letter.top();
                    letter.pop();
                    letter.pop();
                    letter.push(res == 'f' ? 't' : 'f');
                } else if (op == '|') {
                    char res = 'f';
                    while (letter.top() != '(') {
                        auto let = letter.top();
                        if (let == 't') {
                            res = 't';
                        }
                        letter.pop();
                    }
                    letter.pop();
                    letter.push(res);
                } else {
                    char res = 't';
                    while (letter.top() != '(') {
                        auto let = letter.top();
                        if (let == 'f') {
                            res = 'f';
                        }
                        letter.pop();
                    }
                    letter.pop();
                    letter.push(res);
                }
            } else if (c == 't' || c == 'f'){
            	letter.push(c);
            }
        }
        return letter.top() == 't';
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string expression;
    LeetCodeIO::scan(cin, expression);

    Solution *obj = new Solution();

    auto res = obj->parseBoolExpr(expression);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
