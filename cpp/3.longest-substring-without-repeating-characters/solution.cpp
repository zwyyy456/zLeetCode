// Created by zwyyy456 at 2023/10/18 15:41
// leetgo: 1.3.8
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char, int> cnt;
        while (r < s.size()) {
            char c = s[r];
            while (cnt[s[r]] < 2) {
                ++cnt[s[r]];
                c = s[r];
                ++r;
            }
            res = max(r - l, res);
            while (l < r && cnt[c] >= 2) {
                --cnt[s[l]];
                ++l;
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

    Solution *obj = new Solution();
    auto res = obj->lengthOfLongestSubstring(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
