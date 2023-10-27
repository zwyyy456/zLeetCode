// Created by zwyyy456 at 2023/10/18 16:14
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> record;
        unordered_map<char, int> window;
        int m = s.size(), n = t.size();
        for (int i = 0; i < n; ++i) {
            ++record[t[i]];
            ++window[t[i]];
        }
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            if (record.find(s[r]) == record.end()) {
                ++r;
                continue;
            }
        }
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

    Solution *obj = new Solution();
    auto res = obj->minWindow(s, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
