// Created by zwyyy456 at 2023/07/23 11:14
// leetgo: 1.3.1
// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> sufmax(n);
        sufmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufmax[i] = max(sufmax[i + 1], height[i]);
        }
        vector<int> premax(n);
        premax[0] = height[0];
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            int cur = height[i];
            int h = min(premax[i - 1], sufmax[i + 1]);
            if (h > cur) {
                res += h - cur;
            }
            premax[i] = max(cur, premax[i - 1]);
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

    auto res = obj->trap(height);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
