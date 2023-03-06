// Created by zwyyy456 at 2023/03/04 18:46
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

// @lc code=begin
#include <vector>
#include <string>
using std::string;
using std::vector;
class Trie {
  private:
    vector<Trie *> children;
    bool is_end;
    Trie *SearchPrefix(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            if (node->children[ch - 'a'] == nullptr) {
                return nullptr;
            }
            node = node->children[ch - 'a'];
        }
        return node;
    }

  public:
    Trie() :
        children(26), is_end(false) {
    }
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Trie *node = this->SearchPrefix(word);
        if (node == nullptr) {
            return false;
        }
        return node->is_end;
    }

    bool startsWith(string prefix) {
        return this->SearchPrefix(prefix) != nullptr;
    }
};

// @lc code=end
