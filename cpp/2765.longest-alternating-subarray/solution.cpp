// Created by zwyyy456 at 2024/01/23 18:22
// leetgo: 1.3.8
// https://leetcode.com/problems/longest-alternating-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int alternatingSubarray(vector<int> &nums) {
        if (nums.size() < 2) {
            return -1;
        }
        int r = 1, l = 0, mid = 0;
        int res = -1, state = 0;
        while (r < nums.size()) {
            if (nums[r] - nums[mid] == 1 && state == 0) {
                r++;
                mid++;
                res = max(res, r - l + 1);
                state = 1;
            } else if (nums[r] - nums[mid] == -1 && state == 1) {
                ++r;
                ++mid;
                res = max(res, r - l + 1);
                state = 0;
            } else {
                if (nums[r] - nums[mid] == 1 && state == 1) {
                    ++r;
                    l = mid;
                    ++mid;
                    state = 1;
                    res = max(res, 2);
                } else {
                    l = r;
                    ++r;
                    mid = l;
                }
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
    auto res = obj->alternatingSubarray(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
