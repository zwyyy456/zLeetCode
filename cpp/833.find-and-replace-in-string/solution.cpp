// Created by zwyyy456 at 2023/08/15 15:10
// leetgo: 1.3.5
// https://leetcode.com/problems/find-and-replace-in-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(string &s, int idx, string &cmp) {
        int l = cmp.size();
        for (int i = 0; i < l; ++i) {
            if (cmp[i] != cmp[i + idx]) {
                return false;
            }
        }
        return true;
    }
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        vector<char> str(s.begin(), s.end());
        int n = s.size();
        vector<pair<int, string>> changes;
        int k = indices.size();
        for (int i = 0; i < k; ++i) {
            if (check(s, indices[i], sources[i])) {
                changes.push_back({indices[i], sources[i]});
            }
        }
        // 开始修改
        for (auto &p : changes) {
            int l = p.second.size();
            for (int i = 0; i < l; ++i) {
                str[i + p.first] = p.second[i];
            }
        }
        string res(str.begin(), str.end());
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    vector<int> indices;
    LeetCodeIO::scan(cin, indices);
    vector<string> sources;
    LeetCodeIO::scan(cin, sources);
    vector<string> targets;
    LeetCodeIO::scan(cin, targets);

    Solution *obj = new Solution();
    auto res = obj->findReplaceString(s, indices, sources, targets);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
