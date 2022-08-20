#include <iostream>
#include <stack>
#include <vector>
using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != nullptr)
            st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            //对节点进行遍历
            if (node != nullptr) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right != nullptr)
                    st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left != nullptr)
                    st.push(node->left);
            } else { //依次处理节点
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != nullptr)
            st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right != nullptr)
                    st.push(node->right);
                if (node->left != nullptr)
                    ;
                st.push(node->left);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != nullptr)
            st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right != nullptr)
                    st.push(node->right);
                if (node->left != nullptr)
                    st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
    }
};
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> st;
    if (root != nullptr)
        st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node != nullptr) {
            st.pop();
            st.push(node);
            st.push(nullptr);
            if (node->right != nullptr)
                st.push(node->right);
            if (node->left != nullptr)
                st.push(node->left);
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
}
