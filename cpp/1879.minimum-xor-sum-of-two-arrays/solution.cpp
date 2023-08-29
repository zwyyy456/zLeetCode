// Created by zwyyy456 at 2023/08/28 10:56
// leetgo: 1.3.5
// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);

    Solution *obj = new Solution();
    auto res = obj->minimumXORSum(nums1, nums2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
