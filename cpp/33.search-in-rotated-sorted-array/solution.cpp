// Created by zwyyy456 at 2023/10/10 10:05
// leetgo: 1.3.8
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<int> &nums, int l, int r, int target) {
        // 左闭右开
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l < nums.size() && nums[l] == target) {
            return l;
        }
        return -1;
    }
    int search(vector<int> &nums, int target) {
        // 先找分界点
        // 分界点右侧的值都小于等于 nums[n - 1];
        int point = 0, n = nums.size();
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid > nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        point = l - 1;
        if (target > nums[n - 1]) {
            return bfind(nums, 0, l, target);
        }
        return bfind(nums, l, n, target);
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
    auto res = obj->search(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
