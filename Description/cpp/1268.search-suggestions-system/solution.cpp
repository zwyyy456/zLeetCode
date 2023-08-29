// Created by zwyyy456 at 2023/08/07 20:11
// leetgo: 1.3.1
// https://leetcode.cn/problems/search-suggestions-system/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Trie {
  public:
    Trie() :
        arr(26), isend(false) {
    }
    void Insert(const string &str) {
        Trie *cur = this;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            int idx = str[i] - 'a';
            if (cur->arr[idx] == nullptr) {
                cur->arr[idx] = new Trie;
            }
            cur = cur->arr[idx];
        }
        cur->isend = true;
    }
    vector<string> find(string str) {
        Trie *cur = this;
        int n = str.size();
        vector<string> res;
        string tmp;
        for (int i = 0; i < n; ++i) {
            int idx = str[i] - 'a';
            if (cur->arr[idx] == nullptr) {
                return res;
            }
            tmp.push_back(str[i]);
            cur = cur->arr[idx];
        }
        dfs(tmp, cur, res);
        return res;
    }

  private:
    vector<Trie *> arr;
    bool isend;
    void dfs(string &tmp, Trie *cur, vector<string> &res) {
        if (res.size() >= 3) {
            return;
        }
        if (cur->isend) {
            res.push_back(tmp);
        }
        for (int i = 0; i < 26; ++i) {
            if (cur->arr[i] != nullptr) {
                tmp.push_back(i + 'a');
                dfs(tmp, cur->arr[i], res);
                tmp.pop_back();
            }
        }
    }
};
class Solution {
  public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        int n = searchWord.size();
        vector<vector<string>> res(n);
        Trie *trie = new Trie;
        for (string &str : products) {
            trie->Insert(str);
        }
        for (int i = 0; i < n; ++i) {
            res[i] = trie->find(searchWord.substr(0, i + 1));
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> products;
    LeetCodeIO::scan(cin, products);
    string searchWord;
    LeetCodeIO::scan(cin, searchWord);

    Solution *obj = new Solution();

    auto res = obj->suggestedProducts(products, searchWord);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
