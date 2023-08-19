// Created by zwyyy456 at 2023/07/28 11:48
// leetgo: 1.3.2
// https://leetcode.com/problems/parallel-courses-iii/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        // 先进行拓扑排序
        // 统计每个课程的先修课程数量
        vector<int> cnt(n + 1);
        vector<unordered_set<int>> next(n + 1);
        vector<unordered_set<int>> pre(n + 1);
        for (auto &vec : relations) {
            ++cnt[vec[1]];
            next[vec[0]].insert(vec[1]);
            pre[vec[1]].insert(vec[0]);
        }
        queue<int> zero;
        vector<int> res;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                zero.push(i);
                ans[i] = time[i - 1];
            }
        }
        int total = 0;
        while (!zero.empty()) {
            int idx = zero.front();
            res.push_back(idx);
            total = max(total, ans[idx]);
            zero.pop();
            for (int course : next[idx]) {
                if (--cnt[course] == 0) {
                    zero.push(course);
                    ans[course] = max(ans[course], ans[idx] + time[course - 1]);
                }
            }
        }
        return total;
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
    vector<int> time;
    LeetCodeIO::scan(cin, time);

    Solution *obj = new Solution();

    auto res = obj->minimumTime(n, relations, time);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
