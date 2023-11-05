// Created by zwyyy456 at 2023/11/05 10:19
// leetgo: 1.3.8
// https://leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> ump;
        for (int i = 0; i + 10 <= s.size(); ++i) {
            ump[s.substr(i, 10)]++;
        }
        vector<string> res;
        for (auto &[str, cnt] : ump) {
            if (cnt > 1) {
                res.push_back(str);
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
    auto res = obj->findRepeatedDnaSequences(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
