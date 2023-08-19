// Created by zwyyy456 at 2023/08/03 08:44
// leetgo: 1.3.1
// https://leetcode.com/problems/remove-comments/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    vector<string> removeComments(vector<string> &source) {
        int block = 0;
        int line = 0;
        vector<string> res;
        string tmp;
        int n = source.size();
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < source[i].size(); ++j) {
                if (block == 0) {
                    if (source[i][j] == '/') {
                        if (j + 1 >= source[i].size() || (source[i][j + 1] != '/' && source[i][j + 1] != '*')) {
                            tmp.push_back(source[i][j]);
                        } else if (source[i][j + 1] == '/') {
                            break;
                        } else {
                            block = 1;
                            ++j;
                        }
                    } else {
                        tmp.push_back(source[i][j]);
                    }
                } else {
                    if (source[i][j] == '*' && j + 1 < source[i].size() && source[i][j + 1] == '/') {
                        block = 0;
                        ++j;
                    }
                }
            }
            if (!tmp.empty() && block == 0) {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> source;
    LeetCodeIO::scan(cin, source);

    Solution *obj = new Solution();

    auto res = obj->removeComments(source);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
