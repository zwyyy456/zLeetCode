// Created by Bob at 2023/05/30 09:15
// https://leetcode.cn/problems/stream-of-characters/

/*
1032. 字符流 (Hard)
设计一个算法：接收一个字符流，并检查这些字符的后缀是否是字符
串数组 `words` 中的一个字符串。

例如， `words = ["abc", "xyz"]` 且字符流中逐个依次加入 4 个
字符 `'a'`、 `'x'`、 `'y'` 和 `'z'` ，你所设计的算法应当可以
检测到 `"axyz"` 的后缀 `"xyz"` 与 `words` 中的字符串 `"xyz"`
匹配。

按下述要求实现 `StreamChecker` 类：

- `StreamChecker(String[] words)` ：构造函数，用字符串数组 `
words` 初始化数据结构。
- `boolean query(char letter)`：从字符流中接收一个新字符，如
果字符流中的任一非空后缀能匹配 `words` 中的某一字符串，返回
`true` ；否则，返回 `false`。

**示例：**

```
输入：
["StreamChecker", "query", "query", "query", "query", "query
", "query", "query", "query", "query", "query", "query", "qu
ery"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f
"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
输出：
[null, false, false, false, true, false, true, false, false,
false, false, false, true]

解释：
StreamChecker streamChecker = new StreamChecker(["cd", "f",
"kl"]);
streamChecker.query("a"); // 返回 False
streamChecker.query("b"); // 返回 False
streamChecker.query("c"); // 返回n False
streamChecker.query("d"); // 返回 True ，因为 'cd' 在 words
中
streamChecker.query("e"); // 返回 False
streamChecker.query("f"); // 返回 True ，因为 'f' 在 words
中
streamChecker.query("g"); // 返回 False
streamChecker.query("h"); // 返回 False
streamChecker.query("i"); // 返回 False
streamChecker.query("j"); // 返回 False
streamChecker.query("k"); // 返回 False
streamChecker.query("l"); // 返回 True ，因为 'kl' 在 words
中

```

**提示：**

- `1 <= words.length <= 2000`
- `1 <= words[i].length <= 200`
- `words[i]` 由小写英文字母组成
- `letter` 是一个小写英文字母
- 最多调用查询 `4 * 10⁴` 次

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class StreamChecker {
  public:
    StreamChecker() :
        tree_(26), end_(false) {
        for (int i = 0; i < 26; ++i) {
            tree_[i] = nullptr;
        }
    }
    StreamChecker(vector<string> &words) :
        tree_(26), end_(false) {
        for (int i = 0; i < 26; ++i) {
            tree_[i] = nullptr;
        }
        for (auto &word : words) {
            StreamChecker *node = this;
            for (int i = word.size() - 1; i >= 0; --i) {
                int c = word[i] - 'a';
                if (node->tree_[c] == nullptr) {
                    node->tree_[c] = new StreamChecker();
                    node = node->tree_[c];
                } else {
                    node = node->tree_[c];
                }
            }
            node->end_ = true;
        }
    }

    bool query(char letter) {
        stream_.push_back(letter);
        StreamChecker *node = this;
        for (int i = stream_.size() - 1; i >= 0; --i) {
            int c = stream_[i] - 'a';
            if (node->tree_[c] == nullptr) {
                return false;
            }
            node = node->tree_[c];
            if (node->end_) {
                return true;
            }
        }
        return false;
    }

  private:
    vector<char> stream_;
    vector<StreamChecker *> tree_;
    bool end_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    StreamChecker *obj;

    const unordered_map<string, function<void()>> methods = {
        {"StreamChecker", [&]() {
             vector<string> words;
             LeetCodeIO::scan(cin, words);
             cin.ignore();
             obj = new StreamChecker(words);
             out_stream << "null,";
         }},
        {"query", [&]() {
             char letter;
             LeetCodeIO::scan(cin, letter);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->query(letter));
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
