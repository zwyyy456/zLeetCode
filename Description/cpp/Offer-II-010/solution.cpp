// Created by zwyyy456 at 2023/08/02 14:14
// leetgo: 1.3.1
// https://leetcode.cn/problems/QTMn0o/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        // 前缀和 + 哈希表
        int sum = 0;
        unordered_map<int, int> sum_log;
        sum_log[0] = 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum_log.find(sum - k) != sum_log.end()) {
                res += sum_log[sum - k];
            }
            ++sum_log[sum];
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

    auto res = obj->subarraySum(nums, k);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
