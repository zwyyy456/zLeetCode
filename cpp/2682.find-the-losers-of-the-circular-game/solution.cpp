// Created by zwyyy456 at 2023/08/16 09:48
// leetgo: 1.3.5
// https://leetcode.com/problems/find-the-losers-of-the-circular-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> men(n);
        int c = 1;
        int pre = 0;
        men[pre] = 1;
        while (true) {
            pre = (pre + c * k) % n;
            if (men[pre] == 1) {
                break;
            }
            men[pre] = 1;
            ++c;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (men[i] == 0) {
                res.push_back(i + 1);
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
    auto res = obj->circularGameLosers(n, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
