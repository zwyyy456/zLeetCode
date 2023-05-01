// Created by zwyyy456 at 2023/04/27 10:17
// https://leetcode.com/problems/longest-string-chain/

/*
1048. Longest String Chain (Medium)
You are given an array of `words` where each word consists of lowercase English letters.

`wordA` is a **predecessor** of `wordB` if and only if we can insert **exactly one** letter anywhere
in `wordA` **without changing the order of the other characters** to make it equal to `wordB`.

- For example, `"abc"` is a **predecessor** of `"abac"`, while `"cba"` is not a **predecessor** of
`"bcad"`.

A **word chain** is a sequence of words `[word₁, word₂, ..., wordₖ]` with `k >= 1`, where `word₁` is
a **predecessor** of `word₂`, `word₂` is a **predecessor** of `word₃`, and so on. A single word is
trivially a **word chain** with `k == 1`.

Return the **length** of the **longest possible word chain** with words chosen from the given list
of  `words`.

**Example 1:**

```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

```

**Example 2:**

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

```

**Example 3:**

```
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

```

**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int r, int l, vector<string> &words) {
        if (words[r].size() - words[l].size() != 1) {
            return false;
        }
        int cnt = 0;
        for (int i = 0, j = 0; j < l; ++i, ++j) {
            if (words[r][i] == words[l][j]) {
                continue;
            }
            ++i;
            cnt = 1;
        }
        return cnt == 1;
    }
    int longestStrChain(vector<string> &words) {
        int n = words.size();
        int res = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (check(i, j, words)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();

    auto res = obj->longestStrChain(words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
