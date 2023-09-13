// Created by zwyyy456 at 2023/09/12 11:03
// leetgo: 1.3.8
// https://leetcode.com/problems/unique-binary-search-trees/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numtree(int l, int r) {
        // 左闭右开
        if (l >= r) {
            return 1;
        }
        int num = 0;
        for (int i = l; i < r; ++i) {
            num += numtree(l, i) * numtree(i + 1, r);
        }
        return num;
    }
    int numTrees(int n) {
        return numtree(0, n);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->numTrees(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
