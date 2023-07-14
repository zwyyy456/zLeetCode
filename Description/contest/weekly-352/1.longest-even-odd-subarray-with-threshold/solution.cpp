// Created by zwyyy456 at 2023/07/02 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/
// https://leetcode.cn/contest/weekly-contest-352/problems/longest-even-odd-subarray-with-threshold/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        // 双指针
        int l = -1, r = 0;
        int n = nums.size();
        int res = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                l = i;
                r = i + 1;
                break;
            }
        }
        if (l == -1) {
            return 0;
        }
        while (r < n) {
            if (nums[r] <= threshold && (r == 0 || (nums[r - 1] % 2 != nums[r] % 2))) {
                ++r;
                res = max(r - l, res);
            } else {
                l = r;
                ++r;
                while (l < n && (nums[l] % 2 != 0 || nums[l] > threshold)) {
                    ++l;
                    ++r;
                }
            }
        }
        return max(res, r - l);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int threshold;
    LeetCodeIO::scan(cin, threshold);

    Solution *obj = new Solution();

    auto res = obj->longestAlternatingSubarray(nums, threshold);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
