// Created by zwyyy456 at 2024/01/13 16:23
// leetgo: 1.3.8
// https://leetcode.com/problems/construct-string-with-repeat-limit/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> arr;
        for (char c : s) {
            arr[c]++;
        }
        string ans;
        int cnt = 0, idx = 25;
        while (idx >= 0) {
            while (arr[idx] > 0 && cnt < repeatLimit) {
                ans.push_back(idx + 'a');
                --arr[idx];
                ++cnt;
            }
            cnt = 0;
            --idx;
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    int repeatLimit;
    LeetCodeIO::scan(cin, repeatLimit);

    Solution *obj = new Solution();
    auto res = obj->repeatLimitedString(s, repeatLimit);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
