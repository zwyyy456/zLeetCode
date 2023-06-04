// Created by zwyyy456 at 2023/05/25 09:24
// https://leetcode.com/problems/odd-string-difference/

/*
2451. Odd String Difference (Easy)
You are given an array of equal-length strings `words`. Assume that the length of each string is `n`.

Each string `words[i]` can be converted into a **difference integer array** `difference[i]` of
length `n - 1` where `difference[i][j] = words[i][j+1] - words[i][j]` where `0 <= j <= n - 2`. Note
that the difference between two letters is the difference between their **positions** in the
alphabet i.e. the position of `'a'` is `0`, `'b'` is `1`, and `'z'` is `25`.

- For example, for the string `"acb"`, the difference integer array is `[2 - 0, 1 - 2] = [2, -1]`.

All the strings in words have the same difference integer array, **except one**. You should find
that string.

Return the string in  `words` that has different **difference integer array**.

**Example 1:**

```
Input: words = ["adc","wzy","abc"]
Output: "abc"
Explanation:
- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1].
The odd array out is [1, 1], so we return the corresponding string, "abc".

```

**Example 2:**

```
Input: words = ["aaa","bob","ccc","ddd"]
Output: "bob"
Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].

```

**Constraints:**

- `3 <= words.length <= 100`
- `n == words[i].length`
- `2 <= n <= 20`
- `words[i]` consists of lowercase English letters.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool nequal(vector<vector<int>> &rec, int cur, int pre) {
        int n = rec.size();
        pre = (pre + n) % n;
        int m = rec[0].size();
        for (int i = 0; i < m; ++i) {
            if (rec[pre][i] != rec[cur][i]) {
                return true;
            }
        }
        return false;
    }
    string oddString(vector<string> &words) {
        int n = words.size();
        int m = words[0].size();
        vector<vector<int>> rec(n, vector<int>(m - 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                rec[i][j] = words[i][j + 1] - words[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (nequal(rec, i, i - 1) && nequal(rec, i, i + 1)) {
                res = i;
                return words[res];
            }
        }
        return words[res];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();

    auto res = obj->oddString(words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
