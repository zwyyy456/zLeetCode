// Created by zwyyy456 at 2023/10/18 11:36
// leetgo: 1.3.8
// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        int res = 0;
        stack<int> stk; // 单调递减栈
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int h = height[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    res += (min(height[stk.top()], height[i]) - h) * (i - stk.top() - 1);
                }
            }
            stk.push(i);
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
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
