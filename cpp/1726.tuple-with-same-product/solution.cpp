// Created by zwyyy456 at 2023/10/19 09:32
// leetgo: 1.3.8
// https://leetcode.com/problems/tuple-with-same-product/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int tupleSameProduct(vector<int> &nums) {
        map<int, int> mp;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++mp[nums[i] * nums[j]];
            }
        }
        for (auto &[res, cnt] : mp) {
            res = res + cnt * (cnt - 1) / 2;
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->tupleSameProduct(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
