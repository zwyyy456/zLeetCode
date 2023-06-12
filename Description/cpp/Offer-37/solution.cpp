// Created by Bob at 2023/06/07 09:35
// https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/

/*
剑指 Offer 37. 序列化二叉树 (Hard)
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定
你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以
被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

**提示：** 输入输出格式与 LeetCode 目前使用的方式一致，详情
请参阅 [LeetCode 序列化二叉树的格式](https://support.leetcod
e-cn.com/hc/kb/article/1567641/)。你并非必须采取这种方式，你
也可以采用其他的方法解决这个问题。

**示例：**

![](https://assets.leetcode.com/uploads/2020/09/15/serdeser.
jpg)

```
输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

```

注意：本题与主站 297 题相同： [https://leetcode-cn.com/probl
ems/serialize-and-deserialize-binary-tree/](https://leetcode
-cn.com/problems/serialize-and-deserialize-binary-tree/)

*/

#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "null,";
        }
        string res;
        res += to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<string> vec;
        int l = 0, r = 0;
        while (r < data.size()) {
            while (r < data.size() && data[r] != 'r') {
                ++r;
            }
            string tmp = data.substr(l, r - l);
            vec.push_back(tmp);
            l = ++r;
        }
        int idx = 0;
        deserialize(vec, idx);
    }
    TreeNode *deserialize(vector<string> &vec, int &idx) {
        if (idx == vec.size() || vec[0] == "null") {
            return nullptr;
        }
        int num = stoi(vec[0]);
        TreeNode *root = new TreeNode(num);
        idx++;
        root->left = deserialize(vec, idx);
        root->right = deserialize(vec, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->Codec(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
