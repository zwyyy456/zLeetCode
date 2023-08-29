// Created by zwyyy456 at 2023/08/24 09:10
// leetgo: 1.3.5
// https://leetcode.com/problems/strange-printer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int strangePrinter(string s) {
        // 是否可以认为只有两种方案，修改中间和追加
        // dp[n]
        int n = s.size();
        string str;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                continue;
            }
            str.push_back(s[i]);
        }
        vector<int> chars(26);
        int m = str.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for (int i = 0; i < m; ++i) {
            dp[i][i] = 1;
        }
        // 左闭右开
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i + 1; j < m; ++j) {
                int res = 0x3f3f3f3f;
                for (int k = i + 1; k <= j; ++k) {
                    if (str[k] == str[i]) {
                        res = min(res, dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
                res = min(res, dp[i + 1][j] + 1);
                dp[i][j] = res;
            }
        }

        return dp[0][m - 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();
    auto res = obj->strangePrinter(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
