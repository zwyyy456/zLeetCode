// Created by zwyyy456 at 2024/01/18 20:03
// leetgo: 1.3.8
// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(int target, vector<int> &beans) {
        int l = 0, r = beans.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (beans[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l; // 第一个大于等于 target 的 bean 的坐标
    }
    long long minimumRemoval(vector<int> &beans) {
        // 假设最后剩下的袋子中，每个豆子数量为 k，枚举这个豆子数量
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + beans[i - 1];
        }
        auto res = prefix[n];
        for (long num = 0; num <= beans[n - 1]; ++num) {
            int idx = bfind(num, beans);
            auto rm_beans = prefix[idx] + prefix[n] - (n - idx) * num - prefix[idx];
            res = min(res, rm_beans);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> beans;
    LeetCodeIO::scan(cin, beans);

    Solution *obj = new Solution();
    auto res = obj->minimumRemoval(beans);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
