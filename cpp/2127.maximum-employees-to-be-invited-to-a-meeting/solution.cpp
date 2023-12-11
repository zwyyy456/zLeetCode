// Created by zwyyy456 at 2023/11/02 23:03
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maximumInvitations(vector<int> &favorite) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> favorite;
    LeetCodeIO::scan(cin, favorite);

    Solution *obj = new Solution();
    auto res = obj->maximumInvitations(favorite);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
