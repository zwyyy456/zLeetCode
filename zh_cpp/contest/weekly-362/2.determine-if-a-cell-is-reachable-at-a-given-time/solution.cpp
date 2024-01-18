// Created by zwyyy456 at 2023/09/10 11:13
// leetgo: 1.3.8
// https://leetcode.cn/problems/determine-if-a-cell-is-reachable-at-a-given-time/
// https://leetcode.cn/contest/weekly-contest-362/problems/determine-if-a-cell-is-reachable-at-a-given-time/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return t >= max(abs(fx - sx), abs(fy - sy));
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int sx;
    LeetCodeIO::scan(cin, sx);
    int sy;
    LeetCodeIO::scan(cin, sy);
    int fx;
    LeetCodeIO::scan(cin, fx);
    int fy;
    LeetCodeIO::scan(cin, fy);
    int t;
    LeetCodeIO::scan(cin, t);

    Solution *obj = new Solution();
    auto res = obj->isReachableAtTime(sx, sy, fx, fy, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
