// Created by zwyyy456 at 2023/08/02 14:04
// leetgo: 1.3.1
// https://leetcode.cn/problems/ZVAVXX/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pre_count(n);
        queue<int> q;
        int mul_res = 1;
        for (int i = 0; i < n; ++i) {
            q.push(nums[i]);
            mul_res *= nums[i];
            while (!q.empty() && mul_res >= k) {
                mul_res /= q.front();
                q.pop();
            }
            pre_count[i] = q.size();
        }
        int res = accumulate(pre_count.begin(), pre_count.end(), 0);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->numSubarrayProductLessThanK(nums, k);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
