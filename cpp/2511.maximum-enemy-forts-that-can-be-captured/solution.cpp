// Created by zwyyy456 at 2023/09/02 10:40
// leetgo: 1.3.1
// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int captureForts(vector<int> &forts) {
        int r = 0, l = 0;
        int n = forts.size();
        int cnt = 0;
        int res = 0;
        while (l < n && forts[l] != 1) {
            ++l;
        }
        while (l < n) {
            while (r < n && forts[r] != -1) {
                ++r;
            }
            while (l < r) {
                if (forts[l] == 0) {
                    ++cnt;
                }
                ++l;
            }
            res = max(res, cnt);
            cnt = 0;
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> forts;
    LeetCodeIO::scan(cin, forts);

    Solution *obj = new Solution();

    auto res = obj->captureForts(forts);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
