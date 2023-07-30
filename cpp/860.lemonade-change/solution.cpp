// Created by zwyyy456 at 2023/07/22 17:45
// leetgo: 1.3.2
// https://leetcode.com/problems/lemonade-change/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        int cnt[3] = {0}; // 0 表示 5 美元的数量，1 表示 10 美元的数量，2 为 20
        int n = bills.size();
        for (int i = 0; i < n; ++i) {
            // 优先用大面额
            if (bills[i] == 5) {
                cnt[0]++;
            } else if (bills[i] == 10) {
                if (cnt[0] == 0) {
                    return false;
                }
                --cnt[0];
                ++cnt[1];
            } else {
                if (cnt[1] == 0) {
                    if (cnt[0] < 3) {
                        return false;
                    }
                    cnt[0] -= 3;
                    ++cnt[2];
                } else {
                    --cnt[1];
                    if (cnt[0] == 0) {
                        return false;
                    }
                    --cnt[0];
                    ++cnt[2];
                }
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> bills;
    LeetCodeIO::scan(cin, bills);

    Solution *obj = new Solution();

    auto res = obj->lemonadeChange(bills);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
