// Created by zwyyy456 at 2023/09/17 10:33
// leetgo: 1.3.5
// https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/
// https://leetcode.cn/contest/weekly-contest-363/problems/sum-of-values-at-indices-with-k-set-bits/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int getk(int num) {
        int cnt = 0;
        while (num != 0) {
            if (num % 2 == 1) {
                ++cnt;
            }
            num = num / 2;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> cnts(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (getk(nums[i]) == k) {
                res += nums[i];
            }
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
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->sumIndicesWithKSetBits(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
