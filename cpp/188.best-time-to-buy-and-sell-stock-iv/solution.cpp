// Created by zwyyy456 at 2023/10/05 15:26
// leetgo: 1.3.8
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));
        for (int j = 1; j <= 2 * k; j++) {
            if (j % 2 == 1)
                dp[0][j] = -prices[0];
        }

        for (int i = 1; i <= prices.size(); i++) {
            for (int j = 1; j <= 2 * k; j++) {
                if (j % 2 == 1)
                    dp[i][j] = max(dp[i - 1][j - 1] - prices[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = max(dp[i - 1][j - 1] + prices[i - 1], dp[i - 1][j]);
            }
        }
        return dp[prices.size()][2 * k];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int k;
    LeetCodeIO::scan(cin, k);
    vector<int> prices;
    LeetCodeIO::scan(cin, prices);

    Solution *obj = new Solution();
    auto res = obj->maxProfit(k, prices);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
