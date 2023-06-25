// Created by zwyyy456 at 2023/06/16 16:19
// leetgo: 1.3.1
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Bfind(vector<vector<int>> &work, int target, int r) {
        int l = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (work[mid][1] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        // 排序，dp + 二分
        int n = startTime.size();
        vector<vector<int>> work(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            work[i][0] = startTime[i];
            work[i][1] = endTime[i];
            work[i][2] = profit[i];
        }
        auto cmp = [&work](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(work.begin(), work.end(), cmp);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k = Bfind(work, work[i - 1][0] + 1, i); // 找到第一个大于 work[i - 1][0] 的
            dp[i] = max(dp[i - 1], dp[k] + work[i - 1][2]);
        }
        return dp[n];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> startTime;
    LeetCodeIO::scan(cin, startTime);
    vector<int> endTime;
    LeetCodeIO::scan(cin, endTime);
    vector<int> profit;
    LeetCodeIO::scan(cin, profit);

    Solution *obj = new Solution();

    auto res = obj->jobScheduling(startTime, endTime, profit);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
