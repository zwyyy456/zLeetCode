// Created by zwyyy456 at 2023/05/27 10:09
// https://leetcode.com/problems/word-search-ii/

/*
212. Word Search II (Hard)
Given an `m x n` `board` of characters and a list of strings `words`, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells**
are horizontally or vertically neighboring. The same letter cell may not be used more than once in a
word.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words =
["oath","pea","eat","rain"]
Output: ["eat","oath"]

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 12`
- `board[i][j]` is a lowercase English letter.
- `1 <= words.length <= 3 * 10⁴`
- `1 <= words[i].length <= 10`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.

*/

#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Trie {
  public:
    Trie() :
        tree(26), is_end(false) {
        for (int i = 0; i < 26; ++i) {
            tree[i] = nullptr;
        }
    }
    int Prefix(string &word) {
        Trie *node = this;
        for (char c : word) {
            if (node->tree[c - 'a'] == nullptr) {
                return -1; // -1 表示不在前缀树中
            }
            node = node->tree[c - 'a'];
        }
        if (node->is_end) {
            return 1; // 1 表示是一个完整的单词
        }
        return 0; // 0 表示是前缀
    }
    void Insert(string &word) {
        Trie *node = this;
        for (char c : word) {
            if (node->tree[c - 'a'] != nullptr) {
                node = node->tree[c - 'a'];
            } else {
                node->tree[c - 'a'] = new Trie();
                node = node->tree[c - 'a'];
            }
        }
        node->is_end = true;
    }

  private:
    vector<Trie *> tree;
    bool is_end;
};
class Solution {
  public:
    void dfs(vector<vector<char>> &board, unordered_set<string> &res, Trie *tree, int x, vector<vector<bool>> &vis, int y, vector<vector<int>> &mov, string &tmp) {
        int m = board.size(), n = board[0].size();
        for (int k = 0; k < 4; ++k) {
            int x_n = x + mov[k][0], y_n = y + mov[k][1];
            if (x_n >= m || x_n < 0 || y_n >= n || y_n < 0 || vis[x_n][y_n] || tmp.size() > 9) {
                continue;
            }
            tmp.push_back(board[x_n][y_n]);
            int num = tree->Prefix(tmp);
            if (num != -1) {
                vis[x_n][y_n] = true;
                if (num == 1) {
                    res.insert(tmp);
                }
                dfs(board, res, tree, x_n, vis, y_n, mov, tmp);
                vis[x_n][y_n] = false;
            }
            tmp.pop_back();
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        // 前缀树 + dfs
        Trie *tree = new Trie();
        for (auto word : words) {
            tree->Insert(word);
        }
        unordered_set<string> res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> mov{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        string tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp.push_back(board[i][j]);
                if (tree->Prefix(tmp) == 1) {
                    res.insert(tmp);
                }
                vis[i][j] = true;
                dfs(board, res, tree, i, vis, j, mov, tmp);
                tmp.pop_back();
                vis[i][j] = false;
            }
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> board;
    LeetCodeIO::scan(cin, board);
    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();

    auto res = obj->findWords(board, words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
