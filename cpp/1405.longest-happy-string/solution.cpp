// Created by zwyyy456 at 2023/03/01 18:49
// https://leetcode.com/problems/longest-happy-string/

/*
1405. Longest Happy String (Medium)

A string `s` is called **happy** if it satisfies the following conditions:

- `s` only contains the letters `'a'`, `'b'`, and `'c'`.
- `s` does not contain any of `"aaa"`, `"bbb"`, or `"ccc"` as a substring.
- `s` contains **at most** `a` occurrences of the letter `'a'`.
- `s` contains **at most** `b` occurrences of the letter `'b'`.
- `s` contains **at most** `c` occurrences of the letter `'c'`.

Given three integers `a`, `b`, and `c`, return the **longest possible happy** string. If there are
multiple longest happy strings, return any of them. If there is no such string, return the empty
string  `""`.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

```

**Example 2:**

```
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

```

**Constraints:**

- `0 <= a, b, c <= 100`
- `a + b + c > 0`
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <string>
#include <utility>
using std::pair;
using std::string;
using std::vector;
using std::priority_queue;
class Solution {
  public:
    string longestDiverseString(int a, int b, int c) {
        pair<char, int> a_num{'a', a};
        pair<char, int> b_num{'b', b};
        pair<char, int> c_num{'c', c};
        auto cmp = [&](pair<char, int> &p1, pair<char, int> &p2) {
            if (p1.second == p2.second) {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        if (a > 0)
            pq.push(a_num);
        if (b > 0)
            pq.push(b_num);
        if (c > 0)
            pq.push(c_num);
        string res;
        int cnt = 0;
        while (!pq.empty() && cnt < 3) {
            auto [letter, num] = pq.top();
            pq.pop();
            if (cnt == 2 && res[res.size() - 1] == letter) {
                if (pq.empty()) {
                    return res;
                }
                auto [letter1, num1] = pq.top();
                pq.pop();
                res.push_back(letter1);
                cnt = 1;
                --num1;
                if (num1 > 0) {
                    pq.push({letter1, num1});
                }
                pq.push({letter, num});
            } else {
                if (!res.empty() && res[res.size() - 1] != letter) {
                    cnt = 1;
                } else {
                    ++cnt;
                }
                res.push_back(letter);
                --num;
                if (num > 0) {
                    pq.push({letter, num});
                }
            }
        }
        return res;
    }
};

// @lc code=end
