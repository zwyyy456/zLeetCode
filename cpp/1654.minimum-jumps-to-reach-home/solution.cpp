// Created by zwyyy456 at 2023/08/30 09:33
// leetgo: 1.3.5
// https://leetcode.com/problems/minimum-jumps-to-reach-home/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using ust = unordered_set<int>;
    const int ub = 0x3f3f3f3f;
    int dfs(ust &forbid, int a, int b, int x, int flag, int target) {
        if (a > b) {
            // 鉴于最多往回跳一次
            if (x > target + b) {
                return ub;
            }
            int res1 = ub, res2 = ub, res3 = ub;
            if (forbid.find(x - a) == forbid.end() && x - a >= 0) {
                res1 = dfs(forbid, a, b, x - a, flag, target);
            }
            return min(min(dfs(forbid, a, b, x - a, 0, target), dfs(forbid, a, b, x + b, 0, target)), dfs(forbid, a, b, x - a, 1, target)) + 1;
        }
    }
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        if (a > b) {
            // 鉴于最多往回跳一次
            return min(min(dfs(forbidden, a, b, x - a, 0), dfs(forbidden, a, b, x + b, 0)), dfs(forbidden, a, b, x - a, 1));
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> forbidden;
    LeetCodeIO::scan(cin, forbidden);
    int a;
    LeetCodeIO::scan(cin, a);
    int b;
    LeetCodeIO::scan(cin, b);
    int x;
    LeetCodeIO::scan(cin, x);

    Solution *obj = new Solution();
    auto res = obj->minimumJumps(forbidden, a, b, x);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
