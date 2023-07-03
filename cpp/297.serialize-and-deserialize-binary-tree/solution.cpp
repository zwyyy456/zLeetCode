// Created by zwyyy456 at 2023/03/23 09:38
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/*
297. Serialize and Deserialize Binary Tree (Hard)

Serialization is the process of converting a data structure or object into a sequence of bits so
that it can be stored in a file or memory buffer, or transmitted across a network connection link to
be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can
be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary
tree](https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation-).
You do not necessarily need to follow this format, so please be creative and come up with different
approaches yourself.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

```

**Example 2:**

```
Input: root = []
Output: []

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10⁴]`.
- `-1000 <= Node.val <= 1000`
*/

// @lc code=begin
// #include "TreeNode.h"
#include <string>
#include <list>
using std::list;
using std::string;
using std::vector;
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += std::to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// @lc code=end
