// Created by zwyyy456 at 2023/07/17 22:51
// leetgo: 1.3.2
// https://leetcode.com/problems/add-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string addStrings(string num1, string num2) {
        vector<char> res;
        int l1 = num1.size(), l2 = num2.size();
        int l = max(l1, l2);
        int residue = 0;
        for (int i = l - 1; i >= 0; --i) {
            int val1 = l1 - l + i >= 0 ? num1[l1 - l + i] - '0' : 0;
            int val2 = l2 - l + i >= 0 ? num2[l2 - l + i] - '0' : 0;
            res.push_back((val1 + val2 + residue) % 10);
            residue = (val1 + val2 + residue) / 10;
        }
        if (residue != 0) {
            res.push_back(residue + '0');
        }
        string ans(res.rbegin(), res.rend());
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string num1;
    LeetCodeIO::scan(cin, num1);
    string num2;
    LeetCodeIO::scan(cin, num2);

    Solution *obj = new Solution();

    auto res = obj->addStrings(num1, num2);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
