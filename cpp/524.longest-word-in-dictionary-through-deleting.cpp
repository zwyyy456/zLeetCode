// Created by zwyyy456 at 2023/02/28 10:26
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

/*
524. Longest Word in Dictionary through Deleting (Medium)

Given a string `s` and a string array `dictionary`, return the longest string in the dictionary that
can be formed by deleting some of the given string characters. If there is more than one possible
result, return the longest word with the smallest lexicographical order. If there is no possible
result, return the empty string.

**Example 1:**

```
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

```

**Example 2:**

```
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"

```

**Constraints:**

- `1 <= s.length <= 1000`
- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 1000`
- `s` and `dictionary[i]` consist of lowercase English letters.
*/

// @lc code=begin
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
  public:
    bool IsSub(string &s, string &word) {
        for (int i = 0, j = 0; j < word.size();) {
            if (i == s.size()) {
                return false;
            }
            if (s[i] == word[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return true;
    }
    string findLongestWord(string s, vector<string> &dictionary) {
        auto cmp = [&](string &s1, string &s2) {
            if (s1.size() != s2.size()) {
                return s1.size() > s2.size();
            }
            return s1 < s2;
        };
        std::sort(dictionary.begin(), dictionary.end(), cmp);
        for (auto &word : dictionary) {
            if (IsSub(s, word)) {
                return word;
            }
        }
        string res;
        return res;
    }
};

// @lc code=end
