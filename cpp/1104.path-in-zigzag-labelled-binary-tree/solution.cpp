// Created by zwyyy456 at 2023/09/03 09:37
// leetgo: 1.3.1
// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> pathInZigZagTree(int label) {
        int cnt = 0;
        int tmp = label;
        int total = 1;
        while (label > 0) {
            ++cnt;
            label /= 2;
            total *= 2;
        }
        label = tmp;
        vector<int> res;
        for (int i = cnt; i > 0; --i) {
            res.push_back(label);
            label = total - 1 + total / 2 - label;
            label /= 2;
            total /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int label;
    LeetCodeIO::scan(cin, label);

    Solution *obj = new Solution();

    auto res = obj->pathInZigZagTree(label);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
