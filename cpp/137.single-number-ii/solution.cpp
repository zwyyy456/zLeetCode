// Created by zwyyy456 at 2023/10/15 12:41
// leetgo: 1.3.8
// https://leetcode.com/problems/single-number-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<int> cnt(32);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int i = 0; i < 32; ++i) {
                cnt[i] += ((nums[i] >> i) & 0x1);
            }
        }
        for (int i = 0; i < 32; ++i) {
        	nums[i] = nums[i] % 3;
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
        	res |= (nums[i] << i);	
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
    auto res = obj->singleNumber(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
