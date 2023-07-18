// Created by zwyyy456 at 2023/07/08 22:20
// leetgo: 1.3.2
// https://leetcode.com/problems/maximum-equal-frequency/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxEqualFreq(vector<int> &nums) {
        // 维护一个频率哈希表，记录每个频率元素种类数，
        unordered_map<int, int> freq_cnt;
        // 一个数字元素对应频率的哈希表
        unordered_map<int, int> num_freq;
        int res = 1, n = nums.size();
        int max_freq = 0, min_freq = n;
        for (int i = 0; i < n; ++i) {
            if (num_freq.find(nums[i]) == num_freq.end()) {
                num_freq[nums[i]] = 1;
                freq_cnt[1]++;
                min_freq = 1;
                max_freq = max(max_freq, 1);
                if (freq_cnt.size() == 1) {
                    res = max(res, i + 1);
                } else if (freq_cnt.size() == 2) {
                    // if (max_freq - min_freq == 1 && (freq_cnt[min_freq] == 1 || freq_cnt[max_freq] == 1)) {
                    // 	res = max(res, i + 1);
                    // }
                    if (freq_cnt[min_freq] == 1 || (max_freq - min_freq == 1 && freq_cnt[max_freq] == 1)) {
                        // 删掉最小的数或者最大的数
                        res = max(res, i + 1);
                    }
                }
            } else {
                int freq = num_freq[nums[i]];
                // 更新频率哈希表
                --freq_cnt[freq];
                ++freq_cnt[freq + 1];
                // 更新计数哈希表
                ++num_freq[nums[i]];
                if (min_freq == freq && freq_cnt[freq] == 0) {
                    freq_cnt.erase(freq);
                    min_freq = freq + 1;
                }
                max_freq = max(max_freq, freq + 1);
                if (freq_cnt.size() == 1) {
                    res = max(res, i + 1);
                } else if (freq_cnt.size() == 2) {
                    // if (max_freq - min_freq == 1 && (freq_cnt[min_freq] == 1 || freq_cnt[max_freq] == 1)) {
                    // 	res = max(res, i + 1);
                    // }
                    if (freq_cnt[min_freq] == 1 || (max_freq - min_freq == 1 && freq_cnt[max_freq] == 1)) {
                        // 删掉最小的数或者最大的数
                        res = max(res, i + 1);
                    }
                }
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

    auto res = obj->maxEqualFreq(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
