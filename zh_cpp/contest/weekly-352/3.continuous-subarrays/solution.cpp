// Created by zwyyy456 at 2023/07/02 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/continuous-subarrays/
// https://leetcode.cn/contest/weekly-contest-352/problems/continuous-subarrays/

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long continuousSubarrays(vector<int> &nums) {
        long res = 0;
        unordered_map<int, int> rec;

        int n = nums.size();
        vector<int> dp(n);
        map<int, int> three;
        // val 表示 key 对应的最右侧的坐标
        for (int i = 0; i < n; ++i) {
            // 维护一个三元组，表示以当前为最右端点的最长子数组的最大值，最小值，中间值
            if (three.empty()) {
                three[nums[i]] = i;
                dp[i] = 1;
                res += 1;
            } else {
                int l = 0;
                bool flag = false;
                for (auto &pai : three) {
                    if (abs(nums[i] - pai.first) >= 2) {
                        l = max(l, pai.second);
                        three.erase(pai.first);
                        flag = true;
                    }
                }
                three[nums[i]] = i;
                if (!flag) {
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = i - l;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            res += dp[i];
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

    auto res = obj->continuousSubarrays(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
