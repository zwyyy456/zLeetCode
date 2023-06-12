// Created by zwyyy456 at 2023/05/18 10:16
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

/*
1190. Reverse Substrings Between Each Pair of Parentheses (Medium)
You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.

**Example 1:**

```
Input: s = "(abcd)"
Output: "dcba"

```

**Example 2:**

```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

```

**Example 3:**

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

```

**Constraints:**

- `1 <= s.length <= 2000`
- `s` only contains lower case English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

*/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string reverseParentheses(string s) {
        stack<char> stk;
        // string ans;
        for (auto c : s) {
            if (c != ')') {
                stk.push(c);
            } else {
                vector<char> tmp;
                while (stk.top() != '(') {
                    tmp.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                reverse(tmp.begin(), tmp.end());
                while (!tmp.empty()) {
                    stk.push(tmp.back());
                    tmp.pop_back();
                }
            }
        }
        vector<char> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        string ans(res.begin(), res.end());
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->reverseParentheses(s);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
