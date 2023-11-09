// Created by zwyyy456 at 2023/10/23 09:20
// leetgo: 1.3.8
// https://leetcode.com/problems/smallest-rotation-with-highest-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    int bestRotation(vector<int> &nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            if (i - nums[i] < 0) {
                if (i - nums[i] + n > i) {
                    if (i + 1 < n) {
                        diff[i + 1] += 1;
                    }
                    if (i - nums[i] + n < n - 1) {
                        diff[i - nums[i] + n + 1] -= 1;
                    }
                }
            } else {
                diff[0] += 1;
                if (i - nums[i] < n - 1) {
                    diff[i - nums[i] + 1] -= 1;
                }
                if (i + 1 < n) {
                    diff[i + 1] += 1;
                }
            }
        }
        int sum = diff[0], mx = diff[0];
        int res = 0;
        for (int i = 1; i < n; ++i) {
            sum += diff[i];
            if (sum > mx) {
                res = i;
                mx = sum;
            }
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
    auto res = obj->bestRotation(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
