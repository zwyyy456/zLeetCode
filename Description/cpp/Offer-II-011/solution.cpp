// Created by zwyyy456 at 2023/08/02 14:39
// leetgo: 1.3.1
// https://leetcode.cn/problems/A1NYOS/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        // 前缀和 + 哈希表
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> sum_log;
        int res = 0;
        sum_log[0] = -1;
        for (int i = 0; i < n; ++i) {
            int tmp = nums[i] == 0 ? -1 : 1;
            sum += tmp;
            if (sum_log.find(sum) != sum_log.end()) {
                res = max(i - sum_log[sum], res);
            } else {
                sum_log[sum] = i;
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

    auto res = obj->findMaxLength(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
