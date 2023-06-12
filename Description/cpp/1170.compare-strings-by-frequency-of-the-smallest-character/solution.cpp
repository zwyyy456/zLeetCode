// Created by Bob at 2023/06/10 19:01
// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/

/*
1170. 比较字符串最小字母出现频次 (Medium)
定义一个函数 `f(s)`，统计 `s`  中 **（按字典序比较）最小字母
的出现频次** ，其中 `s` 是一个非空字符串。

例如，若 `s = "dcce"`，那么 `f(s) = 2`，因为字典序最小字母是
`"c"`，它出现了 2 次。

现在，给你两个字符串数组待查表 `queries` 和词汇表 `words` 。
对于每次查询 `queries[i]` ，需统计 `words` 中满足 `f(queries
[i])` < `f(W)` 的 **词的数目** ， `W` 表示词汇表 `words` 中
的每个词。

请你返回一个整数数组 `answer` 作为答案，其中每个 `answer[i]`
是第 `i` 次查询的结果。

**示例 1：**

```
输入：queries = ["cbd"], words = ["zaaaz"]
输出：[1]
解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f
("zaaaz")。

```

**示例 2：**

```
输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"
]
输出：[1,2]
解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa")
和 f("aaaa") 都 > f("cc")。

```

**提示：**

- `1 <= queries.length <= 2000`
- `1 <= words.length <= 2000`
- `1 <= queries[i].length, words[i].length <= 10`
- `queries[i][j]`、 `words[i][j]` 都由小写英文字母组成

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Count(const string &str) {
        int arr[26] = {0};
        for (char c : str) {
            ++arr[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i] > 0) {
                return arr[i];
            }
        }
        return 0;
    }
    int Bfind(int target, vector<int> &w) {
        int l = 0, r = w.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (w[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        int n = words.size(), m = queries.size();
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            w[i] = Count(words[i]);
        }
        sort(w.begin(), w.end());
        vector<int> res(m);
        for (int i = 0; i < m; ++i) {
            int target = Count(queries[i]);
            res[i] = n - Bfind(target + 1, w);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> queries;
    LeetCodeIO::scan(cin, queries);
    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();

    auto res = obj->numSmallerByFrequency(queries, words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
