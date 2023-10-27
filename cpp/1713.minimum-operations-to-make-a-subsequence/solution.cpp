// Created by zwyyy456 at 2023/10/20 10:11
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(int l, int r, vector<int> &lis, int target) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (lis[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int minOperations(vector<int> &target, vector<int> &arr) {
        // 等价于求 target 的子序列中是 arr 的子序列的最大长度
        // target 互不相同
        unordered_map<int, int> ump;
        for (int i = 0; i < target.size(); ++i) {
            ump[target[i]] = i;
        }
        vector<int> vec;
        for (int const i : arr) {
            if (ump.find(i) != ump.end()) {
                vec.push_back(i);
            }
        }
        // 开始 LIS 问题：
        if (vec.empty()) {
            return ump.size();
        }
        vector<int> lis(vec.size());
        int len = 1;
        lis.push_back(ump[vec[0]]);
        for (int i = 1; i < vec.size(); ++i) {
            int idx = bfind(0, len, lis, ump[vec[i]]);
            if (idx == len) {
                lis[len++] = ump[vec[i]];
            } else {
                lis[idx] = ump[vec[i]];
            }
        }
        return ump.size() - len;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> target;
    LeetCodeIO::scan(cin, target);
    vector<int> arr;
    LeetCodeIO::scan(cin, arr);

    Solution *obj = new Solution();
    auto res = obj->minOperations(target, arr);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
