// Created by zwyyy456 at 2023/08/03 09:53
// leetgo: 1.3.1
// https://leetcode.cn/problems/aseY1I/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        vector<int> word_bits(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                word_bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((word_bits[i] & word_bits[j]) == 0) {
                    int tmp = words[i].size() * words[j].size();
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();

    auto res = obj->maxProduct(words);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
