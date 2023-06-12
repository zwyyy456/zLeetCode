// Created by zwyyy456 at 2023/06/11 15:44
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

/*
438. Find All Anagrams in a String (Medium)
Given two strings `s` and `p`, return an array of all the start indices of  `p`'s anagrams in  `s`.
You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

**Example 1:**

```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

```

**Example 2:**

```
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

```

**Constraints:**

- `1 <= s.length, p.length <= 3 * 10⁴`
- `s` and `p` consist of lowercase English letters.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        // 双指针
        int l = 0, r = 0;
        unordered_map<char, int> hash;
        for (auto c : p) {
            ++hash[c];
        }
        vector<int> res;
        while (r < s.size()) {
            char c = s[r++];
            if (hash.find(c) == hash.end()) {
                while (l < r && s[l] != c) {
                    ++hash[s[l++]];
                }
                ++hash[s[l++]];
            }
            --hash[c];
            if (hash[c] == 0) {
                hash.erase(c);
                if (hash.empty()) {
                    res.push_back(l);
                    ++hash[s[l++]];
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

    string s;
    LeetCodeIO::scan(cin, s);
    string p;
    LeetCodeIO::scan(cin, p);

    Solution *obj = new Solution();

    auto res = obj->findAnagrams(s, p);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
