// Created by zwyyy456 at 2023/04/08 21:48
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

/*
1239. Maximum Length of a Concatenated String with Unique Characters (Medium)

You are given an array of strings `arr`. A string `s` is formed by the **concatenation** of a
**subsequence** of `arr` that has **unique characters**.

Return the **maximum** possible length of `s`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements
without changing the order of the remaining elements.

**Example 1:**

```
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

```

**Example 2:**

```
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act"
+ "ers").

```

**Example 3:**

```
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

```

**Constraints:**

- `1 <= arr.length <= 16`
- `1 <= arr[i].length <= 26`
- `arr[i]` contains only lowercase English letters.
*/

// @lc code=begin
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> record(n);
        for (int i = 0; i < n; ++i) {
            for (char c : arr[i]) {
                int cnt = c - 'a';
                if (((1 << cnt) & record[i]) != (1 << cnt)) {
                    record[i] |= (1 << cnt);
                } else {
                    record[i] = -1;
                    break;
                }
            }
        }
    }
};

// @lc code=end
