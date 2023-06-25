// Created by zwyyy456 at 2023/06/15 09:05
// https://leetcode.com/problems/can-make-palindrome-from-substring/

/*
1177. Can Make Palindrome from Substring (Medium)
You are given a string `s` and array `queries` where `queries[i] = [leftᵢ, rightᵢ, kᵢ]`. We may
rearrange the substring `s[leftᵢ...rightᵢ]` for each query and then choose up to `kᵢ` of them to
replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above, the result of the
query is `true`. Otherwise, the result is `false`.

Return a boolean array `answer` where `answer[i]` is the result of the `ith` query `queries[i]`.

Note that each letter is counted individually for replacement, so if, for example `s[leftᵢ...rightᵢ]
= "aaa"`, and `kᵢ = 2`, we can only replace two of the letters. Also, note that no query modifies
the initial string `s`.

**Example :**

```
Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0]: substring = "d", is palidrome.
queries[1]: substring = "bc", is not palidrome.
queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be
changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.

```

**Example 2:**

```
Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
Output: [false,true]

```

**Constraints:**

- `1 <= s.length, queries.length <= 10⁵`
- `0 <= leftᵢ <= rightᵢ < s.length`
- `0 <= kᵢ <= s.length`
- `s` consists of lowercase English letters.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<vector<int>> prefix(26, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            int c = s[i - 1] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (j == c) {
                    prefix[j][i] = prefix[j][i - 1] + 1;
                } else {
                    prefix[j][i] = prefix[j][i - 1];
                }
            }
        }
        // 统计每个字母的前缀和
        int m = queries.size();
        vector<bool> ans;
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            int k = queries[i][2];
            // r - l + 1 为奇数时，必然有 2 * x + 1 个个数为奇数的字母
            // r - l + 1 为偶数时，必然有 2 * x 个个数为偶数的字母
            // k >= x，即可满足条件
            int cnt = 0;
            for (int j = 0; j < 26; ++j) {
                if ((prefix[j][r + 1] - prefix[j][l]) % 2 == 1) {
                    ++cnt;
                }
            }
            if (cnt / 2 > k) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->canMakePaliQueries(s, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
