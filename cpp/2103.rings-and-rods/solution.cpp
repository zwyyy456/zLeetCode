// Created by zwyyy456 at 2023/11/02 20:16
// leetgo: 1.3.8
// https://leetcode.com/problems/rings-and-rods/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countPoints(string rings) {
        int n = rings.size() / 2;
        int road[10] = {0};
        for (int i = 0; i < 10; ++i) {
            road[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            int idx = rings[2 * i + 1] - '0';
            char c = rings[2 * i];
            int val;
            if (c == 'R') {
                val = 2;
            } else if (c == 'G') {
                val = 3;
            } else {
                val = 5;
            }
            road[idx] *= val;
        }
        int res = 0;
        for (int i = 0; i < 10; ++i) {
            if (road[i] % 30 == 0) {
                ++res;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string rings;
    LeetCodeIO::scan(cin, rings);

    Solution *obj = new Solution();
    auto res = obj->countPoints(rings);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
