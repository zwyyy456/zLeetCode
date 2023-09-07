// Created by zwyyy456 at 2023/08/27 10:02
// leetgo: 1.3.1
// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > right) {
                left = intervals[i][0];
                right = intervals[i][1];
                res.push_back(intervals[i]);
            } else {
                right = max(right, intervals[i][1]);
                res.back()[1] = right;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> intervals;
    LeetCodeIO::scan(cin, intervals);

    Solution *obj = new Solution();

    auto res = obj->merge(intervals);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
