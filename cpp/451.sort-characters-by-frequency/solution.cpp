// Created by zwyyy456 at 2023/07/12 23:10
// leetgo: 1.3.2
// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
#include <functional>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string frequencySort(string s) {
        vector<vector<int>> freq(26, vector<int>(2, 0));
        for (int i = 0; i < 26; ++i) {
            freq[i][1] = i;
        }
        for (char c : s) {
            freq[c - 'a'][0]++;
        }
        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        };
        sort(freq.begin(), freq.end(), cmp);
        string res;
        int i = 0;
        while (i < 26) {
            while (freq[i][0] > 0) {
                res.push_back(freq[i][1] + 'a');
                --freq[i][0];
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

    auto res = obj->frequencySort(s);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
