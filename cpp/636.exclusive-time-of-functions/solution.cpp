// Created by zwyyy456 at 2023/07/14 21:34
// leetgo: 1.3.2
// https://leetcode.com/problems/exclusive-time-of-functions/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n);
        stack<tuple<int, int, int>> stk;
        for (auto &str : logs) {
            char c = 0;
            int id = 0;
            int stamp = 0;
            bool flag = false;
            bool flag_end = false;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == ':') {
                    if (!flag) {
                        c = str[i + 1];
                        flag = true;
                    } else {
                        flag_end = true;
                    }
                } else {
                    if (!flag) {
                        id = id * 10 + str[i] - '0';
                    } else if (flag && flag_end) {
                        stamp = stamp * 10 + str[i] - '0';
                    }
                }
            }
            if (c == 's') {
                stk.push({id, stamp, 0});
            } else {
                auto [idx, start, occupied] = stk.top();
                stk.pop();
                int tmp = stamp - start + 1 - occupied;
                res[idx] += tmp;
                if (!stk.empty()) {
                    auto [idx_tmp, start_tmp, occ_tmp] = stk.top();
                    stk.pop();
                    stk.push({idx_tmp, start_tmp, occ_tmp + tmp + occupied});
                }
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
    vector<string> logs;
    LeetCodeIO::scan(cin, logs);

    Solution *obj = new Solution();

    auto res = obj->exclusiveTime(n, logs);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
