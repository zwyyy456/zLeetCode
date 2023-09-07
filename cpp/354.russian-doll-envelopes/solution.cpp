// Created by zwyyy456 at 2023/08/19 15:33
// leetgo: 1.3.1
// https://leetcode.com/problems/russian-doll-envelopes/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<int> &dp, vector<vector<int>> &envelopes, int w, int h, int r) {
        int l = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int idx = dp[mid];
            if (envelopes[idx][0] < w && envelopes[idx][1] < h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end());
        //	最长递增子序列问题？
        int n = envelopes.size();
        map<int, int> recs;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            recs[envelopes[i][0]] = max(recs[envelopes[i][0]], i);
            ++cnt[envelopes[i][0]];
        }
        vector<int> dp(n + 1);
        dp[1] = 0;
        int len = 1;
        for (int i = 1; i < n; ++i) {
            if (envelopes[i][0] > envelopes[dp[len]][0] && envelopes[i][1] > envelopes[dp[len]][1]) {
                ++len;
                dp[len] = i;
            } else {
                int id = bfind(dp, envelopes, envelopes[i][0], envelopes[i][1], len);
                dp[id] = i;
            }
        }
        return len;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> envelopes;
    LeetCodeIO::scan(cin, envelopes);

    Solution *obj = new Solution();

    auto res = obj->maxEnvelopes(envelopes);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
