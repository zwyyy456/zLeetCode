// Created by zwyyy456 at 2023/09/11 14:18
// leetgo: 1.3.8
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *dfs(int l, int r, ListNode **head) {
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode *left = dfs(l, mid - 1, head);
        TreeNode *root = new TreeNode((*head)->val);
        root->left = left;
        *head = (*head)->next;
        root->right = dfs(mid + 1, r, head);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // 牢记，二叉搜索树的中序遍历结果是一个升序数组
        ListNode *tail = head;
        int cnt = 0;
        while (tail != nullptr) {
            ++cnt;
            tail = tail->next;
        }
        return dfs(0, cnt - 1, &head);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();
    auto res = obj->sortedListToBST(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
