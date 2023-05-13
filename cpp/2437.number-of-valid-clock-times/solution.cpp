// Created by zwyyy456 at 2023/05/09 10:12
// https://leetcode.com/problems/number-of-valid-clock-times/

/*
2437. Number of Valid Clock Times (Easy)
You are given a string of length `5` called `time`, representing the current time on a digital clock
in the format `"hh:mm"`. The **earliest** possible time is `"00:00"` and the **latest** possible
time is `"23:59"`.

In the string `time`, the digits represented by the `?` symbol are **unknown**, and must be
**replaced** with a digit from `0` to `9`.

Return an integer  `answer`, the number of valid clock times that can be created by replacing every
`?` with a digit from  `0` to  `9`.

**Example 1:**

```
Input: time = "?5:00"
Output: 2
Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we
cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.

```

**Example 2:**

```
Input: time = "0?:0?"
Output: 100
Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.

```

**Example 3:**

```
Input: time = "??:??"
Output: 1440
Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes.
In total, we have 24 * 60 = 1440 choices.

```

**Constraints:**

- `time` is a valid string of length `5` in the format `"hh:mm"`.
- `"00" <= hh <= "23"`
- `"00" <= mm <= "59"`
- Some of the digits might be replaced with `'?'` and need to be replaced with digits from `0` to
`9`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countTime(string time) {
        vector<char> mtm(4);
        int res = 1;
        int h = 0;
        for (int i = 0; i < 2; ++i) {
            mtm[i] = time[i];
        }
        for (int i = 3; i < 5; ++i) {
            mtm[i - 1] = time[i];
        }
        int cnth = 0;
        if (mtm[0] == '?') {
            for (int i = 0; i <= 9; ++i) {
                h = i;
                if (mtm[1] == '?') {
                    for (int j = 0; j <= 9; ++j) {
                        h = h * 10 + j;
                        if (h < 24) {
                            ++cnth;
                        }
                        h = (h - j) / 10;
                    }
                } else {
                    h = h * 10 + mtm[1] - '0';
                    if (h < 24) {
                        ++cnth;
                    }
                }
            }
        } else {
            h = mtm[0] - '0';
            if (mtm[1] == '?') {
                for (int j = 0; j <= 9; ++j) {
                    h = h * 10 + j;
                    if (h < 24) {
                        ++cnth;
                    }
                    h = (h - j) / 10;
                }
            } else {
                h = h * 10 + mtm[1] - '0';
                if (h < 24) {
                    ++cnth;
                }
            }
        }
        cout << cnth << endl;
        int cntm = 0;
        if (mtm[2] == '?') {
            for (int i = 0; i <= 9; ++i) {
                h = i;
                if (mtm[3] == '?') {
                    for (int j = 0; j <= 9; ++j) {
                        h = h * 10 + j;
                        if (h < 60) {
                            ++cntm;
                        }
                        h = (h - j) / 10;
                    }
                } else {
                    h = h * 10 + mtm[3] - '0';
                    if (h < 60) {
                        ++cntm;
                    }
                }
            }
        } else {
            h = mtm[2] - '0';
            if (mtm[3] == '?') {
                for (int j = 0; j <= 9; ++j) {
                    // cout << "rightj\n";
                    h = h * 10 + j;
                    if (h < 60) {
                        ++cntm;
                    }
                    h = (h - j) / 10;
                }
            } else {
                h = h * 10 + mtm[3] - '0';
                if (h < 60) {
                    ++cntm;
                }
            }
        }
        cout << cntm << endl;
        return cnth * cntm;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string time;
    LeetCodeIO::scan(cin, time);

    Solution *obj = new Solution();

    auto res = obj->countTime(time);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
