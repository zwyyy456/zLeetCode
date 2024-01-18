// Created by Bob at 2023/05/28 14:35
// https://leetcode.cn/problems/implement-magic-dictionary/

/*
676. 实现一个魔法字典 (Medium)
设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 *
*互不相同** 。 如果给出一个单词，请判定能否只将这个单词中 **
一个** 字母换成另一个字母，使得所形成的新单词存在于你构建的
字典中。

实现 `MagicDictionary` 类：

- `MagicDictionary()` 初始化对象
- `void buildDict(String[] dictionary)` 使用字符串数组 `dict
ionary` 设定该数据结构， `dictionary` 中的字符串互不相同
- `bool search(String searchWord)` 给定一个字符串 `searchWor
d` ，判定能否只将字符串中 **一个** 字母换成另一个字母，使得
所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回
`true` ；否则，返回 `false` 。

**示例：**

```
输入
["MagicDictionary", "buildDict", "search", "search", "search
", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"]
, ["leetcoded"]]
输出
[null, null, false, true, false, false]

解释
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // 返回 False
magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e'
可以匹配 "hello" ，所以返回 True
magicDictionary.search("hell"); // 返回 False
magicDictionary.search("leetcoded"); // 返回 False

```

**提示：**

- `1 <= dictionary.length <= 100`
- `1 <= dictionary[i].length <= 100`
- `dictionary[i]` 仅由小写英文字母组成
- `dictionary` 中的所有字符串 **互不相同**
- `1 <= searchWord.length <= 100`
- `searchWord` 仅由小写英文字母组成
- `buildDict` 仅在 `search` 之前调用一次
- 最多调用 `100` 次 `search`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MagicDictionary {
  public:
    MagicDictionary() :
        is_end_(false) {
    }

    void buildDict(vector<string> dictionary) {
        for (auto &str : dictionary) {
            MagicDictionary *node = this;
            for (char &c : str) {
                if (node->vec_.find(c) == node->vec_.end()) {
                    node->vec_[c] = new MagicDictionary();
                    node = node->vec_[c];
                } else {
                    node = node->vec_[c];
                }
            }
            node->is_end_ = true;
        }
    }

    bool search(string searchWord) {
        MagicDictionary *node = this;
        for (int i = 0; i < searchWord.size(); ++i) {
            char c = searchWord[i];
            for (auto &[ch, p] : node->vec_) {
                if (ch == c) {
                    continue;
                }
                if (search(searchWord.substr(i + 1), node->vec_[ch])) {
                    return true;
                }
            }
            if (node->vec_.find(c) == node->vec_.end()) {
                return false;
            }
            node = node->vec_[c];
        }
        return false;
    }

    bool search(string searchWord, MagicDictionary *node) {
        for (char c : searchWord) {
            if (node->vec_.find(c) == node->vec_.end()) {
                return false;
            }
            node = node->vec_[c];
        }
        return node->is_end_;
    }

  private:
    // vector<MagicDictionary *> vec_;
    unordered_map<char, MagicDictionary *> vec_;
    bool is_end_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MagicDictionary *obj;

    const unordered_map<string, function<void()>> methods = {
        {"MagicDictionary", [&]() {
             cin.ignore();
             obj = new MagicDictionary();
             out_stream << "null,";
         }},
        {"buildDict", [&]() {
             vector<string> dictionary;
             LeetCodeIO::scan(cin, dictionary);
             cin.ignore();
             obj->buildDict(dictionary);
             out_stream << "null,";
         }},
        {"search", [&]() {
             string searchWord;
             LeetCodeIO::scan(cin, searchWord);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->search(searchWord));
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
