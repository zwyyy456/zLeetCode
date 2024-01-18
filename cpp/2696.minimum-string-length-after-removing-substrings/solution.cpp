// Created by zwyyy456 at 2024/01/10 23:42
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minLength(string s) {
        vector<int> stk;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B' && !stk.empty() && stk.back() == 'A') {
                stk.pop_back();
            } else if (s[i] == 'D' && !stk.empty() && stk.back() == 'C') {
                stk.pop_back();
            } else {
                stk.push_back(s[i]);
            }
        }
        return stk.size();
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();
    auto res = obj->minLength(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
