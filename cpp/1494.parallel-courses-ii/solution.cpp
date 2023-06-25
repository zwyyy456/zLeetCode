// Created by zwyyy456 at 2023/06/16 08:59
// leetgo: 1.3.1
// https://leetcode.com/problems/parallel-courses-ii/

#include <bits/stdc++.h>
#include <climits>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    static auto dfs(int to_study, vector<int> &cach, int full, vector<int> &pre, int n, int k) -> int {
        if (to_study == 0) {
            return 0;
        }
        if (cach[to_study] != -1) {
            return cach[to_study];
        }
        int studied = (to_study ^ full);
        int cnt = 0; // 统计可以学习的课程数
        int tmp = 0; // 本次递归要学习的课程
        for (int i = 0; i < n; ++i) {
            if ((((1 << i) & to_study) != 0) && (pre[i] & to_study) == 0) {
                // 说明 i 在 to_study 中 且 i 的先修课程已经学习过了（或者没有先修课程）
                tmp = (tmp | (1 << i));
                ++cnt;
            }
        }
        if (cnt <= k) {
            cach[to_study] = dfs(to_study ^ tmp, cach, full, pre, n, k) + 1;
            return cach[to_study];
        }
        int res = INT_MAX;
        for (int i = tmp; i != 0; i = (i - 1) & tmp) {
            if (__builtin_popcount(i) <= k) {
                res = min(res, dfs(to_study ^ i, cach, full, pre, n, k) + 1);
            }
        }
        cach[to_study] = res;
        return cach[to_study];
    }
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        // 合集 i 表示要修的课程
        // 合集 j 是 i 的子集，且 pre(j)（表示 j 的先修课程）与 i 没有交集，并且 size(j) <= k
        vector<int> pre(n);
        for (auto &vec : relations) {
            int x = vec[0] - 1, y = vec[1] - 1; // 下标选择从 0 到 n - 1
            pre[y] = (pre[y] | (1 << x));
        }
        int full = (1 << n) - 1; // 全集
        vector<int> cach(1 << n, -1);
        return dfs(full, cach, full, pre, n, k);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> relations;
    LeetCodeIO::scan(cin, relations);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->minNumberOfSemesters(n, relations, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
