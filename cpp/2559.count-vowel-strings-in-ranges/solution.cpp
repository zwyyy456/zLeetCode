// Created by zwyyy456 at 2023/06/02 09:37
// https://leetcode.com/problems/count-vowel-strings-in-ranges/

/*
2559. Count Vowel Strings in Ranges (Medium)
You are given a **0-indexed** array of strings `words` and a 2D array of integers `queries`.

Each query `queries[i] = [lᵢ, rᵢ]` asks us to find the number of strings present in the range `lᵢ`
to `rᵢ` (both **inclusive**) of `words` that start and end with a vowel.

Return an array  `ans` of size  `queries.length`, where  `ans[i]` is the answer to the  `i`  query.

**Note** that the vowel letters are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

```
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

```

**Example 2:**

```
Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
```

**Constraints:**

- `1 <= words.length <= 10⁵`
- `1 <= words[i].length <= 40`
- `words[i]` consists only of lowercase English letters.
- `sum(words[i].length) <= 3 * 10⁵`
- `1 <= queries.length <= 10⁵`
- `0 <= lᵢ <= rᵢ < words.length`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        int n = words.size();
        vector<int> prefix(n + 1);
        unordered_set<char> ust{'a', 'o', 'e', 'i', 'u'};
        for (int i = 1; i <= n; ++i) {
            int flag = 0;
            if (ust.find(words[i - 1][0]) != ust.end() && ust.find(words[i - 1].back()) != ust.end()) {
                flag = 1;
            }
            prefix[i] = prefix[i - 1] + flag;
        }
        int m = queries.size();

        vector<int> res(m);
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = prefix[r + 1] - prefix[l];
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
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->vowelStrings(words, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
