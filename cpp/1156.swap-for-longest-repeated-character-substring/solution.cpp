// Created by zwyyy456 at 2023/06/03 12:42
// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

/*
1156. Swap For Longest Repeated Character Substring (Medium)
You are given a string `text`. You can swap two of the characters in the `text`.

Return the length of the longest substring with repeated characters.

**Example 1:**

```
Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then,
the longest repeated character substring is "aaa" with length 3.

```

**Example 2:**

```
Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character
substring "aaaaaa" with length 6.

```

**Example 3:**

```
Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.

```

**Constraints:**

- `1 <= text.length <= 2 * 10⁴`
- `text` consist of lowercase English characters only.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> prefix(26);
        for (int i = 1; i <= n; ++i) {
            int c = text[i - 1] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (j == c) {
                    prefix[j] = prefix[j] + 1;
                }
            }
        }
        int res = 0;
        int i = 0, j = 0, k = 0;
        while (i < n) {
            while (j < n && text[j] == text[i]) {
                ++j;
            }
            k = j + 1;
            while (k < n && text[k] == text[i]) {
                ++k;
            }
            res = max(res, min(k - i, prefix[text[i] - 'a']));
            i = j;
        }
        return res;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string text;
    LeetCodeIO::scan(cin, text);

    Solution *obj = new Solution();

    auto res = obj->maxRepOpt1(text);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
