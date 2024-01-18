// Created by zwyyy456 at 2023/09/10 11:13
// leetgo: 1.3.8
// https://leetcode.cn/problems/string-transformation/
// https://leetcode.cn/contest/weekly-contest-362/problems/string-transformation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numberOfWays(string s, string t, long long k) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string t;
    LeetCodeIO::scan(cin, t);
    int64_t k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->numberOfWays(s, t, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
