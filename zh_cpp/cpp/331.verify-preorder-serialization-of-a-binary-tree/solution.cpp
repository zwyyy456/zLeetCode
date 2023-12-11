// Created by zwyyy456 at 2023/09/13 11:11
// leetgo: 1.3.8
// https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/

#include <bits/stdc++.h>
#include <vector>
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
    bool dfs(vector<string> &strs, int &idx) {
        if (idx >= strs.size()) {
            return false;
        }
        if (strs[idx] == "#") {
            ++idx;
            return true;
        }
        ++idx;
        return dfs(strs, idx) && dfs(strs, idx);
    }
    bool isValidSerialization(string preorder) {
        vector<string> strs;
        string2vec(preorder, strs);
        int idx = 0;
        return dfs(strs, idx) && idx == strs.size();
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
