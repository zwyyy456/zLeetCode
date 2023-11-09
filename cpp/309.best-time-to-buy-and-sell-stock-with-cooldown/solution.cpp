// Created by zwyyy456 at 2023/10/05 14:55
// leetgo: 1.3.8
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = dp[i - 1][1];
            dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
        }
        return max(max(dp[n - 1][1], dp[n - 1][2]), dp[n - 1][3]);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> prices;
    LeetCodeIO::scan(cin, prices);

    Solution *obj = new Solution();
    auto res = obj->maxProfit(prices);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
