// Created by Bob at 2023/06/12 13:45
// https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/

/*
1483. 树节点的第 K 个祖先 (Hard)
给你一棵树，树上有 `n` 个节点，按从 `0` 到 `n-1` 编号。树以
父节点数组的形式给出，其中 `parent[i]` 是节点 `i` 的父节点。
树的根节点是编号为 `0` 的节点。

树节点的第 `k`个祖先节点是从该节点到根节点路径上的第 `k` 个
节点。

实现 `TreeAncestor` 类：

- `TreeAncestor（int n， int[] parent）` 对树和父数组中的节
点数初始化对象。
- `getKthAncestor` `(int node, int k)` 返回节点 `node` 的第
`k` 个祖先节点。如果不存在这样的祖先节点，返回 `-1` 。

**示例 1：**

**![](https://assets.leetcode-cn.com/aliyun-lc-upload/upload
s/2020/06/14/1528_ex1.png)**

```
输入：
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAnc
estor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

输出：
[null,1,0,-1]

解释：
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1
, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父
节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖
父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满
足要求的祖先节点

```

**提示：**

- `1 <= k <= n <= 5 * 10⁴`
- `parent[0] == -1` 表示编号为 `0` 的节点是根节点。
- 对于所有的 `0 < i < n` ， `0 <= parent[i] < n` 总成立
- `0 <= node < n`
- 至多查询 `5 * 10⁴` 次

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class TreeAncestor {
  public:
    TreeAncestor(int n, vector<int> &parent) {
    }

    int getKthAncestor(int node, int k) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    TreeAncestor *obj;

    const unordered_map<string, function<void()>> methods = {
        {"TreeAncestor", [&]() {
             int n;
             LeetCodeIO::scan(cin, n);
             cin.ignore();
             vector<int> parent;
             LeetCodeIO::scan(cin, parent);
             cin.ignore();
             obj = new TreeAncestor(n, parent);
             out_stream << "null,";
         }},
        {"getKthAncestor", [&]() {
             int node;
             LeetCodeIO::scan(cin, node);
             cin.ignore();
             int k;
             LeetCodeIO::scan(cin, k);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getKthAncestor(node, k));
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
