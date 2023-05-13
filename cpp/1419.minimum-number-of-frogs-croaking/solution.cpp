// Created by zwyyy456 at 2023/05/06 09:11
// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

/*
1419. Minimum Number of Frogs Croaking (Medium)
You are given the string `croakOfFrogs`, which represents a combination of the string `"croak"` from
different frogs, that is, multiple frogs can croak at the same time, so multiple `"croak"` are
mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid `"croak"` means a frog is printing five letters `'c'`, `'r'`, `'o'`, `'a'`, and `'k'`
**sequentially**. The frogs have to print all five letters to finish a croak. If the given string is
not a combination of a valid `"croak"` return `-1`.

**Example 1:**

```
Input: croakOfFrogs = "croakcroak"
Output: 1
Explanation: One frog yelling "croak" twice.

```

**Example 2:**

```
Input: croakOfFrogs = "crcoakroak"
Output: 2
Explanation: The minimum number of frogs is two.
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

```

**Example 3:**

```
Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.

```

**Constraints:**

- `1 <= croakOfFrogs.length <= 10⁵`
- `croakOfFrogs` is either `'c'`, `'r'`, `'o'`, `'a'`, or `'k'`.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> letter;
        vector<char> croak{'c', 'r', 'o', 'a', 'k'};
        int res = 0;
        for (char c : croakOfFrogs) {
            ++letter[c];
            if (c == 'r') {
                if (letter[c] > letter['c']) {
                    return -1;
                }
            } else if (c == 'o') {
                if (letter[c] > letter['r']) {
                    return -1;
                }
            } else if (c == 'a') {
                if (letter[c] > letter['o']) {
                    return -1;
                }
            } else if (c == 'k') {
                if (letter[c] > letter['a']) {
                    return -1;
                }
            }
            res = max(res, letter['c'] - letter['k']);
        }
        for (auto pa : letter) {
            if (pa.second != croakOfFrogs.size() / 5) {
                return -1;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string croakOfFrogs;
    LeetCodeIO::scan(cin, croakOfFrogs);

    Solution *obj = new Solution();

    auto res = obj->minNumberOfFrogs(croakOfFrogs);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
