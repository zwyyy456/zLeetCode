// Created by zwyyy456 at 2023/03/29 09:25
// https://leetcode.com/problems/count-sorted-vowel-strings/

/*
1641. Count Sorted Vowel Strings (Medium)

Given an integer `n`, return the number of strings of length  `n` that consist only of vowels ( `a`,
`e`,  `i`,  `o`,  `u`) and are **lexicographically sorted**.

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes
before `s[i+1]` in the alphabet.

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

```

**Example 2:**

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

```

**Example 3:**

```
Input: n = 33
Output: 66045

```

**Constraints:**

- `1 <= n <= 50`
*/

// @lc code=begin
#include <sys/syslimits.h>
#include <vector>
using std::vector;
class Solution {
public:
    int countVowelStrings(int n) {
        // vector<vector<int>> res(n, vector<int>(5));
        // for (int i = 0; i < 5; ++i) {
        //     res[0][i] = 1;
        // }
        // for (int i = 1; i < n; ++i) {
        //     res[i][0] = res[i - 1][0];
        //     res[i][1] = res[i][0] + res[i - 1][1];
        //     res[i][2] = res[i][1] + res[i - 1][2];
        //     res[i][3] = res[i][2] + res[i - 1][3];
        //     res[i][4] = res[i][3] + res[i - 1][4];
        // }
        // 优化空间复杂度
        if (n == 1) {
            return 5;
        }
        int res[2][5];
        for (int i = 0; i < 5; ++i) {
            res[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            res[1][0] = res[0][0];
            res[1][1] = res[1][0] + res[0][1];
            res[1][2] = res[1][1] + res[0][2];
            res[1][3] = res[1][2] + res[0][3];
            res[1][4] = res[1][3] + res[0][4];
            for (int j = 0; j < 5; ++j) {
                res[0][j] = res[1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans += res[1][i];
        }
        return ans;
    }
};

// @lc code=end
