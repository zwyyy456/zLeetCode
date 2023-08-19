// Created by zwyyy456 at 2023/07/27 10:00
// leetgo: 1.3.1
// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int uniqueLetterString(string s) {
        vector<vector<int>> same(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'A';
            same[idx].push_back(i);
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < same[i].size(); ++j) {
                int left = 0, right = 0;
                if (j == 0) {
                    left = same[i][j] + 1;
                } else {
                    left = same[i][j] - same[i][j - 1];
                }
                if (j == same[i].size() - 1) {
                    right = n - same[i][j];
                } else {
                    right = same[i][j + 1] - same[i][j];
                }
                res += left * right;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->uniqueLetterString(s);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
