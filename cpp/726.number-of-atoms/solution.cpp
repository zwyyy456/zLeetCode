// Created by zwyyy456 at 2023/05/19 10:16
// https://leetcode.com/problems/number-of-atoms/

/*
726. Number of Atoms (Hard)
Given a string `formula` representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters,
representing the name.

One or more digits representing that element's count may follow if the count is greater than `1`. If
the count is `1`, no digits will follow.

- For example, `"H2O"` and `"H2O2"` are possible, but `"H1O2"` is impossible.

Two formulas are concatenated together to produce another formula.

- For example, `"H2O2He3Mg4"` is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

- For example, `"(H2O2)"` and `"(H2O2)3"` are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted
order), followed by its count (if that count is more than `1`), followed by the second name (in
sorted order), followed by its count (if that count is more than `1`), and so on.

The test cases are generated so that all the values in the output fit in a **32-bit** integer.

**Example 1:**

```
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

```

**Example 2:**

```
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

```

**Example 3:**

```
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

```

**Constraints:**

- `1 <= formula.length <= 1000`
- `formula` consists of English letters, digits, `'('`, and `')'`.
- `formula` is always valid.

*/

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string countOfAtoms(string formula) {
        // 栈
        stack<pair<string, int>> stk;
        int n = formula.size();
        for (int i = 0; i < n; ++i) {
            char c = formula[i];
            if (c == '(') {
                string tmp;
                tmp.push_back(c);
                stk.push({tmp, 1});
            } else if (c == ')') {
                int scale = 0;
                while (i + 1 < n && formula[i + 1] <= '9' && formula[i + 1] > '1') {
                    scale = 10 * scale + formula[++i];
                }
                scale = (scale == 0) ? 1 : scale;
                stack<pair<string, int>> tmp_stk;
                while (stk.top().first != "(") {
                    tmp_stk.push({stk.top().first, stk.top().second * scale});
                    stk.pop();
                }
                stk.pop();
                while (!tmp_stk.empty()) {
                    stk.push(tmp_stk.top());
                    tmp_stk.pop();
                }
            } else {
                // 数字和字母直接一起处理掉
                string tmp;
                tmp.push_back(c);
                while (i + 1 < n && formula[i + 1] <= 'z' && formula[i + 1] >= 'a') {
                    tmp.push_back(formula[++i]);
                }
                int scale = 0;
                while (i + 1 < n && formula[i + 1] <= '9' && formula[i + 1] > '1') {
                    scale = 10 * scale + formula[++i];
                }
                scale = (scale == 0) ? 1 : scale;
                stk.push({tmp, scale});
            }
        }
       	map<string, int> ump;
        while (!stk.empty()) {
        	auto [str, num] = stk.top();
        	stk.pop();
        	ump[str] += num;
        }
        string res;
        for (auto pa : ump) {
        	res += pa.first;
        	res += to_string(pa.second);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string formula;
    LeetCodeIO::scan(cin, formula);

    Solution *obj = new Solution();

    auto res = obj->countOfAtoms(formula);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
