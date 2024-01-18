// Created by zwyyy456 at 2024/01/14 15:39
// leetgo: 1.3.8
// https://leetcode.com/problems/count-common-words-with-one-occurrence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countWords(vector<string> &words1, vector<string> &words2) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> words1;
    LeetCodeIO::scan(cin, words1);
    vector<string> words2;
    LeetCodeIO::scan(cin, words2);

    Solution *obj = new Solution();
    auto res = obj->countWords(words1, words2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
