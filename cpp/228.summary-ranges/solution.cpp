// Created by zwyyy456 at 2023/08/27 10:11
// leetgo: 1.3.1
// https://leetcode.com/problems/summary-ranges/

#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int n = nums.size();
        if (nums.empty()) {
            return res;
        }
        int l = nums[0], r = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] == 1) {
                r = nums[i];
            } else {
                if (l != r) {
                    res.push_back(to_string(l) + "->" + to_string(r));
                } else {
                    res.push_back(to_string(l));
                }
                l = nums[i];
                r = nums[i];
            }
        }
        if (l != r) {
            res.push_back(to_string(l) + "->" + to_string(r));
        } else {
            res.push_back(to_string(l));
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

    auto res = obj->summaryRanges(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
