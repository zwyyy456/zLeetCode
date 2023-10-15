// Created by zwyyy456 at 2023/10/06 11:30
// leetgo: 1.3.8
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0] - fee;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][1] - prices[i] - fee);
                } else {
                    dp[i][j] = max(dp[i - 1][0] + prices[i], dp[i - 1][j]);
                }
            }
        }
        return dp[n - 1][1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> prices;
    LeetCodeIO::scan(cin, prices);
    int fee;
    LeetCodeIO::scan(cin, fee);

    Solution *obj = new Solution();
    auto res = obj->maxProfit(prices, fee);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
