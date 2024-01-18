// Created by zwyyy456 at 2023/09/17 10:33
// leetgo: 1.3.5
// https://leetcode.cn/problems/happy-students/
// https://leetcode.cn/contest/weekly-contest-363/problems/happy-students/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int countWays(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        // 大家都被选中
        if (nums[n - 1] < n) {
            res += 1;
        }
        // 大家都没有被选中
        if (nums[0] > 0) {
            res += 1;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] < (i + 1) && nums[i + 1] > (i + 1)) {
                res += 1;
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

    Solution *obj = new Solution();
    auto res = obj->countWays(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
