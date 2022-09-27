#include <deque>
using std::deque;

class Solution {
  public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        deque<TreeNode *> dq;
        int lvl = 0;
        if (root == nullptr)
            return root;
        dq.push_back(root);
        while (!dq.empty()) {
            lvl++;
            int sz = dq.size();
            TreeNode *node;
            for (int i = 0; i < sz; i++) {
                node = dq.front();
                dq.pop_front();
                if (node->left != nullptr)
                    dq.push_back(node->left);
                if (node->right != nullptr)
                    dq.push_back(node->right);
            }
            sz = dq.size();
            if (lvl % 2 == 1) {
                for (int l = 0, r = sz - 1; l <= r; l++, r--) {
                    int temp = dq[l]->val;
                    dq[l]->val = dq[r]->val;
                    dq[r]->val = temp;
                }
            }
        }
        return root;
    }
};