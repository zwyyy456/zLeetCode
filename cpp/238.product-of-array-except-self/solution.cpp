// Created by zwyyy456 at 2023/08/17 20:27
// leetgo: 1.3.5
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // 前后缀分解
        int n = nums.size();
        vector<int> premul(n + 1, 1);
        vector<int> sufmul(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            premul[i] = premul[i - 1] * nums[i - 1];
            sufmul[i] = sufmul[i - 1] * nums[n - i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = premul[i] * sufmul[n - 1 - i];
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
    auto res = obj->productExceptSelf(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
