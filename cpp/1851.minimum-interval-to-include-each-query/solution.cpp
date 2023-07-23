// Created by zwyyy456 at 2023/07/18 21:16
// leetgo: 1.3.2
// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
        sort(intervals.begin(), intervals.end());
        using pii = pair<int, int>;
        vector<pii> qrs;
        int m = intervals.size(), n = queries.size();
        for (int i = 0; i < n; ++i) {
            qrs.emplace_back(queries[i], i);
        }
        std::sort(qrs.begin(), qrs.end());
        vector<int> ans(n, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq; // pair.first => right - left + 1，pair.second => right
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            while (idx < m && intervals[idx][0] <= qrs[i].first) {
                pq.push({intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]});
                ++idx;
            }
            while (!pq.empty() && pq.top().second < qrs[i].first) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans[qrs[i].second] = pq.top().first;
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> intervals;
    LeetCodeIO::scan(cin, intervals);
    vector<int> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->minInterval(intervals, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
