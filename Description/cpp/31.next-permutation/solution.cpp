// Created by zwyyy456 at 2023/08/08 09:55
// leetgo: 1.3.5
// https://leetcode.cn/problems/next-permutation/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int resr = 0, resl = -1;
        int rnum = nums[n - 1], lnum = nums[n - 1];
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] >= rnum) {
                resr = i;
                rnum = nums[i];
            } else if (nums[i] < rnum) {
                resl = i;
                lnum = nums[i];
                break;
            }
        }
        for (int i = n - 1; i > lnum; --i) {
            if (nums[i] > lnum && nums[i] < rnum) {
                resr = i;
                rnum = nums[i];
            }
        }
        if (resl < 0) {
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[resl], nums[resr]);
            sort(nums.begin() + resl + 1, nums.end());
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->nextPermutation(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
