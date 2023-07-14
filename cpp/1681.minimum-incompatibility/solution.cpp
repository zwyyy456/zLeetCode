// Created by zwyyy456 at 2023/06/28 10:35
// leetgo: 1.3.1
// https://leetcode.com/problems/minimum-incompatibility/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minimumIncompatibility(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
            if (cnt[nums[i]] > k) {
                return -1;
            }
        }
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

    auto res = obj->minimumIncompatibility(nums, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
