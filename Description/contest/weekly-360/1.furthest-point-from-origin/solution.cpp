// Created by zwyyy456 at 2023/08/27 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/furthest-point-from-origin/
// https://leetcode.cn/contest/weekly-contest-360/problems/furthest-point-from-origin/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cntl = 0, cntr = 0, cnt_ = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (moves[i] == 'L') {
                ++cntl;
            } else if (moves[i] == 'R') {
                ++cntr;
            } else {
                ++cnt_;
            }
            res = max(res, abs(cntr - cntl - cnt_));
            res = max(res, abs(cntr + cnt_ - cntl));
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string moves;
    LeetCodeIO::scan(cin, moves);

    Solution *obj = new Solution();

    auto res = obj->furthestDistanceFromOrigin(moves);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
