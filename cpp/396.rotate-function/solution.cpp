// Created by zwyyy456 at 2023/08/19 14:12
// leetgo: 1.3.1
// https://leetcode.com/problems/rotate-function/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxRotateFunction(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> fn(n);
        for (int i = 0; i < n; ++i) {
            fn[0] += i * nums[i];
        }
        int res = fn[0];
        for (int i = 1; i < n; ++i) {
            fn[i] = fn[i - 1] + sum - n * nums[(n - i) % n];
            res = max(res, fn[i]);
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

    auto res = obj->maxRotateFunction(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
