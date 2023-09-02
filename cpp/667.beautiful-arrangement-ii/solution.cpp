// Created by zwyyy456 at 2023/08/21 10:47
// leetgo: 1.3.5
// https://leetcode.com/problems/beautiful-arrangement-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res[i] = i + 1;
        }
        int i = 0;
        while (k >= 1) {
            if (i % 2 == 0) {
                res[i] = k;
                --k;
            } else {
                res[i] = i / 2 + 1;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->constructArray(n, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
