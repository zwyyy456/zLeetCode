// Created by zwyyy456 at 2023/10/30 09:54
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<vector<int>> &lis, int target, int r) {
        int l = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (lis[mid][1] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int findLongestChain(vector<vector<int>> &pairs) {
        // 最长递增子序列问题
        auto cmp = [](vector<int> &v1, vector<int> &v2) {
            return v1[1] < v2[1];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int idx = bfind(pairs, pairs[i - 1][0], i);
            dp[i] = max(dp[i - 1], dp[idx] + 1);
        }
        return dp[n];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> pairs;
    LeetCodeIO::scan(cin, pairs);

    Solution *obj = new Solution();
    auto res = obj->findLongestChain(pairs);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
