// Created by zwyyy456 at 2023/10/10 09:35
// leetgo: 1.3.8
// https://leetcode.com/problems/movement-of-robots/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int mod = 1e9 + 7;
    int sumDistance(vector<int> &nums, string s, int d) {
        // 如果最右边的机器人向右移动，那么它不参与碰撞
        // 时间足够长的情况下，一定是分成两批，一批统一往左，一批统一往右
        // 发生碰撞可以认为直接穿透？
        // 直接当碰撞不存在
        int n = nums.size();
        vector<long> loc(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                loc[i] = nums[i] - d;
            } else {
                loc[i] = nums[i] + d;
            }
        }
        sort(loc.begin(), loc.end());
        long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + i * loc[i] - (n - i - 1) * loc[i]) % mod;
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
    string s;
    LeetCodeIO::scan(cin, s);
    int d;
    LeetCodeIO::scan(cin, d);

    Solution *obj = new Solution();
    auto res = obj->sumDistance(nums, s, d);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
