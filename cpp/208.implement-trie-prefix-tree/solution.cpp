// Created by zwyyy456 at 2023/05/10 10:53
// https://leetcode.com/problems/implement-trie-prefix-tree/

/*
208. Implement Trie (Prefix Tree) (Medium)
A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree
data structure used to efficiently store and retrieve keys in a dataset of strings. There are
various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was
inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word`
that has the prefix `prefix`, and `false` otherwise.

**Example 1:**

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

```

**Constraints:**

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 10⁴` calls **in total** will be made to `insert`, `search`, and `startsWith`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Trie {
  private:
    vector<Trie *> vec;
    bool is_end;

  public:
  	Trie() : vec(26), is_end(false) {
  		for (int i = 0; i < 26; ++i) {
  			vec[i] = nullptr;
  		}
  	}
  	void insert(string word) {
  		Trie *node = this;
  		for (int i = 0; i < word.size(); ++i) {
  			if (node->vec[word[i] - 'a'] != nullptr) {
  				node = node->vec[word[i] - 'a'];
  			} else {
  				vec[word[i] - 'a'] = new Trie();
  				node = node->vec[word[i] - 'a'];
  			}
  		}
  		node->is_end = true;
  	}
  	bool search(string word) {
  		Trie *node = this;
  		for (int i = 0; i < word.size(); ++i) {
  			if (node->vec[word[i] - 'a'] != nullptr) {
  				node = node->vec[word[i] - 'a'];
  			} else {
  				return false;
  			}
  		}
  		return node->is_end;
  	}
  	bool startsWith(string prefix) {
  		Trie *node = this;
  		for (int i = 0; i < prefix.size(); ++i) {
  			if (node->vec[prefix[i] - 'a'] != nullptr) {
  				node = node->vec[prefix[i] - 'a'];
  			} else {
  				return false;
  			}
  		}
  		return true;
  	}	
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    Trie *obj;

    const unordered_map<string, function<void()>> methods = {
        {"Trie", [&]() {
             cin.ignore();
             obj = new Trie();
             out_stream << "null,";
         }},
        {"insert", [&]() {
             string word;
             LeetCodeIO::scan(cin, word);
             cin.ignore();
             obj->insert(word);
             out_stream << "null,";
         }},
        {"search", [&]() {
             string word;
             LeetCodeIO::scan(cin, word);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->search(word));
             out_stream << ',';
         }},
        {"startsWith", [&]() {
             string prefix;
             LeetCodeIO::scan(cin, prefix);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->startsWith(prefix));
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
