// Created by zwyyy456 at 2023/10/06 14:36
// leetgo: 1.3.8
// https://leetcode.com/problems/shifting-letters-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = s.size();
        const int mod = 26;
        vector<int> diff(n + 1);
        for (auto &vec : shifts) {
            int l = vec[0], r = vec[1];
            if (vec[2] == 1) {
                diff[l] += 1;
                diff[r + 1] -= 1;
            } else {
                diff[l] -= 1;
                diff[r + 1] += 1;
            }
        }
        int sum = 0;
        vector<int> ans(n);
        ans[0] = diff[0];
        sum = diff[0];
        for (int i = 1; i < n; ++i) {
            sum += diff[i];
            ans[i] = sum;
        }
        string res;
        for (int i = 0; i < n; ++i) {
            int change = ((s[i] - 'a' + ans[i]) % mod + mod) % mod;
            res.push_back('a' + change);
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
    vector<vector<int>> shifts;
    LeetCodeIO::scan(cin, shifts);

    Solution *obj = new Solution();
    auto res = obj->shiftingLetters(s, shifts);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
