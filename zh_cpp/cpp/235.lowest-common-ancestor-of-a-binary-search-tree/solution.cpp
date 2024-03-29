// Created by Bob at 2023/06/12 14:23
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
235. 二叉搜索树的最近公共祖先 (Medium)
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E
5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin) 中最
近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共
祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能
大（ **一个节点也可以是它自己的祖先**）。”

例如，给定如下二叉搜索树:  root = \[6,2,8,0,4,7,9,null,null,
3,5\]

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/
2018/12/14/binarysearchtree_improved.png)

**示例 1:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。

```

**示例 2:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公
共祖先节点可以为节点本身。
```

**说明:**

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉搜索树中。

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val > p->val) {
            // p 在 root 的左子树
            if (root->val <= q->val) {
                // q 在 root 的右子树
                return root;
            }
            // q 在 root 的左子树
            return lowestCommonAncestor(root->left, p, q);
        }
        // p 在 root 的右子树, root->val <= p->val
        if (root->val < p->val) {
            if (root->val >= q->val) {
                return root;
            }
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
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
