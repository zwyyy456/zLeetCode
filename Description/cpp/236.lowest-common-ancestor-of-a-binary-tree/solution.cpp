// Created by Bob at 2023/06/12 13:52
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

/*
236. 二叉树的最近公共祖先 (Medium)
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin) 中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（ **一个节点也可以是它自己的祖先**）。”

**示例 1：**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

```

**示例 3：**

```
输入：root = [1,2], p = 1, q = 2
输出：1

```

**提示：**

- 树中节点数目在范围 `[2, 10⁵]` 内。
- `-10⁹ <= Node.val <= 10⁹`
- 所有 `Node.val` `互不相同` 。
- `p != q`
- `p` 和 `q` 均存在于给定的二叉树中。

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    pair<bool, bool> Ancestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **res) {
        if (root == nullptr) {
            return {false, false};
        }
        auto flagp = root == p, flagq = root == q;
        auto [pleft, qleft] = Ancestor(root->left, p, q, res);
        auto [pright, qright] = Ancestor(root->right, p, q, res);
        bool res_p = flagp || pleft || pright;
        bool res_q = flagq || qleft || qright;
        // 最近公共祖先的条件
        // 左子树，右子树都不是最近公共祖先
        if (res_p && res_q && !(pleft && qleft) && !(pright && qright)) {
            *res = root;
        }
        return {pleft || pright || flagp, qleft || qright || flagq};
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *res = nullptr;
        Ancestor(root, p, q, &res);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int p;
    LeetCodeIO::scan(cin, p);
    int q;
    LeetCodeIO::scan(cin, q);

    Solution *obj = new Solution();

    auto res = obj->lowestCommonAncestor(root, p, q);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
