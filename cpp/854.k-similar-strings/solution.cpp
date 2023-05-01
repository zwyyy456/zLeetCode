// Created by zwyyy456 at 2023/04/21 13:48
// https://leetcode.com/problems/k-similar-strings/

/*
854. K-Similar Strings (Hard)
Strings `s1` and `s2` are `k` **-similar** (for some non-negative integer `k`) if we can swap the
positions of two letters in `s1` exactly `k` times so that the resulting string equals `s2`.

Given two anagrams `s1` and `s2`, return the smallest `k` for which `s1` and `s2` are `k` **-
similar**.

**Example 1:**

```
Input: s1 = "ab", s2 = "ba"
Output: 1
Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" -->
"ba".

```

**Example 2:**

```
Input: s1 = "abc", s2 = "bca"
Output: 2
Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" -->
"bac" --> "bca".

```

**Constraints:**

- `1 <= s1.length <= 20`
- `s2.length == s1.length`
- `s1` and `s2` contain only lowercase letters from the set `{'a', 'b', 'c', 'd', 'e', 'f'}`.
- `s2` is an anagram of `s1`.

*/

#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int kSimilarity(string s1, string s2) {
    	int res = 0;
    	unordered_set<string> vis;
    	
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s1;
    LeetCodeIO::scan(cin, s1);
    string s2;
    LeetCodeIO::scan(cin, s2);

    Solution *obj = new Solution();

    auto res = obj->kSimilarity(s1, s2);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
