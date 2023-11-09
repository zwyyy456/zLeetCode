// Created by zwyyy456 at 2023/11/07 10:29
// leetgo: 1.3.8
// https://leetcode.com/problems/super-washing-machines/

#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findMinMoves(vector<int> &machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (total % n != 0) {
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            machines[i] -= total / n;
        }
        int left = 0;
        for (int i = 0; i < n; ++i) {
            left += machines[i];
            if (machines[i] > 0) {
                if (left <= 0) {
                }
            }
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> machines;
    LeetCodeIO::scan(cin, machines);

    Solution *obj = new Solution();
    auto res = obj->findMinMoves(machines);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
