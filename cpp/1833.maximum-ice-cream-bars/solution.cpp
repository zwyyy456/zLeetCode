// Created by zwyyy456 at 2023/12/05 13:15
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-ice-cream-bars/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        const int n = 1e5 + 1;
        vector<int> cnt(n);
        for (int cost : costs) {
            cnt[cost]++;
        }
        int res = 0, i = 1;
        while (i < n && coins > 0) {
            if (cnt[i] > 0) {
                coins -= cnt[i];
                if (coins >= 0) {
                    ++res;
                }
            } else {
                ++i;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> costs;
    LeetCodeIO::scan(cin, costs);
    int coins;
    LeetCodeIO::scan(cin, coins);

    Solution *obj = new Solution();
    auto res = obj->maxIceCream(costs, coins);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
