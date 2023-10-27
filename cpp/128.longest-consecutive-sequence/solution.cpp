// Created by zwyyy456 at 2023/10/18 10:52
// leetgo: 1.3.8
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        unordered_set<int> ust;
        int mn = nums[0];
        for (int i = 0; i < n; ++i) {
            ust.insert(nums[i]);
            if (nums[i] < mn) {
                mn = nums[i];
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (ust.find(nums[i] - 1) != ust.end()) {
                continue;
            }
            int tmp = 0, k = nums[i];
            while (ust.find(k) != ust.end()) {
                tmp += 1;
                ++k;
            }
            res = max(res, tmp);
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
    auto res = obj->longestConsecutive(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
