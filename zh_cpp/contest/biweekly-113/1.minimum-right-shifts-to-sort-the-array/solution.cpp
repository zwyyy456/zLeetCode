// Created by zwyyy456 at 2023/09/16 22:30
// leetgo: 1.3.5
// https://leetcode.cn/problems/minimum-right-shifts-to-sort-the-array/
// https://leetcode.cn/contest/biweekly-contest-113/problems/minimum-right-shifts-to-sort-the-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minimumRightShifts(vector<int> &nums) {
        vector<int> tmp(nums.begin(), nums.end());
        vector<int> vec2(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            vec2.push_back(nums[i]);
        }
        int n = nums.size();
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            for (int j = 1; j < nums.size(); ++i) {
                if (vec2[i + j] <= vec2[i + j - 1]) {
                    break;
                }
                ++cnt;
            }
            if (cnt == n) {
                idx = i;
            }
        }
        return idx == -1 ? -1 : n - idx;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->minimumRightShifts(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
