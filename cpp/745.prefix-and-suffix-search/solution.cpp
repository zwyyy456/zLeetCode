// Created by zwyyy456 at 2023/05/29 09:12
// https://leetcode.com/problems/prefix-and-suffix-search/

/*
745. Prefix and Suffix Search (Hard)
Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the `WordFilter` class:

- `WordFilter(string[] words)` Initializes the object with the `words` in the dictionary.
- `f(string pref, string suff)` Returns the index of the word in the dictionary, which has the prefix
`pref` and the suffix `suff`. If there is more than one valid index, return **the largest** of them.
If there is no such word in the dictionary, return `-1`.

**Example 1:**

```
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".

```

**Constraints:**

- `1 <= words.length <= 10⁴`
- `1 <= words[i].length <= 7`
- `1 <= pref.length, suff.length <= 7`
- `words[i]`, `pref` and `suff` consist of lowercase English letters only.
- At most `10⁴` calls will be made to the function `f`.

*/

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class WordFilter {
  public:
    WordFilter(vector<string> &words) :
        pre_tree_(26), suf_tree_(26) {
        for (int i = 0; i < 26; ++i) {
            pre_tree_[i] = nullptr;
            suf_tree_[i] = nullptr;
        }
        for (int i = 0; i < words.size(); ++i) {
            InsertPre(words[i], i);
            InsertSuf(words[i], i);
        }
    }
    WordFilter() :
        pre_tree_(26), suf_tree_(26) {
        for (int i = 0; i < 26; ++i) {
            pre_tree_[i] = nullptr;
            suf_tree_[i] = nullptr;
        }
    }
    void InsertPre(string &word, int i) {
        WordFilter *node = this;
        for (char c : word) {
            if (node->pre_tree_[c - 'a'] == nullptr) {
                node->pre_tree_[c - 'a'] = new WordFilter();
            }
            node = node->pre_tree_[c - 'a'];
            node->pre_idx_.push_back(i);
        }
    }

    void InsertSuf(string word, int i) {
        reverse(word.begin(), word.end());
        WordFilter *node = this;
        for (char c : word) {
            if (node->suf_tree_[c - 'a'] == nullptr) {
                node->suf_tree_[c - 'a'] = new WordFilter();
            }
            node = node->suf_tree_[c - 'a'];
            node->suf_idx_.push_back(i);
        }
    }

    int f(string pref, string suff) {
        WordFilter *pre = this;
        WordFilter *suf = this;
        reverse(suff.begin(), suff.end());
        for (char c : pref) {
            if (pre->pre_tree_[c - 'a'] == nullptr) {
                return -1;
            }
            pre = pre->pre_tree_[c - 'a'];
        }
        for (char c : suff) {
            if (suf->suf_tree_[c - 'a'] == nullptr) {
                return -1;
            }
            suf = suf->suf_tree_[c - 'a'];
        }
        // vector<int> suf_ids(suf->suf_idx_.begin(), suf->suf_idx_.end());
        // vector<int> pre_ids(pre->pre_idx_.begin(), pre->pre_idx_.end());
        for (int i = pre->pre_idx_.size() - 1, j = suf->suf_idx_.size() - 1; i >= 0 && j >= 0;) {
            if (pre->pre_idx_[i] > suf->suf_idx_[j]) {
                --i;
                ;
            } else if (pre->pre_idx_[i] < suf->suf_idx_[j]) {
                --j;
            } else {
                return pre->pre_idx_[i];
            }
        }
        return -1;
    }

  private:
    vector<WordFilter *> pre_tree_;
    vector<WordFilter *> suf_tree_;
    vector<int> pre_idx_;
    vector<int> suf_idx_;
    vector<string> dict;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    WordFilter *obj;

    const unordered_map<string, function<void()>> methods = {
        {"WordFilter", [&]() {
             vector<string> words;
             LeetCodeIO::scan(cin, words);
             cin.ignore();
             obj = new WordFilter(words);
             out_stream << "null,";
         }},
        {"f", [&]() {
             string pref;
             LeetCodeIO::scan(cin, pref);
             cin.ignore();
             string suff;
             LeetCodeIO::scan(cin, suff);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->f(pref, suff));
             out_stream << ',';
         }},
    };
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';

    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
