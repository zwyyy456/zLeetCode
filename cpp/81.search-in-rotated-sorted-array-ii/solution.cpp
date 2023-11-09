// Created by zwyyy456 at 2023/10/10 10:24
// leetgo: 1.3.8
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

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
    bool search(vector<int> &nums, int target) {
        // 先看 nums[0] 与 nums[n - 1] 是否相等
        int n = nums.size();
        int point = -1;
        if (nums[0] == nums[n - 1]) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target) {
                    return true;
                }
            }
            return false;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
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
