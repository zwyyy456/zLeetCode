// Created by zwyyy456 at 2023/06/19 10:20
// leetgo: 1.3.1
// https://leetcode.cn/problems/parallel-courses-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> relations;
    LeetCodeIO::scan(cin, relations);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->minNumberOfSemesters(n, relations, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output : " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
