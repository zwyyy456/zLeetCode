// Created by zwyyy456 at 2023/08/21 10:30
// leetgo: 1.3.5
// https://leetcode.com/problems/bulb-switcher-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int flipLights(int n, int presses) {
        n = min(n, 6);
        // 4 个按钮，对应四种操作
        vector<int> ops = {0b111111, 0b010101, 0b101010, 0b100100};
        unordered_set<int> vis;
        for (int mask = 0; mask < 1 << 4; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt > presses || cnt % 2 != presses % 2) continue;
            int t = 0;
            for (int i = 0; i < 4; ++i) {
                if (mask >> i & 1) {
                    t ^= ops[i];
                }
            }
            t &= (1 << 6) - 1;
            t >>= (6 - n);
            vis.insert(t);
        }
        return vis.size();
    }

}; // @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int presses;
    LeetCodeIO::scan(cin, presses);

    Solution *obj = new Solution();
    auto res = obj->flipLights(n, presses);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
