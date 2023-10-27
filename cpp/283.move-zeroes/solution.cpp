// Created by zwyyy456 at 2023/10/18 11:13
// leetgo: 1.3.8
// https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        for (int i = k; i < n; ++i) {
            nums[i] = 0;
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
    auto res = obj->moveZeroes(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
