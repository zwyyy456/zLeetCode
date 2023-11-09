// Created by zwyyy456 at 2023/10/18 11:16
// leetgo: 1.3.8
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                res = max(res, (r - l) * height[l]);
                ++l;
            } else {
                res = max(res, (r - l) * height[r]);
                ++r;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> height;
    LeetCodeIO::scan(cin, height);

    Solution *obj = new Solution();
    auto res = obj->maxArea(height);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
