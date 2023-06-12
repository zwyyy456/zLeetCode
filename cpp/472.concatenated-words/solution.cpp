// Created by zwyyy456 at 2023/06/05 09:35
// https://leetcode.com/problems/concatenated-words/

/*
472. Concatenated Words (Hard)
Given an array of strings `words` ( **without duplicates**), return all the **concatenated words**
in the given list of `words`.

A **concatenated word** is defined as a string that is comprised entirely of at least two shorter
words (not necesssarily distinct) in the given array.

**Example 1:**

```
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```

**Example 2:**

```
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]

```

**Constraints:**

- `1 <= words.length <= 10⁴`
- `1 <= words[i].length <= 30`
- `words[i]` consists of only lowercase English letters.
- All the strings of `words` are **unique**.
- `1 <= sum(words[i].length) <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 字典树
class Trie {
  private:
    int arr[130120][26] = {0};
    int cnt = 0;
    int is_end[130120] = {0};

  public:
    Trie() {
    }
    void Insert(string &word) {
        int p = 0;
        for (char i : word) {
            int c = i - 'a';
            if (arr[p][c] == 0) {
                // 说明不存在这条边
                arr[p][c] = ++cnt;
            }
            p = arr[p][c];
        }
        is_end[p] = 1;
    }
    bool Find(const string &word, int l, int r) {
        int p = 0;
        for (int i = l; i < r; ++i) {
            int c = word[i] - 'a';
            if (arr[p][c] == 0) {
                return false;
            }
            p = arr[p][c];
        }
        return is_end[p] == 1;
    }
    bool Check(const string &str) {
        vector<int> cach(str.size(), -1);
        return dfs(str, 0, cach);
    }
    bool dfs(const string &str, int idx, vector<int> &cach) {
        if (idx == str.size()) {
            return true;
        }
        if (cach[idx] != -1) {
            return cach[idx] == 1;
        }
        bool res = false;
        // 左闭右开
        for (int i = idx + 1; i <= str.size(); ++i) {
            res = res || (Find(str, idx, i) && dfs(str, i, cach));
        }
        return res;
    }
};
class Solution {
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        auto cmp = [&](const string &str1, const string &str2) {
            if (str1.size() == str2.size()) {
                return str1 < str2;
            }
            return str1.size() < str2.size();
        };
        sort(words.begin(), words.end(), cmp);
        Trie *tree = new Trie();
        vector<string> res;
        for (auto &str : words) {
            if (tree->Check(str)) {
                res.push_back(str);
            }
            tree->Insert(str);
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

    auto res = obj->findAllConcatenatedWordsInADict(words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
