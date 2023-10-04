// Created by zwyyy456 at 2023/09/13 10:03
// leetgo: 1.3.8
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void string2vec(string &preorder, vector<string> &strs) {
        for (int i = 0; i < preorder.size(); ++i) {
            int r = i;
            while (r < preorder.size() && preorder[r] != ',') {
                ++r;
            }
            strs.push_back(preorder.substr(i, r - i));
            i = r;
        }
    }
    bool check(vector<string> &strs, int l, int r) {
        if (strs[l] == "#") {
            return r - l == 1;
        }
        bool res = true;
        int i = l;
        for (int i = l; i < r; ++i) {
            if (strs[i] == "#") {
                break;
            }
        }
        bool lres = check(strs, l + 1, i);
        bool rres = check(strs, i + 1, r);
    }
    bool isValidSerialization(string preorder) {
        vector<string> strs;
        string2vec(preorder, strs);
        int n = strs.size();
        stack<string> stk;
        for (int i = 0; i < n; ++i) {
            if (strs[i] != "#") {
                stk.push(strs[i]);
            } else {
                while (stk.size() >= 2 && stk.top() == "#") {
                    stk.pop();
                    if (stk.top() == "#") {
                        return false;
                    }
                    stk.pop();
                }
                stk.push("#");
            }
        }
        return stk.size() == 1 && stk.top() == "#";
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string preorder;
    LeetCodeIO::scan(cin, preorder);

    Solution *obj = new Solution();
    auto res = obj->isValidSerialization(preorder);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
