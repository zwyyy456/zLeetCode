// Created by zwyyy456 at 2023/10/15 16:27
// leetgo: 1.3.8
// https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            res = res ^ nums[i];
        }
        // 找出 res 的第一个 1
        int c = (res & (-res));
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & c) {
                res1 = res1 ^ nums[i];
            } else {
                res2 = res2 ^ nums[i];
            }
        }
        return {res1, res2};
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->singleNumber(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
