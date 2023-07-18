// Created by zwyyy456 at 2023/07/10 12:35
// leetgo: 1.3.1
// https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void two_sum(vector<int> &nums, int target, int &near, int left, int n, vector<int> &res) {
        int l = left + 1, r = n - 1;
        while (l < r) {
            int tmp = nums[left] + nums[l] + nums[r];
            if (abs(tmp - target) < abs(near - target)) {
                res = {nums[left], nums[l], nums[r]};
                near = tmp;
            }
            if (tmp > target) {
                --r;
            } else if (tmp == target) {
                return;
            } else {
                ++l;
            }
        }
    }
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int near = INT_MAX / 2;
        int l = 0;
        vector<int> res{-1, -1, -1};
        for (int l = 0; l < n - 2; ++l) {
            two_sum(nums, target, near, l, n, res);
            if (near == target) {
                return near;
            }
        }
        return near;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();

    auto res = obj->threeSumClosest(nums, target);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
