// Created by zwyyy456 at 2023/08/17 18:51
// leetgo: 1.3.5
// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    const int mod = 1e9 + 7;
    int dfs(int stx, int sty, int endx, int endy, int k, vector<vector<int>> &presum, int m, int n, vector<vector<vector<int>>> &cache) {
        if (k == 0) {
            return presum[endx + 1][endy + 1] - presum[endx + 1][sty] - presum[stx][endy + 1] + presum[stx][sty] > 0 ? 1 : 0;
        }
        int res = 0;
        if (cache[stx][sty][k] >= 0) {
            return cache[stx][sty][k];
        }
        for (int i = sty; i < endy; ++i) {
            // 竖着切
            // int res1 = dfs(stx, sty, endx, i, j, presum, m, n);
            int res2 = dfs(stx, i + 1, endx, endy, k - 1, presum, m, n, cache);
            // (stx, sty) (endx, i)
            if (presum[endx + 1][i + 1] - presum[endx + 1][sty] - presum[stx][i + 1] + presum[stx][sty] > 0 && res2 > 0) {
                res = (res + res2) % mod;
            }
        }
        for (int i = stx; i < endx; ++i) {
            // 水平切
            // int res1 = dfs(stx, sty, i, endy, j, presum, m, n);
            // stx, sty, i, endy
            int res2 = dfs(i + 1, sty, endx, endy, k - 1, presum, m, n, cache);
            if (presum[i + 1][endy + 1] - presum[i + 1][sty] - presum[stx][endy + 1] + presum[stx][sty] > 0 && res2 > 0) {
                res = (res + res2) % mod;
            }
        }
        cache[stx][sty][k] = res;
        return res;
    }
    int ways(vector<string> &pizza, int k) {
        // dfs + 二维前缀和
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> rowsum(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + (pizza[i][j - 1] == 'A' ? 1 : 0);
                // cout << i << " " << j << " " << rowsum[i][j] << endl;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                presum[i][j] = presum[i - 1][j] + rowsum[i - 1][j];
                cout << i << " " << j << " " << presum[i][j] << endl;
            }
        }
        vector<vector<vector<int>>> cache(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return dfs(0, 0, m - 1, n - 1, k - 1, presum, m, n, cache);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> pizza;
    LeetCodeIO::scan(cin, pizza);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->ways(pizza, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
