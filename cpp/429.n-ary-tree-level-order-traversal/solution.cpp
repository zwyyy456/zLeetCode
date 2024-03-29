/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> tmp;
            while(size--){
                Node *p=que.front();
                que.pop();
                tmp.push_back(p->val);
                for(int i=0;i<p->children.size();i++)
                    que.push(p->children[i]);
                //for(auto c:p->children)
                    //que.push(c);                
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

