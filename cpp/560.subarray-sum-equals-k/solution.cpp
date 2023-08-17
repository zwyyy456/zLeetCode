// Created by zwyyy456 at 2023/08/17 20:43
// leetgo: 1.3.5
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        // 前缀和 + 哈希表
        int res = 0;
        unordered_map<int, int> cnt;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (cnt.find(sum - k) != cnt.end()) {
                res += cnt[sum - k];
            }
            ++cnt[sum];
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
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
