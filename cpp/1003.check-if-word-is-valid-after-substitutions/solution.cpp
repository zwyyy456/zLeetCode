// Created by zwyyy456 at 2023/05/04 09:24
// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

/*
1003. Check If Word Is Valid After Substitutions (Medium)
Given a string `s`, determine if it is **valid**.

A string `s` is **valid** if, starting with an empty string `t = ""`, you can **transform** `t`
**into** `s` after performing the following operation **any number of times**:

- Insert string `"abc"` into any position in `t`. More formally, `t` becomes `tₗₑfₜ + "abc" +
trᵢgₕₜ`, where `t == tₗₑfₜ + trᵢgₕₜ`. Note that `tₗₑfₜ` and `trᵢgₕₜ` may be **empty**.

Return `true`if  `s` is a **valid** string, otherwise, return `false`.

**Example 1:**

```
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
```

**Example 2:**

```
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

```

**Example 3:**

```
Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

```

**Constraints:**

- `1 <= s.length <= 2 * 10⁴`
- `s` consists of letters `'a'`, `'b'`, and `'c'`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isValid(string s) {
        // 大概是用栈来模拟
        stack<char> stk;
        for (auto c : s) {
            if (c == 'c') {
                if (stk.size() < 2) {
                    return false;
                }
                if (stk.top() == 'b') {
                    stk.pop();
                    if (stk.top() == 'a') {
                        stk.pop();
                    } else {
                        stk.push('b');
                        stk.push('c');
                    }
                } else {
                    stk.push(c);
                }
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->isValid(s);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
