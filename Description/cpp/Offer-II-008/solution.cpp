// Created by zwyyy456 at 2023/06/16 16:33
// leetgo: 1.3.1
// https://leetcode.cn/problems/2VG8Kg/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Bfind(vector<int> &nums, int target, int r) {
        int l = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int minSubArrayLen(int target, vector<int> &nums) {
        // 前缀和 + 二分
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int len = 1e5 + 1;
        for (int r = 1; r <= n; ++r) {
            if (prefix[r] < target) {
                continue;
            }
            int l = Bfind(nums, prefix[r] - target + 1, r);
            len = min(len, r - l + 1);
        }
        return len;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int target;
    LeetCodeIO::scan(cin, target);
    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->minSubArrayLen(target, nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
