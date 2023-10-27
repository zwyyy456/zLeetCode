// Created by zwyyy456 at 2023/10/20 09:56
// leetgo: 1.3.8
// https://leetcode.com/problems/categorize-box-according-to-criteria/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string categorizeBox(int length, int width, int height, int mass) {
        const int a1 = 1e4;
        const long v = 1e9;
        vector<int> ans(2);
        if (length >= a1 || width >= a1 || height >= a1 || (long)length * width * height > v) {
            ans[0] = 1;
        }
        if (mass >= 100) {
            ans[1] = 1;
        }
        if (ans[0] + ans[1] == 2) {
            return "Both";
        }
        if (ans[0] + ans[1] == 0) {
            return "Neither";
        }
        if (ans[0] == 1) {
            return "Bulky";
        }
        return "Heavy";
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int length;
    LeetCodeIO::scan(cin, length);
    int width;
    LeetCodeIO::scan(cin, width);
    int height;
    LeetCodeIO::scan(cin, height);
    int mass;
    LeetCodeIO::scan(cin, mass);

    Solution *obj = new Solution();
    auto res = obj->categorizeBox(length, width, height, mass);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
